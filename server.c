#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in address = {
    AF_INET,
    htons(9090),
    0
  };

  bind(sockfd, &address, sizeof(address));

  listen(sockfd, 5);

  int clientfd = accept(sockfd, 0, 0);

  char buffer[2048];

  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer);
}
