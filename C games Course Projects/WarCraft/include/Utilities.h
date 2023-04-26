#ifndef S04_SAMURAI_JACK_UTILITIES_H
#define S04_SAMURAI_JACK_UTILITIES_H

#include <stdbool.h>

#include "Vector.h"
#include "ClassHero.h"

/**
 * picks a target using a vector
 * @param team
 * @return id of the chosen target
 */
int chooseEnemy(Vector *team);


/**
 * Printing all heroes from given team.
 * @param team Can be both teams Attacking Team or Enemy Team.
 */
void printTeam(Vector *team);


/**
 * Used when Supporter revive Hero, choosing dead Hero by user input and revive it.
 * @param team Refers to current hero own team.
 * @return
 */
int chooseDeadAlly(Vector *team);


/**
 * Used when Supporter buff or heal Hero, choosing hero by user input and heals or buffs the target.
 * @param team Refers to current hero own team.
 * @return
 */
int chooseAliveAlly(Vector *team);

/**
 * This fucntion calculates and processes the received damage.
 * @param attacker the attacking hero pointer.
 * @param receiver the receiving hero pointer.
 * @param damage the damage in int form.
 */
void receiveDamage(struct Hero **attacker, struct Hero **receiver, int damage);

/**
 * This function returns the class string according to the class ID.
 * @param classID the class ID of the hero.
 * @return the string of the class.
 */
char *getClassString(int classID);

bool checkTeamDead(Vector *teamToCheck);


#endif //S04_SAMURAI_JACK_UTILITIES_H
