#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int socket_desc, new_socket, c;
	struct sockaddr_in server, client;
	char *message;

	// create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc < 0) {
		puts("Could not create socket");
		return 1;
	}

	// prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	// bind
	if (bind(socket_desc, (struct sockaddr*)&server, sizeof(server)) < 0) {
		puts("bind failed");
		return 1;
	}

	// listen
	listen(socket_desc, 5);

	// accept and incoming connection
	puts("waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	while ((new_socket = accept(socket_desc, (struct sockaddr*)&client, (socklen_t*)&c))) {
		puts("connection accepted");

		// reply to the client
		message = "hello client, i have received your connection. but i have to go now. bye";
		write(new_socket, message, strlen(message));
	}

	if (new_socket < 0) {
		perror("accept failed");
		return 1;
	}
}