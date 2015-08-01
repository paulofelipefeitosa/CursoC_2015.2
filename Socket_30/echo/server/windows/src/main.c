#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORT_NO 9090

#define MAX_SOCKETS 10

SOCKET create_socket(void);
int bind_socket(SOCKET* sockfd, int port, int timeout_recv);
int wait_connection(SOCKET* sockfd);
int do_processing(SOCKET* sockfd);
void disconnect_socket(SOCKET* sockfd);
void destroy_socket(SOCKET* sockfd);
int send_socket(SOCKET* sockfd, char* buffer, int to_send);
int recv_socket(SOCKET* sockfd, char* buffer, int to_read);
int keyboard_read(char* message, char* buffer, int to_read);

int main(int argc, char *argv[])
{
    SOCKET sockfd = create_socket();
	
    if (sockfd != INVALID_SOCKET)
    {
        if (bind_socket(&sockfd, PORT_NO, 100))
        {
            SOCKET sockets[MAX_SOCKETS] = {INVALID_SOCKET};
            int opened_sockets = 0;

            while (1)
            {
                int idx, max;
                if (opened_sockets < MAX_SOCKETS)
                {
                    SOCKET new_sockfd = wait_connection(&sockfd);

                    if (new_sockfd != INVALID_SOCKET)
                    {
                        sockets[opened_sockets++] = new_sockfd;
                    }
                    else if (WSAGetLastError() != WSAETIMEDOUT)
                    {
                        //perror("ERROR waiting");
                    }
                }

                for (idx = 0, max = opened_sockets; idx < max; idx++)
                {
                    if (sockets[idx] != INVALID_SOCKET)
                    {
                        if (!do_processing(&sockets[idx]))
                        {
                            if (WSAGetLastError() != WSAETIMEDOUT)
                            {
                                printf("Disconnecting...\n");
                                disconnect_socket(&sockets[idx]);
                                sockets[idx] = sockets[opened_sockets-1];
                                sockets[opened_sockets-1] = INVALID_SOCKET;
                                opened_sockets--;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            printf("ERROR binding\n");
        }

        disconnect_socket(&sockfd);
    }
    else
    {
        printf("ERROR opening socket\n");
    }

    destroy_socket(&sockfd);

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

int bind_socket(SOCKET* sockfd, int port, int timeout_recv)
{
    int result = 0;

    if (*sockfd != INVALID_SOCKET)
    {
        struct sockaddr_in serv_addr = {0};
        struct timeval tv = {0};
        
        tv.tv_usec = timeout_recv;//10

        //setsockopt(*sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv, sizeof(struct timeval));

        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(port);

        result = bind(*sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == 0;
    }

    return result;
}

int wait_connection(SOCKET* sockfd)
{
    SOCKET new_sockfd = INVALID_SOCKET;

    if (*sockfd != INVALID_SOCKET)
    {
        int clilen;
        struct sockaddr_in cli_addr;
		
        listen(*sockfd, MAX_SOCKETS);
        clilen = sizeof(cli_addr);
		FD_SET my_socket;
		FD_SET(*sockfd, &my_socket);
		struct timeval tv = {0};
		tv.tv_usec = 100;
		if(select(0, &my_socket, NULL, NULL, &tv) > 0)
		{
			new_sockfd = accept(*sockfd, NULL, NULL);// 
			if (new_sockfd != INVALID_SOCKET)
			{
				struct timeval tv = {0};
				tv.tv_usec = 100;
				//setsockopt(new_sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*) &tv, sizeof(struct timeval));

				printf("New connection incoming: %s:%d\n", inet_ntoa(cli_addr.sin_addr),
					ntohs(cli_addr.sin_port));
			}
		}
    }
    return new_sockfd;
}

int do_processing(SOCKET* sockfd)
{
    int result = 0;

    if (*sockfd != INVALID_SOCKET)
    {
        int read;
        char buffer[256] = {0};
		/* FD_SET my_socket;
		FD_SET(*sockfd, &my_socket);
		struct timeval tv = {0};
		tv.tv_usec = 100;
		if(select(0, &my_socket, NULL, NULL, &tv) == 0)
			return 0;
 */
        if ((read = recv_socket(sockfd, buffer, 255)) >= 0)
        {
            send_socket(sockfd, buffer, read);
            result = 1;
        }
    }

    return result;
}

void disconnect_socket(SOCKET* sockfd)
{
    if (*sockfd != INVALID_SOCKET)
    {
        closesocket(*sockfd);
    }
}

void destroy_socket(SOCKET* sockfd)
{
    WSACleanup();
}

int send_socket(SOCKET* sockfd, char* buffer, int to_send)
{
    int sent = 0;

    if ((*sockfd != INVALID_SOCKET) && buffer && (to_send > 0))
    {
        sent = send(*sockfd, buffer, to_send, 0); //write
    }

    return sent;
}

int recv_socket(SOCKET* sockfd, char* buffer, int to_read)
{
    int read = 0;
    if ((*sockfd != INVALID_SOCKET) && buffer && (to_read > 0))
    {
		FD_SET my_socket;
		FD_SET(*sockfd, &my_socket);
		struct timeval tv = {0};
		tv.tv_usec = 100;
		if(select(0, &my_socket, NULL, NULL, &tv) > 0)
		{
			read = recv(*sockfd, buffer, to_read, 0); //read
		}
    }
    return read;
}
