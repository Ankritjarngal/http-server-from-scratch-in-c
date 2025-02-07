#include <stdio.h>
#include <winsock2.h>
#include <string.h>

#define BUF_SIZE 5000

void get(char *path, char *store) {
    FILE *file = fopen("index.html", "w");
    if (file == NULL) {
        printf("Error writing to index.html\n");
        sprintf(store,
            "HTTP/1.0 500 Internal Server Error\r\n"
            "Server: webserver-c\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 58\r\n"
            "Connection: close\r\n\r\n"
            "<html><body><h1>500 Internal Server Error</h1></body></html>");
        return;
    }

    fprintf(file,
        "<!DOCTYPE html>\n"
        "<html lang=\"en\">\n"
        "<head>\n"
        "    <meta charset=\"UTF-8\">\n"
        "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
        "    <title>GET Request Log</title>\n"
        "    <style>\n"
        "        body { font-family: Arial, sans-serif; text-align: center; padding: 50px; background: #f0f0f0; }\n"
        "        .container { background: #fff; padding: 20px; box-shadow: 0px 0px 10px rgba(0,0,0,0.1); border-radius: 8px; }\n"
        "        h1 { color: #007bff; }\n"
        "    </style>\n"
        "</head>\n"
        "<body>\n"
        "    <div class=\"container\">\n"
        "        <h1>GET request received for: %s</h1>\n"
        "    </div>\n"
        "</body>\n"
        "</html>", path);

    fclose(file);

    char content[BUF_SIZE];
    sprintf(content, "<html><body><h1>GET request received for: %s</h1></body></html>", path);
    
    sprintf(store,
        "HTTP/1.0 200 OK\r\n"
        "Server: webserver-c\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n\r\n"
        "%s",
        strlen(content), content);
}

void post(char *body, char *store) {
    FILE *file = fopen("index.html", "w");
    if (file == NULL) {
        printf("Error writing to index.html\n");
        sprintf(store,
            "HTTP/1.0 500 Internal Server Error\r\n"
            "Server: webserver-c\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 58\r\n"
            "Connection: close\r\n\r\n"
            "<html><body><h1>500 Internal Server Error</h1></body></html>");
        return;
    }

    fprintf(file,
        "<!DOCTYPE html>\n"
        "<html lang=\"en\">\n"
        "<head>\n"
        "    <meta charset=\"UTF-8\">\n"
        "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
        "    <title>POST Request Log</title>\n"
        "    <style>\n"
        "        body { font-family: Arial, sans-serif; text-align: center; padding: 50px; background: #f0f0f0; }\n"
        "        .container { background: #fff; padding: 20px; box-shadow: 0px 0px 10px rgba(0,0,0,0.1); border-radius: 8px; }\n"
        "        h1 { color: #ff5733; }\n"
        "    </style>\n"
        "</head>\n"
        "<body>\n"
        "    <div class=\"container\">\n"
        "        <h1>POST request received with body:</h1>\n"
        "        <p>%s</p>\n"
        "    </div>\n"
        "</body>\n"
        "</html>", body);

    fclose(file);

    char content[BUF_SIZE];
    sprintf(content, "<html><body><h1>POST request received with body:</h1><p>%s</p></body></html>", body);
    
    sprintf(store,
        "HTTP/1.0 200 OK\r\n"
        "Server: webserver-c\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n\r\n"
        "%s",
        strlen(content), content);
}
void put(char *body, char *store) {
    FILE *file = fopen("index.html", "w");
    if (file == NULL) {
        printf("Error writing to index.html\n");
        sprintf(store,
            "HTTP/1.0 500 Internal Server Error\r\n"
            "Server: webserver-c\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 58\r\n"
            "Connection: close\r\n\r\n"
            "<html><body><h1>500 Internal Server Error</h1></body></html>");
        return;
    }

    fprintf(file,
        "<!DOCTYPE html>\n"
        "<html lang=\"en\">\n"
        "<head>\n"
        "    <meta charset=\"UTF-8\">\n"
        "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
        "    <title>POST Request Log</title>\n"
        "    <style>\n"
        "        body { font-family: Arial, sans-serif; text-align: center; padding: 50px; background: #f0f0f0; }\n"
        "        .container { background: #fff; padding: 20px; box-shadow: 0px 0px 10px rgba(0,0,0,0.1); border-radius: 8px; }\n"
        "        h1 { color:rgb(156, 9, 214); }\n"
        "    </style>\n"
        "</head>\n"
        "<body>\n"
        "    <div class=\"container\">\n"
        "        <h1>PUT request received with body:</h1>\n"
        "        <p>%s</p>\n"
        "    </div>\n"
        "</body>\n"
        "</html>", body);

    fclose(file);

    char content[BUF_SIZE];
    sprintf(content, "<html><body><h1>PUT request received with body:</h1><p>%s</p></body></html>", body);
    
    sprintf(store,
        "HTTP/1.0 200 OK\r\n"
        "Server: webserver-c\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n\r\n"
        "%s",
        strlen(content), content);
}
void delete(char *body, char *store) {
    FILE *file = fopen("index.html", "w");
    if (file == NULL) {
        printf("Error writing to index.html\n");
        sprintf(store,
            "HTTP/1.0 500 Internal Server Error\r\n"
            "Server: webserver-c\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: 58\r\n"
            "Connection: close\r\n\r\n"
            "<html><body><h1>500 Internal Server Error</h1></body></html>");
        return;
    }

    fprintf(file,
        "<!DOCTYPE html>\n"
        "<html lang=\"en\">\n"
        "<head>\n"
        "    <meta charset=\"UTF-8\">\n"
        "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
        "    <title>delete Request Log</title>\n"
        "    <style>\n"
        "        body { font-family: Arial, sans-serif; text-align: center; padding: 50px; background: #f0f0f0; }\n"
        "        .container { background: #fff; padding: 20px; box-shadow: 0px 0px 10px rgba(0,0,0,0.1); border-radius: 8px; }\n"
        "        h1 { color:rgb(16, 206, 51); }\n"
        "    </style>\n"
        "</head>\n"
        "<body>\n"
        "    <div class=\"container\">\n"
        "        <h1>delete request received with body:</h1>\n"
        "        <p>%s</p>\n"
        "    </div>\n"
        "</body>\n"
        "</html>", body);

    fclose(file);

    char content[BUF_SIZE];
    sprintf(content, "<html><body><h1>delete request received with body:</h1><p>%s</p></body></html>", body);
    
    sprintf(store,
        "HTTP/1.0 200 OK\r\n"
        "Server: webserver-c\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n\r\n"
        "%s",
        strlen(content), content);
}

