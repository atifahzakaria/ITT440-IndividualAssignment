#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SIZE 1024

int main()
{
        //create client socket
        char *ip = "192.168.178.4";
        int port = 8080;

        int sock;
        struct sockaddr_in addr;
        socklen_t address_size;
        char buffer[SIZE];
        int n;

        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0)
        {
         perror("[ERROR!]error finding socket\n");
         exit(1);
        }
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip);

        //Connect to remote server
        if (connect(sock, (struct sockaddr *)&addr , sizeof(addr)) < 0)
        {
         perror("[ERROR!]connect failed\n");
         exit(1);
        }
        printf("[SUCCESS!]connected\n");

        return 0;
}
