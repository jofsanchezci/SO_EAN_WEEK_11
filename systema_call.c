#include <fcntl.h>   // Para open()
#include <unistd.h>  // Para read(), write() y close()
#include <stdio.h>   // Para printf()
#include <stdlib.h>  // Para exit()

#define BUF_SIZE 1024

int main() {
    int fd;                  // Descriptor de archivo
    ssize_t bytes_read;       // Número de bytes leídos
    char buffer[BUF_SIZE];    // Buffer para almacenar los datos leídos

    // Abrir el archivo con permisos de solo lectura
    fd = open("archivo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    // Leer el contenido del archivo y mostrarlo en la consola
    while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
            perror("Error al escribir en la salida estándar");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error al leer el archivo");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Cerrar el archivo
    if (close(fd) == -1) {
        perror("Error al cerrar el archivo");
        exit(EXIT_FAILURE);
    }

    return 0;
}
