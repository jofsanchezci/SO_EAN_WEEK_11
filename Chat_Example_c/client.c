#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE] = {0};

    // Crear el socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Error al crear el socket \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convertir la dirección IP del servidor a binario y asignarla
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\n Dirección inválida o no soportada \n");
        return -1;
    }

    // Conectar al servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Error en la conexión \n");
        return -1;
    }

    // Leer el mensaje de bienvenida del servidor
    read(sock, buffer, BUF_SIZE);
    printf("%s", buffer);

    // Bucle de comunicación
    while (1) {
        printf("Cliente: ");
        fgets(buffer, BUF_SIZE, stdin);
        send(sock, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUF_SIZE);
        int valread = read(sock, buffer, BUF_SIZE);
        if (valread <= 0) {
            printf("Servidor desconectado\n");
            break;
        }

        printf("Servidor: %s", buffer);
    }

    close(sock);
    return 0;
}
