#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SIZE 1024

int main()
{
        //create socket
        char* ip = "192.168.178.3";
        int port = 8080;

        int serversocket, clientsocket;
        struct sockaddr_in server_addr, client_addr;
        char buffer[SIZE];
        int n;

        serversocket = socket(AF_INET, SOCK_STREAM, 0);
        if(serversocket < 0)
        {
         perror("[ERROR!]socket cannot be created.");
         exit(1);
        }
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(ip);

        n = bind(serversocket, (struct sockaddr*) &server_addr, sizeof(server_addr));
        if(n < 0)
        {
         perror("[ERROR!]bind error.");
         exit(1);
        }
        printf("[SUCCESS!]bind to the port number: %d\n", port);

        if(listen(serversocket, 100) < 0)
        {
         perror("[ERROR!]listening failed.");
         exit(1);
        }
        printf("[SUCCESS!]listening...\n");

	  socklen_t client_len = sizeof(client_addr);
        clientsocket = accept(serversocket, (struct sockaddr *)&client_addr, &client_len>

        while(1)
        {
         clientsocket = accept(serversocket, (struct sockaddr*)&client_addr, &client_len>
         printf("Client connected.");

         bzero(buffer, 1024);
         recv(clientsocket, buffer, sizeof(buffer), 0);
         printf("Client: %s\n", buffer);

         bzero(buffer, 1024);
         strcpy(buffer, "HI, THIS IS THE SERVER. WELCOME!!");
         printf("Server: %s\n", buffer);
         send(clientsocket, buffer, strlen(buffer), 0);

         close(clientsocket);
         printf("Client disconnected.\n\n");
        }
        return 0;
}
