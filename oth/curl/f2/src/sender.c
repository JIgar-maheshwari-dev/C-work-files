#include"head.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send1() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *file_name = "send_file.txt";
    FILE *file;
    char buffer[BUFFER_SIZE] = {0};

    // Open file to send
    file = fopen(file_name, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(EXIT_FAILURE);
    }

    // Send file
    while (!feof(file)) {
        size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
        send(sock, buffer, bytesRead, 0);
    }
    fclose(file);
    printf("File sent successfully.\n");

    close(sock);
    return 0;
}

