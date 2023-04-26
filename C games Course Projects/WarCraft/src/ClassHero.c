#include <string.h>
#include <stdlib.h>


#include "ClassHero.h"
#include "ErrorHandler.h"
#include "Vector.h"

#define MAX_HERO_NAME_SIZE  20


struct Hero {
    char *name;
    int damage;
    int health;
    int status;
    int armor;
    int classID;
    int MaxHealth;
    int MaxArmor;

    void (*heroMenu)();

};


struct Hero *initHero(void) {
    struct Hero *tmpHero = (struct Hero *) malloc(sizeof(struct Hero));
    if (tmpHero == NULL) {
        printErrorStatus(ERR_ALLOCATE_INIT_HERO);
        return false;
    }
    tmpHero->name = NULL;
    tmpHero->health = 0;
    tmpHero->status = 0;
    tmpHero->armor = 0;
    tmpHero->classID = 0;
    tmpHero->heroMenu = NULL;

    return tmpHero;
}



//=========================== GETTERS ========================================


// status getter
void *GetFuncPtrAttack(struct Hero *currentHero) {
    return currentHero->heroMenu;
}

int GetHeroMaxHealth(struct Hero *currentHero) {
    return currentHero->MaxHealth;
}

int GetHeroMaxArmor(struct Hero *currentHero) {
    return currentHero->MaxArmor;
}

// status getter
int GetHeroStatus(struct Hero *currentHero) {
    return currentHero->status;
}

// health getter
int GetHeroHealth(struct Hero *currentHero) {
    return currentHero->health;
}

// name getter
char *GetHeroName(struct Hero *currentHero) {
    return currentHero->name;
}

// class getter
int GetHeroClassID(struct Hero *currentHero) {
    return currentHero->classID;
}

// armor getter
int GetHeroArmor(struct Hero *currentHero) {
    return currentHero->armor;
}

int GetHeroDamage(struct Hero **currentHero) {
    return (*currentHero)->damage;
}

//=========================== SETTERS =======================================

void SetHeroDamage(struct Hero **const self, const int damage) {
    (*self)->damage = damage;
}

// status setter
void SetHeroStatus(struct Hero **const self, const int NewStatus) {
    (*self)->status = NewStatus;
}

// health setter
void SetHeroHealth(struct Hero **const self, const int NewHealth) {
    (*self)->health = NewHealth;
}


// name setter
void SetHeroName(struct Hero **const self, char *const NewName) {
    (*self)->name = (char *) malloc(sizeof(char) * MAX_HERO_NAME_SIZE);
    strcpy((*self)->name, NewName);
}

// class setter
void SetHeroClassID(struct Hero **const self, const int NewClass) {
    (*self)->classID = NewClass;
}

// armor setter
void SetHeroArmor(struct Hero **const self, const int NewArmor) {
    (*self)->armor = NewArmor;
}

// armor setter
void SetFuncPtrMenu(struct Hero **const self, void* funcName) {
    (*self)->heroMenu = (void (*)()) funcName;
}

void SetHeroMaxHealth(struct Hero** self, const int maxHP) {
    (*self)->MaxHealth = maxHP;
}

void SetHeroMaxArmor(struct Hero** self, const int maxArmor) {
    (*self)->MaxArmor = maxArmor;
}
