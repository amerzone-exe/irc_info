#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>

#define SERVER_PORT 1800
#define	SOCKET int
#define MAXLINE	4096

int main(void)
{
	SOCKET				listenfd, connfd, n;
	struct sockaddr_in	servaddr;
	char				buff[MAXLINE+1];
	uint8_t				recvline[MAXLINE+1];

	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		std::cout << "Socket error" << std::endl;
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family			= AF_INET;
	servaddr.sin_addr.s_addr	= htonl(INADDR_ANY);
	servaddr.sin_port			= htons(SERVER_PORT);

	int opt = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	if ((bind (listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr))) < 0)
		std::cout << "Bind error" << std::endl;

	if (listen(listenfd, 5) < 0)
		std::cout << "Listen error" << std::endl;

	std::cout << "Waiting for a connection on port " << SERVER_PORT << std::endl;
	
	for ( ; ; )
	{
		struct sockaddr_in	client_addr;
		socklen_t 			addr_len = sizeof(client_addr);
		SOCKET				client;
		std::string			message;

		client = accept(listenfd, (struct sockaddr *) NULL, NULL);
		if (client < 0)
			std::cout << "accept error" << std::endl;

		std::cout << "Client connected" << std::endl;

		for ( ; ; )
		{
			int bytes = recv(client, buff, sizeof(buff) - 1, 0);
			if (bytes <= 0)
			{
				if (bytes == 0)
					std::cout << "client deconnected" << std::endl;
				else
					std::cout << "recv error" << std::endl;
				break;
			}
			buff[bytes] = '\0';
			message += buff;

            size_t pos;
            while ((pos = message.find('\n')) != std::string::npos) 
			{
                std::string line = message.substr(0, pos);
                message.erase(0, pos + 1);
                
                std::cout << "Reçu: " << line << std::endl;
			}
		}
	}
}
