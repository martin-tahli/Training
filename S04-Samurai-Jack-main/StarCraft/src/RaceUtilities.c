#include "RaceUtilities.h"


/**
 * This function prints information for each individual race.
 * @param currentRaceID the race ID which will get printed.
 */
void printCurrentRaceUnits(int currentRaceID) {
    //string stringToPrint;

    switch(currentRaceID) {
        case TERRAN:
            printf("The available units for the Terran race are:\nv - Viking (Health: %d, Damage: %d)\n  "
                            "Special ability: The Viking deals x2 damage to the Phoenix unit from the Protoss race.\n\n"
                            "b - Battle Cruiser (Health %d, Damage %d)\n  "
                            "Special ability: The Battle Cruiser has a super powerful attack, every 5th round it fires"
                            "its Yamato cannon, which allows it to deal 5 times normal damage!\n",
            VIKING_HEALTH, VIKING_DAMAGE, BATTLE_CRUSER_HEALTH, BATTLE_CRUSER_DAMAGE);
            break;
        case PROTOSS:
            printf("The available units for the Protoss race are:\np - Phoenix (Health: %d, Shield: %d, Damage: %d)\n  "
                            "Special ability: The Phoenix can regenate its shield every round by %d.\n\n"
                            "c- Carrier (Health: %d, Shield: %d, Damage: %d)\n  "
                            "Special ability 1: If the Carrier is at full health, it attacks with 8 interceptor drones, each dealing %d damage.\n    "
                            "If the Carrier's health drops, it attacks with 4 interceptors only.\n  "
                            "Special ability 2: The Carrier regenerates %d of its shield after every turn.\n",
            PHOENIX_HEALTH, PHOENIX_SHIELD,PHOENIX_DAMAGE, PHOENIX_SHIELD_REGENERATE_RATE, CARRIER_HEALTH,
            CARRIER_SHIELD, CARRIER_DAMAGE, CARRIER_DAMAGE, CARRIER_SHIELD_REGENERATE_RATE);
            break;
        case ZERG:
            printf("The available units for the Zerg race are:\nm - Mutalisk (Health: %d, Damage: %d)\n  "
                            "Special ability: The Mutalisk can regenerate %d of its HP after every round.\n\n"
                            "b - Broodlord (Health: %d, Damage: %d)\n  "
                            "Special ability 1: At the beginning the Broodlord spawns 2 Broodlings, which deal the same damage as the Broodlord.\n    "
                            "With every attack the amount of Broodlings decreases by 1, and when they reach 0 the Broodlord spawns another 2.\n    "
                            "You can think of Broodlord's damage in the following formula (Broodlord damage + Broodlord damage * Broodling count)\n  "
                            "Special ability 2: The broodlord receives 10%% less damage from all sources.\n",
                            MUTALISK_HEALTH, MUTALISK_DAMAGE, MUTALISK_HEALTH_REGEN, BROODLORD_HEALTH, BROODLORD_DAMAGE);
            break;
        default:
            exit(-1);
    }
}

/**
 * This function asks our player for their desired race to play with.
 * It takes int input from console and sets the global race identifying variables to the appropriate value.
 */
void askForRace() {


    printf("Hello and welcome to our tiny implementation of the world fameous Starcraft game.\nYou can start "
           "by selecting races for teams 1 and 2, and watch them decimate each other on the battlefield!\n"
           "The races are as follows:\n0 - Terran,\n1 - Protoss,\n2 - Zerg.\n");

    // Race selection for team 1
    printf("Please pick a race for team 1 by entering a number between 0-2:\n");
    team1RaceID = validateIntegerInput();

    // Race selection for team 2
    printf("Please pick a race for team 2 by entering a number between 0-2:\n");
    team2RaceID = validateIntegerInput();
}