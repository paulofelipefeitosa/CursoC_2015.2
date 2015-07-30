#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define IP_ADDR "192.168.150.28"
#define PORT_NO 666

SOCKET create_socket(void);
int connect_socket(SOCKET* sock, char* ip, int port, int timeout_recv);
void disconnect_socket(SOCKET* sock);
void destroy_socket(SOCKET* sock);
int send_socket(SOCKET* sock, char* buffer, int to_send);
int recv_socket(SOCKET* sock, char* buffer, int to_read);
int keyboard_read(char* message, char* buffer, int to_read);

int main(int argc, char *argv[])
{
    SOCKET sock = create_socket();
    if (sock != INVALID_SOCKET)
    {
        if (connect_socket(&sock, IP_ADDR, PORT_NO, 10))
        {
			char header[2] = {0x01, 0x00};
            char buffer[256] = {0};
            int n, op;
			printf("Informe a Operacao: ");
			scanf("%d", &op);
			getchar();
			if(op == 1)
			{
				keyboard_read("Please enter the message: ", buffer, 255);
				header[0] = 0x01;
				header[1] = strlen(buffer)-1;
				n = send_socket(&sock, header, 2);
				n = send_socket(&sock, buffer, strlen(buffer));
				if (n >= 0)
				{
					memset((void*) buffer, 0, 256);
					n = recv_socket(&sock, buffer, 256);

					if (n >= 0)
					{
						printf("%s\n", buffer);
					}
					else
					{
						perror("ERROR reading from socket");
					}
				}
				else
				{
					perror("ERROR writing to socket");
				}
			}
			else if(op==2)
			{
				keyboard_read("Please enter the message: ", buffer, 255);
				header[0] = 0x02;
				header[1] = strlen(buffer)-1;
				n = send_socket(&sock, header, 2);
				n = send_socket(&sock, buffer, strlen(buffer));
				if (n >= 0)
				{
					memset((void*) buffer, 0, 256);
					n = recv_socket(&sock, buffer, 256);

					if (n >= 0)
					{
						printf("%s\n", buffer);
					}
					else
					{
						perror("ERROR reading from socket");
					}
				}
				else
				{
					perror("ERROR writing to socket");
				}
			}
			else if(op == 3)
			{
				header[0] = 0x03;
				header[1] = 0x00;
				n = send_socket(&sock, header, 1);
				if (n >= 0)
				{
					memset((void*) buffer, 0, 256);
					n = recv_socket(&sock, buffer, 1);
					printf("%d\n", strlen(buffer));
					if (n >= 0)
					{
						printf("%d\n", (int)buffer[0]-'0');
					}
					else
					{
						perror("ERROR reading from socket");
					}
				}
				else
				{
					perror("ERROR writing to socket");
				}
			}
			else if(op==4)
			{
				header[0] = 0x03;
				n = send_socket(&sock, header, 1);
				n = recv_socket(&sock, buffer, 1);
				printf("Voce deseja Ligar ou Desligar? 1-S/0-N: ");
				scanf("%d", &op);
				header[0] = 0x04;
				if(op)
				{
					printf("Voce Ligar qual LED? {1, 2, 3, 4, 5, 6}: ");
					scanf("%d", &op);
					buffer[0]=buffer[0]-'0';
					buffer[0] |= (1 << (op-1));
					header[1] = buffer[0];
					n = send_socket(&sock, header, 2);
				}
				else
				{
					printf("Voce Desligar qual LED? {1, 2, 3, 4, 5, 6}: ");
					scanf("%d", &op);
					buffer[0]=buffer[0]-'0';
					buffer[0] &= ~(1 << (op-1));
					header[1] = buffer[0];
					n = send_socket(&sock, header, 2);
				}
			}
        }
        else
        {
            perror("ERROR connecting");
        }
        disconnect_socket(&sock);
    }
    else
    {
        perror("ERROR opening socket");
    }

    destroy_socket(&sock);

    return 0;
}

SOCKET create_socket(void)
{
    SOCKET sock = INVALID_SOCKET;
    WSADATA wsaData = {0};

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) == 0)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    return sock;
}

int connect_socket(SOCKET* sock, char* ip, int port, int timeout_recv)
{
    int result = 0;
    if (sock && ip)
    {
        struct sockaddr_in serv_addr = {0};
        struct timeval tv = {0};
		
        tv.tv_sec = timeout_recv;
        setsockopt(*sock, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv, sizeof(struct timeval));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr(ip);
        serv_addr.sin_port = htons(port);
        result = (connect(*sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) >= 0);
    }

    return result;
}

void disconnect_socket(SOCKET* sock)
{
    if (sock)
    {
        closesocket(*sock);
    }
}

void destroy_socket(SOCKET* sock)
{
    WSACleanup();
}

int send_socket(SOCKET* sock, char* buffer, int to_send)
{
    int sent = 0;

    if (sock && buffer && (to_send > 0))
    {
        sent = send(*sock, buffer, to_send, 0);
    }

    return sent;
}

int recv_socket(SOCKET* sock, char* buffer, int to_read)
{
    int read = 0;

    if (sock && buffer && (to_read > 0))
    {
        read = recv(*sock, buffer, to_read, 0);
    }

    return read;
}

int keyboard_read(char* message, char* buffer, int to_read)
{
    int read = 0;

    if (message && buffer && (to_read > 0))
    {
        printf(message);

        if (fgets(buffer, to_read, stdin))
        {
            read = to_read;
        }
    }

    return read;
}
