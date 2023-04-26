
#include <stdio.h>
#include <stdlib.h>

#include "BattleField.h"
#include "Defines.h"
#include "CheckInput.h"
#include "HumanRace/ClassPaladin.h"
#include "HumanRace/ClassArchMage.h"
#include "UndeadRace/ClassDeathKnight.h"
#include "UndeadRace/ClassDrawRanger.h"

#define ONE_POSITION 1


static void inputHeroName(char *heroName, const int idx) {

    fflush(stdin);
    printf("\nPlease, enter Hero No %d name here:\n", idx + ONE_POSITION);
    fgets(heroName, MAX_HERO_NAME_SIZE, stdin);
    terminateTrailingNewline(heroName);
}


static int chooseHero() {
    int classID;
    fflush(stdin);
    puts("\nChoose Hero:\n- For Paladin  \t\t\t0\n- "
         "For ArchMage  \t\t1\n- "
         "For DeathKnight  \t\t2\n- "
         "For DrawRanger  \t\t3\n- ");

    classID = validateIntegerInput(0, 3);

    return classID;
}


void fillTeam(Vector *currentTeam, const int teamSize) {


    char name[MAX_HERO_NAME_SIZE];
    int classID;
    vectorInit(currentTeam, 5);
    for (int i = 0; i < teamSize; i++) {

        inputHeroName(name, i);
        classID = chooseHero();

        switch (classID) {
            case PALADIN:
                vectorSet(currentTeam, i, GeneratePaladin(name));
                break;
            case DEATH_KNIGHT:
                vectorSet(currentTeam, i, GenerateDeathKnight(name));
                break;
            case DRAW_RANGER:
                vectorSet(currentTeam, i, GenerateDrawRanger(name));
                break;
            case ARCH_MAGE:
                vectorSet(currentTeam,i, GenerateArchMage(name));
            default:
                break;   // some error handle maybe
        }
    }
}



void deinit(BattleField *battleField) {

    for (int i = 0; i < battleField->Team1.capacity; i++) {

        battleField->Team1.size = battleField->Team1.capacity;

        struct Hero *temp = vectorGet(&battleField->Team1, i);

        free(temp);

    }

    vectorFree(&battleField->Team1);

    for (int i = 0; i < battleField->Team2.capacity; i++) {

        battleField->Team2.size = battleField->Team2.capacity;

        struct Hero *temp = vectorGet(&battleField->Team2, i);

        free(temp);
    }

    vectorFree(&battleField->Team2);
}
