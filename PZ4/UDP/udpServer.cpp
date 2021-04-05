#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

char* getCMD(){
    int port = 1234;
    int sockfd;
    struct sockaddr_in si_me, si_other;
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&si_me, '\0', sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(port);
    si_me.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr*)&si_me, sizeof(si_me));
    addr_size = sizeof(si_other);
    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)& si_other, &addr_size);
    printf("[+]Data Received: %s\n", buffer);

    char* charPointer = buffer;
    close(sockfd);
    return charPointer;
}

int main(int argc, char **argv){
    std::string CMD;
    do {
        CMD = getCMD();
        if (CMD == "fly") std::cout << "break for fly"<< std::endl;
        if (CMD == "eat") std::cout << "break for eat"<< std::endl;
    }while (CMD != "exit");

}
