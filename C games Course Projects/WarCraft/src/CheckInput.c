
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#include "CheckInput.h"
#include "Defines.h"




void PrintHelloMessage() {
    printf("\n");
    printf("\tHello and welcome to our mini copy of the Warcraft game!\n"
           "\tIn this game we have two teams of heroes fighting each other until\n"
           "\tone of the teams meets their demise.\n"
           "\tLet's first start by getting a team size from you.\n");
    printf("\n");
}

int AskForTeamSize() {
    printf("\nPlease enter a number between 1-%d for team size:\n", MAX_TEAM_SIZE);

    int teamSize = validateIntegerInput(0,MAX_TEAM_SIZE);
    return teamSize;
}

int checkIfInputIsEmpty(const char* input) {
    // if input is just "Enter", meaning user tries to skip.
    if (input[0] == '\n') {
        printf("\nPlease enter at least 1 character.\n");
        return 1;
    }
    return 0;
}

int validateIntegerInput(int min, int max) {

    char input[500] = {};          //input buffer
    int temp;
    int converted_input = 0;

    int not_all_number;
    int emptyCondition;


    do {
        not_all_number = 0;

        // do while here for empty input
        fflush(stdin);
        fgets(input, sizeof(input), stdin);
        terminateTrailingNewline(input);

        if (!checkIfInputIsEmpty(input)) {
            size_t size = strlen(input) - 1;
            // this checks every character from input to see if it is a number or not, it breaks on first non-number occurrence.
            for (size_t i = 0; i < size; i++) {

                if (isdigit(input[i]) == 0) {
                    not_all_number = 1;
                    break;
                }
            }

            //this only triggers if everything from the input is a number, converts the string numbers into integers and compares it for size
            if (not_all_number == 0) {
                temp = atoi(input);

                if (temp < min) {
                    printf("\nThe number is too small, please enter a number between 0-2\n");
                    continue;
                } else if (temp > max) {
                    printf("\nThe number is too big, please enter a number between 0-2\n");
                    continue;
                } else {
                    converted_input = temp;
                    return converted_input;
                }
            }
                //This is if the input is anything other than numbers
            else {
                printf("\nInvalid input, please try again.\n");
            }
        } else {
            emptyCondition = 1;
        }

        //converted_input == 0   <-- old working condition
    } while (converted_input == 0 && emptyCondition);
    return true;
}

void terminateTrailingNewline(char* input) {
    if (input[(strlen(input) - 1)] == '\n') {
        input[(strlen(input) - 1)] = '\0';
    }
}