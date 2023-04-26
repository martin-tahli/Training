
#include <stdio.h>
#include <unistd.h>
//#include<windows.h>   - Use for windows.
#include "Utilities.h"
#include "CheckInput.h"
#include "Defines.h"




char *StatusMsg(int heroStatus) {
    char *statusMsg;
    switch (heroStatus) {
        case DEAD:
            statusMsg = "Dead";
            break;

        case ALIVE:
            statusMsg = "Normal";
            break;

        default:
            printf(" ");
            break;
    }
    return statusMsg;
}


int chooseEnemy(Vector *team) {

    struct Hero **attackingHero;
    int attackingHeroStatus;
    int invalidChoice = 0;
    int userChoice;

    int teamSize = vectorGetSize(team);

    do {
        printf("\n\nPlease select an Enemy to attack by typing its number:\n");
        userChoice = validateIntegerInput(0, teamSize);

        attackingHero = vectorGet(team, userChoice);
        attackingHeroStatus = GetHeroStatus((*attackingHero));

            if ( attackingHeroStatus == DEAD) {
                printf("\nYou cannot select dead enemies!\n");
                continue; // Skipping this hero because it is stunned or slept or DEAD.
            }
            else {
                invalidChoice = 1;
            }
        }
    while(invalidChoice == 0);

    return userChoice;
}

int chooseAliveAlly(Vector *team) {
    int teamSize = vectorGetSize(team);
    int heroStatus = 0;
    int isAlive = 0;
    int userChoice = 0;

    printf("=========================================================\n");
    printf("\n\nPlease select an Ally to buff/heal by typing its number:\n");
    printTeam(team);

    do {
        userChoice = validateIntegerInput(0, teamSize);
        struct Hero **currTarget = vectorGet(team, userChoice);
        heroStatus = GetHeroStatus(*currTarget);

        if (heroStatus == ALIVE) {
            isAlive = true;
        }
        else {
            printf("\nYou can only target heroes that are alive!\n");
        }
    } while(isAlive == 0);

    return userChoice;
}

int chooseDeadAlly(Vector *team) {
    int teamSize = vectorGetSize(team);
    int heroStatus = 0;
    int isDead = 0;
    int userChoice = 0;

    printf("=========================================================\n");
    printf("\n\nPlease select an Ally to revive by typing its number:\n");
    printTeam(team);

    do {
        userChoice = validateIntegerInput(0, teamSize);
        struct Hero **currTarget = vectorGet(team, userChoice);
        heroStatus = GetHeroStatus(*currTarget);

        if (heroStatus == DEAD) {
            isDead = true;
        }
        else {
            printf("\nYou can only revive dead heroes!\n");
        }
    } while(isDead == 0);

    return userChoice;
}

void printTeam(Vector *team) {


    int defendingTeamSize = vectorGetSize(team);

    struct Hero **currentEnemyHero;

    for (int heroIndex = 0; heroIndex < defendingTeamSize; heroIndex++) {

        currentEnemyHero = vectorGet(team, heroIndex); //set current enemy hero data

        char *heroName = GetHeroName(*currentEnemyHero);
        int heroHP = GetHeroHealth(*currentEnemyHero);
        int heroArmor = GetHeroArmor(*currentEnemyHero);
        int heroStatus = GetHeroStatus(*currentEnemyHero);

        char *currentHeroStatus = StatusMsg(heroStatus);

        // print hero data to console
        printf("\n=========================\n");
        printf("\n- Hero  Position: %d \n"
               "- Status: %s \n"
               "- Name: %s \n"
               "- Health: %d  \n"
               "- Armor: %d \n",
               heroIndex, currentHeroStatus,
               heroName, heroHP, heroArmor);
        printf("\n=========================\n");
    }
}

void receiveDamage(struct Hero **attacker, struct Hero ** const receiver, const int damage) {


    int armor = GetHeroArmor(*receiver);
    int health = GetHeroHealth(*receiver);
    int receiverClassID = GetHeroClassID(*receiver);
    char *receiverName = GetHeroName(*receiver);
    char *receiverClass = getClassString(receiverClassID);


    int attackerClassID = GetHeroClassID(*attacker);
    char *attackerName = GetHeroName(*attacker);
    char *attackerClass = getClassString(attackerClassID);


    int damageToDo = damage - (damage * armor) / 100;  // damage after armor

    if (health <= damageToDo) {
        SetHeroHealth(receiver, 0);
        SetHeroStatus(receiver, DEAD);
        printf("\n\n%s %s killed %s %s!\n", attackerClass, attackerName,  receiverClass, receiverName);

    } else {
        SetHeroHealth(receiver, health - damageToDo);
        printf("\n\n%s %s dealt %d damage to %s %s!\n", attackerClass, attackerName, damageToDo, receiverName,
               receiverClass);
    }
    sleep(3);
}

char *getClassString(int classID) {
    switch (classID) {
        case DEATH_KNIGHT:
            return "Death Knight";

        case DRAW_RANGER:
            return "Draw Ranger";
        case ARCH_MAGE:
            return "Arch Mage";
        case PALADIN:
            return "Paladin";
        default:
            return "";

    }
}

bool checkTeamDead(Vector* teamToCheck){

    struct Hero ** currentHero;
    int teamSize = vectorGetSize(teamToCheck);
    int heroStatus;
    int deadCounter = 0;

    for (int heroIdx = 0 ;heroIdx < teamSize; heroIdx++) {
        currentHero = vectorGet(teamToCheck, heroIdx);
        heroStatus = GetHeroStatus(*currentHero);
        if (heroStatus == DEAD) {
            deadCounter++;
        }
    }

    if (deadCounter == teamSize) {
        return true;
    }
    else {
        return false;
    }
}