int main() {
    WSADATA wsa;
    char buffer[BUF_SIZE];
    char resp[BUF_SIZE];

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

        char method[5], path[100];
        sscanf(buffer, "%s %s", method, path);
        

        if (strcmp(method, "GET") == 0) {
            get(path, resp);
        } else if (strcmp(method, "POST") == 0) {
            char *body = strstr(buffer, "\r\n\r\n");
            if (body != NULL) {
                char *end = body + strlen(body) - 1;
                while(end > body && (*end == '\n' || *end == '\r')) {
                    *end = '\0';
                    end--;
                }
                
            } else {
                printf("No body found\n");
                body = NULL;
            }
            post(body, resp);
        } 
        else if(strcmp(method,"PUT")==0){
            char *body = strstr(buffer,"\r\n\r\n");
            if (body != NULL) {
                body += 4;
               
                char *end = body + strlen(body) - 1;
                while(end > body && (*end == '\n' || *end == '\r')) {
                    *end = '\0';
                    end--;
                }
                printf("\nPUT Body: %s\n", body);
            } else {
                printf("No body found\n");
                body = NULL;
            }
            put(body, resp);
        }
        else if(strcmp(method,"DELETE")==0){
            char *body = strstr(buffer,"\r\n\r\n");
            if (body != NULL) {
                body += 4;
               
                char *end = body + strlen(body) - 1;
                while(end > body && (*end == '\n' || *end == '\r')) {
                    *end = '\0';
                    end--;
                }
                printf("\nDelete Body: %s\n", body);
            } else {
                printf("No body found\n");
                body = NULL;
            }
            delete(body, resp);
        }
            else {
            sprintf(resp,
                "HTTP/1.0 405 Method Not Allowed\r\n"
                "Server: webserver-c\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: 58\r\n"
                "Connection: close\r\n\r\n"
                "<html><body><h1>405 Method Not Allowed</h1></body></html>");
        }

        int valwrite = send(sockw, resp, strlen(resp), 0);
        if (valwrite == SOCKET_ERROR) {
            printf("Send failed: %d\n", WSAGetLastError());
            closesocket(sockw);
            continue;
        }

        shutdown(sockw, SD_BOTH);
        closesocket(sockw);
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}