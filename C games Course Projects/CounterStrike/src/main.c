#include <stdlib.h>
#include "BattleField.h"



int main() {


    printIntroMsg();

    BattleField battleField;

    createPlayers(&battleField);

    startBattle(&battleField);

    deinit(&battleField);

  return EXIT_SUCCESS;
}
