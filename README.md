# minitalk
This is a simple client-server communication program implemented in C, where the communication between the client and server is achieved solely through UNIX signals. The server must be started first, followed by the client. The server will print its process ID (PID) upon launch.

Project Structure
The project consists of two executable files:

client: The client program responsible for sending messages to the server.
server: The server program responsible for receiving and displaying messages from clients.
Additionally, the project includes a Makefile for compiling the source files. The Makefile ensures that the source files are compiled without relinking.

Dependencies
The following dependencies are used in the project:

libft: A custom library containing various utility functions.

Mandatory Part:

Server
Upon launch, the server prints its PID.
It listens for incoming messages from clients.
The server receives messages from clients and prints them promptly.
It is designed to handle multiple client messages without needing to restart.
Communication between the client and server is accomplished using only the signals SIGUSR1 and SIGUSR2.

Client
Takes two parameters:
The PID of the server.
The string to send to the server.
Sends the provided string to the server using signals.
Handles errors thoroughly and ensures the server acknowledges every received message.

Bonus Part
Acknowledgement
The server acknowledges every message received by sending back a signal to the client.
Unicode Support
Unicode character support is not implemented in the current version of the program.
