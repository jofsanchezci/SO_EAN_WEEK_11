
# Chat Cliente-Servidor en C

Este proyecto es una implementación básica de un chat utilizando sockets en C. El programa consiste en un servidor que acepta conexiones de un cliente. Una vez conectado, tanto el cliente como el servidor pueden enviarse mensajes entre sí. Esta implementación utiliza TCP/IP para la comunicación, lo que asegura una conexión confiable entre ambos.

## Requisitos

Para compilar y ejecutar este proyecto, necesitarás:

- Un sistema operativo compatible con compilación C (Linux, macOS, Windows con Cygwin o WSL).
- Un compilador C, como `gcc`.

## Estructura del proyecto

- `server.c`: Contiene el código del servidor, que espera y acepta conexiones de clientes.
- `client.c`: Contiene el código del cliente, que se conecta al servidor para iniciar la conversación.

## Funcionamiento

### Servidor

El servidor se encarga de:

1. **Crear un socket** para escuchar conexiones en un puerto específico.
2. **Vincularse** a una dirección IP y puerto (en este caso, el puerto 8080).
3. **Escuchar** conexiones entrantes de clientes.
4. **Aceptar** una conexión del cliente y permitir la comunicación.
5. **Enviar y recibir mensajes** del cliente hasta que este se desconecte.

### Cliente

El cliente se encarga de:

1. **Crear un socket** y conectarse al servidor utilizando la dirección IP y el puerto del servidor.
2. **Enviar y recibir mensajes** al servidor hasta que uno de los dos se desconecte.

## Instrucciones de compilación

### Compilar el servidor

Para compilar el servidor, ejecuta el siguiente comando:

```bash
gcc server.c -o server
```

### Compilar el cliente

Para compilar el cliente, ejecuta el siguiente comando:

```bash
gcc client.c -o client
```

## Instrucciones de ejecución

### Paso 1: Ejecutar el servidor

Primero, ejecuta el servidor en una terminal. Este comenzará a escuchar conexiones en el puerto 8080.

```bash
./server
```

El servidor mostrará un mensaje de que está esperando conexiones:

```
Servidor esperando conexiones...
```

### Paso 2: Ejecutar el cliente

En una segunda terminal, ejecuta el cliente, que intentará conectarse al servidor en la dirección `127.0.0.1` (localhost) y en el puerto 8080.

```bash
./client
```

El cliente recibirá un mensaje de bienvenida desde el servidor y permitirá que el usuario comience a enviar mensajes.

### Interacción

El cliente y el servidor pueden enviarse mensajes alternadamente. El flujo es el siguiente:

1. El cliente escribe un mensaje y lo envía al servidor.
2. El servidor muestra el mensaje recibido y responde.
3. El ciclo continúa hasta que alguno de los dos se desconecte.

### Ejemplo de flujo

**Servidor:**
```
Servidor esperando conexiones...
Mensaje de bienvenida enviado
Cliente: Hola servidor!
Servidor: Hola cliente!
```

**Cliente:**
```
Bienvenido al chat del servidor
Cliente: Hola servidor!
Servidor: Hola cliente!
```

## Notas importantes

- **IP y Puerto**: En esta implementación, el cliente se conecta al servidor en `127.0.0.1` (localhost) y el servidor escucha en el puerto 8080. Si quieres usar esta implementación en máquinas diferentes, deberás cambiar la dirección IP en el archivo `client.c` a la IP del servidor.
- **Desconexión**: Si el cliente o el servidor se desconecta, el programa terminará. Esta implementación no maneja múltiples clientes ni desconexiones seguras.
- **Mejoras posibles**: Puedes mejorar este chat añadiendo soporte para múltiples clientes con threads o select, o añadiendo cifrado para la seguridad de los mensajes.

## Contribuir

Si encuentras algún error o deseas mejorar la implementación, siéntete libre de hacer un fork y enviar un pull request.


