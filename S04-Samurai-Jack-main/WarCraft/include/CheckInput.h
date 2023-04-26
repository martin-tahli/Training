#ifndef S04_SAMURAI_JACK_CHECKINPUT_H
#define S04_SAMURAI_JACK_CHECKINPUT_H

#include "ClassHero.h"

/**
 * This function takes the hero class and calls the appropriate setter.
 * @param self current hero
 * @param selfClass the class id of the hero
 */
void HeroClassSetter(struct Hero *self, int selfClassID);

/**
 * This function checks input, parses it to int, and only accepts it if it is in the predefined range of\n
 * min-max. Everything else is considered wrong input and is discarded.
 * @return integer converted from input
 */
int validateIntegerInput(int min, int max);


/**
 * This function terminates the '\\n' symbol at the end of the input string.
 * @param input the string we wish to clear from \\n
 */
void terminateTrailingNewline(char *input);


/**
 * This function checks whether the first character of the input is '\\n', meaning the user tried to skip input
 * @param input the input string to be checked
 * @return 1 if input is empty and 0 if not.
 */
int checkIfInputIsEmpty(const char *input);

/**
 * This function asks for team size.
 * @return the team size.
 */
int AskForTeamSize();

/**
 * This function prints the initial welcoming hello message.
 */
void PrintHelloMessage();

#endif //S04_SAMURAI_JACK_CHECKINPUT_H
