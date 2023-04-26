#include "CheckInput.h"


/**
 * This function checks wether the first character of the input is '\\n', meaning the user tried to skip input
 * @param input the input string to be checked
 * @return 1 if input is empty and 0 if not.
 */
int checkIfInputIsEmpty(const string input) {
    // if input is just "Enter", meaning user tries to skip.
    if (input[0] == '\n') {
        printf("Please enter at least 1 character.\n");
        return 1;
    }
    return 0;
}

/**
 * This function checks input, parses it to int, and only accepts it if it is in the predefined range of\n
 * 0-2. Everything else is considered wrong input and is discarded.
 * @return integer converted from input
 */
int validateIntegerInput() {

    char input[500] = {};          //input buffer
    int temp;
    int converted_input = 0;

    int not_all_number;
    int emptyCondition;


    do {
        not_all_number = 0;

        // do while here for empty input
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

                if (temp < 0) {
                    printf("The number is too small, please enter a number between 0-2\n");
                    continue;
                } else if (temp > 2) {
                    printf("The number is too big, please enter a number between 0-2\n");
                    continue;
                } else {
                    converted_input = temp;
                    return converted_input;
                }
            }
                //This is if the input is anything other than numbers
            else {
                printf("Invalid input, please try again.\n");
            }
        } else {
            emptyCondition = 1;
        }

        //converted_input == 0   <-- old working condition
    } while (converted_input == 0 && emptyCondition);
    return TRUE;
}

/**
 * This function terminates the '\\n' symbol at the end of the input string.
 * @param input the string we wish to clear from \\n
 */
void terminateTrailingNewline(string input) {
    if (input[(strlen(input) - 1)] == '\n') {
        input[(strlen(input) - 1)] = '\0';
    }
}

/**
 * This function takes the input for each race and checks whether it is valid or not.
 * @param currentRaceArray the unit array we wish to check.
 * @param currentRaceID the ID of the current race.
 */
void takeRaceInput(char currentRaceArray[], int currentRaceID) {

    do {
        fflush(stdin);
        fgets(currentRaceArray, 50, stdin);

        //checking for empty lines
        if (checkIfInputIsEmpty(currentRaceArray)) {
            continue;
        }

        terminateTrailingNewline(currentRaceArray);
        if (!raceUnitInputCheck(currentRaceArray,currentRaceID)){
            puts("Invalid input please try again:\n");
            memset(currentRaceArray,0,sizeof(*currentRaceArray));
            continue;

        }
        return;
    } while (1);  // if input contains invalid chars this will loop until valid.
}

/**
 * This function checks the input against the units of the current race.
 * @param raceArray the array we wish to check.
 * @param currentRaceID the ID of the current race.
 * @return
 */
int raceUnitInputCheck(char raceArray[], int currentRaceID) {

    char valuesToBeCHecked[2] = {};

    switch (currentRaceID) {

        case TERRAN:
            valuesToBeCHecked[0] = 'v';
            valuesToBeCHecked[1] = 'b';
            break;

        case PROTOSS:
            valuesToBeCHecked[0] = 'p';
            valuesToBeCHecked[1] = 'c';
            break;

        case ZERG:
            valuesToBeCHecked[0] = 'm';
            valuesToBeCHecked[1] = 'b';
            break;

        default:
            exit(-1);
    }
    

    size_t size = strlen(raceArray);
    // checking every character if they are one of the race's units, if not we break with a false return.
    for (size_t i = 0; i < size; i++) {

        if (raceArray[i] == valuesToBeCHecked[0]  || raceArray[i] == valuesToBeCHecked[1]) {
            continue;
        }
        return FALSE;

    }
    return TRUE;
}
