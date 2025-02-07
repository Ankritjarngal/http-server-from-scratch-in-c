#include <stdio.h>
#include <winsock2.h>
#define BUF_SIZE 1024

int main() {
    WSADATA wsa;
    char buffer[BUF_SIZE];
    char resp[] = "HTTP/1.0 200 OK\r\n"
                  "Server: webserver-c\r\n"
                  "Content-type: text/html\r\n\r\n"
                  "<html>hello, world</html>\r\n";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Winsock initialization failed: %d\n", WSAGetLastError());
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        printf("Socket creation failed: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    struct sockaddr_in hostAddr;
    hostAddr.sin_family = AF_INET;
    hostAddr.sin_port = htons(8080);
    hostAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&hostAddr, sizeof(hostAddr)) == SOCKET_ERROR) {
        printf("Bind failed: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    printf("Socket created and bound successfully\n");
    if (listen(sockfd, 100) == SOCKET_ERROR) {
        printf("Listen failed: %d\n", WSAGetLastError());
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }
    printf("Server is listening on port 8080\n");
    while (1) {
        struct sockaddr_in clientAddr;
        int lenClientAddr = sizeof(clientAddr);
        
        int sockw = accept(sockfd, (struct sockaddr*)&clientAddr, &lenClientAddr);
        if (sockw == INVALID_SOCKET) {
            printf("Accept failed: %d\n", WSAGetLastError());
            continue;
        }
        printf("Connection accepted\n");
        int valread = recv(sockw, buffer, BUF_SIZE, 0);
        if (valread == SOCKET_ERROR) {
            printf("Receive failed: %d\n", WSAGetLastError());
            closesocket(sockw);
            continue;
        }
        printf("Received: %s\n", buffer);
        int valwrite = send(sockw, resp, strlen(resp), 0);
        if (valwrite == SOCKET_ERROR) {
            printf("Send failed: %d\n", WSAGetLastError());
            closesocket(sockw);
            continue;
        }
        shutdown(sockw,SD_BOTH);
        closesocket(sockw);
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}
