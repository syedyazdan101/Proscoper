#include <stdio.h>
#include <stdlib.h>
#include "process_list.h"
#include "memory_usage.h"
#include "process_termination.h"

void display_menu() {
    printf("=================================\n");
    printf("       System Monitor Tool       \n");
    printf("=================================\n");
    printf("1. List all processes\n");
    printf("2. Check memory usage of a process\n");
    printf("3. Terminate a process\n");
    printf("4. Exit\n");
    printf("=================================\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    DWORD processID; 

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // List all processes
                printf("\nListing all processes:\n");
                list_processes();
                break;

            case 2:
                // Check memory usage of a specific process
                 
               printf("Enter Process ID to check memory usage: ");
               scanf("%lu", &processID);
               get_memory_usage(processID);
               break;

            case 3:
                // Terminate a specific process
                printf("\nEnter Process ID to terminate: ");
                scanf("%1lu", &processID);
                terminate_process(processID);
                break;

            case 4:
                // Exit the program
                printf("\nExiting System Monitor. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

        printf("\nPress Enter to continue...");
        getchar(); // Consume newline character left in the buffer
        getchar(); // Wait for user input
    }

    return 0;
}
