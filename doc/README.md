# SC2 - Simple C Server Client

## Demo
In this simple example, server opens a socket and bind it with a port number (i.e 8888). Then multiple clients can connect to that server and send two integers (i.e 600 900). Server takes the input, tokenize and returns to clients the results of sum, subtraction of that two integer blah blah...
- Build the project and move to bin directory
```bash
# In the current directory of project
make
make test
cd bin/test
```
- Run the server
```bash
# In bin/test directory
./server 8888
```
- Run client (or clients)
```bash
# In bin/test directory
./client localhost 8888
600 900
```
Clients then will receive the arithmetic calculations for those integers (600 and 900)
## API
### int tcp_sock_init() 
    - Creates an unbound socket
    - Returns: socket file descriptor (sockfd)
    
### int tcp_sock_serv(int portno)
    -  a server's socket with a port number.
    - Params: port number
    - Returns: socket file descriptor (sockfd)

### int tcp_sock_accept(int serv_sockfd)
    - stablishes a client socket that connect to server.
    - Params: file descriptor of server's socket.
    - Returns: file descriptor of client's socket.
    
### void tcp_sock_connect(int sockfd, char* hostname, int portno)
    - Connect the socket to server
    - Params: socket's file descriptor, hostname, port number
