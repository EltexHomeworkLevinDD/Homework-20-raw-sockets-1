#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define BUFFER_SIZE 65536

int main() {
    int sockfd;
    unsigned char buffer[BUFFER_SIZE];
    struct sockaddr_in saddr;
    socklen_t saddr_len = sizeof(saddr);

    // Создание raw-сокета для UDP, получение только входящего трафика
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("Listening for UDP packets...\n");

    // Бесконечный цикл для получения пакетов
    while (1) {
        // Блокирующее получение пакета
        int num_bytes = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&saddr, &saddr_len);
        if (num_bytes < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        printf("Received UDP packet\n");
    }

    close(sockfd);

    return 0;
}
