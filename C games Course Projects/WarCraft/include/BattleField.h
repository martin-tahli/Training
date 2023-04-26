#ifndef S04_SAMURAI_JACK_BATTLEFIELD_H
#define S04_SAMURAI_JACK_BATTLEFIELD_H

#include "Vector.h"

typedef struct {
    Vector Team1;
    Vector Team2;

} BattleField;


/**
 * This function frees the dynamically allocated memory for the battlefield.
 * @param battleField the battlefield to free.
 */
void deinit(BattleField *battleField);


/**
 * This function fills the teams
 * @param currentTeam the team to fill
 * @param teamSize the size of the team
 */
void fillTeam(Vector *currentTeam,  int teamSize);

#endif //S04_SAMURAI_JACK_BATTLEFIELD_H
