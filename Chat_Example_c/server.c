
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};
    char *welcome_message = "Bienvenido al chat del servidor\n";
    
    // Crear el socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }

    // Configuración del servidor
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Asignar el socket a la dirección y puerto
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Error en el bind");
        exit(EXIT_FAILURE);
    }

    // Escuchar conexiones entrantes
    if (listen(server_fd, 3) < 0) {
        perror("Error en el listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Servidor esperando conexiones...\n");

    // Aceptar una conexión entrante
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Error en el accept");
        exit(EXIT_FAILURE);
    }

    // Enviar mensaje de bienvenida al cliente
    send(new_socket, welcome_message, strlen(welcome_message), 0);
    printf("Mensaje de bienvenida enviado\n");

    // Bucle de comunicación
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int valread = read(new_socket, buffer, BUF_SIZE);
        if (valread <= 0) {
            printf("Cliente desconectado\n");
            break;
        }

        printf("Cliente: %s", buffer);
        
        printf("Servidor: ");
        fgets(buffer, BUF_SIZE, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
