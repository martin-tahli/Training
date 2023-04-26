#ifndef BATTLEFIELD_H_
#define BATTLEFIELD_H_

#include "Player.h"

typedef struct {
  Player *players[PLAYERS_COUNT];
} BattleField;

/**
 * This function takes user input and generates the players according to it.
 * @param bf the battlefield
 */
void createPlayers(BattleField* bf);

/**
 * This function starts the battle.
 * @param bf the battlefield
 */
void startBattle(BattleField* bf);

/**
 * This function prints a pretty intro message.
 */
void printIntroMsg();

/**
 * This function clears the dynamically allocated memory.
 * @param battleField the battlefield that needs to be cleared.
 */
void deinit(BattleField *battleField);

#endif /* BATTLEFIELD_H_ */
