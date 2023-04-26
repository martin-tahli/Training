#include <stdlib.h>
#include <stdio.h>

#include "BattleProcessor.h"
#include "Defines.h"
#include "Utilities.h"


static void swapTeam(Vector **AttackingTeam, Vector **EnemyTeam){
    Vector *temp;
    temp = *AttackingTeam;
    *AttackingTeam = *EnemyTeam;
    *EnemyTeam = temp;
}

void Battle(Vector *AttackingTeam, Vector *EnemyTeam) {


    while (true) {

        int teamSize = vectorGetSize(AttackingTeam);

        // cycling through each attacking hero
        for (int heroIdx = 0; heroIdx < teamSize; heroIdx++) {
            if (teamSize == 0)
                return; // to do AttackingTeam ID.

            struct Hero **attackingHero = vectorGet(AttackingTeam, heroIdx);
            int attackingHeroStatus = GetHeroStatus((*attackingHero));


            if ( attackingHeroStatus == DEAD) {
                continue; // Skipping this hero because it is stunned or slept or DEAD.
            }
            if (checkTeamDead(EnemyTeam)) {
                //win logic
                printf("\nWinner Winner Chicken Dinner :D \n");
                exit(69);

            }
            void (*fPtrCurrHero)(struct Hero **, Vector *, Vector *) = GetFuncPtrAttack(*attackingHero);
            fPtrCurrHero(attackingHero, AttackingTeam, EnemyTeam);

            // checking if the enemy team was killed, if they are all dead this will return true and print msg

        }
        // Swapping the teams. Attacking team now is the previous defending team.
        swapTeam(&AttackingTeam, &EnemyTeam);

    }
}



