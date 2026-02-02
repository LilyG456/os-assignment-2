/*
 * main.c
 * @author Lily Gustafson
 */
#include <stdio.h>
#include <string.h>
#include "stats.h"
#include "menu.h"

#define MAX_INPUT_LEN 128	/** maximum allowed input length */

/**
 * @brief Main function
 */
int main(int argc, char *argv[]) {
    wordstats_t stats = {0};
    char input[MAX_INPUT_LEN];

    printf("Enter strings (# to stop):\n");

    while (1) {

        //string input
        while (1) {
            if (fgets(input, MAX_INPUT_LEN, stdin) == NULL) {
                printf("Exiting...\n");
                return 0;
            }

            if (strcmp(input, "#\n") == 0) {
                break;
            }

            updateStats(&stats, input);
        }

        // menu
        int menu = 1;
        while (menu) {
            printMenu();

            char arr[8];
            if (fgets(arr, sizeof(arr), stdin) == NULL) {
                printf("Exiting...\n");
                return 0;
            }

            if (arr[1] != '\n' || arr[0] < '1' || arr[0] > '4') {
                printf("Invalid option %s", arr);
                printf("Exiting...\n");
                return 0;
            }

            int option = arr[0] - '0';

            switch (option) {
                case 1:
                    printStats(&stats);
                    break;

                case 2:
                    printHistogram(&stats);
                    break;

                case 3:
                    printf("Enter strings (# to stop):\n");
                    menu = 0;
                    break;

                case 4:
                    printf("Exiting...\n");
                    return 0;
            }
        }
    }
}