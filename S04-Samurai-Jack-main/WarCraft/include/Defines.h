#ifndef DEFINES_H_
#define DEFINES_H_
#define NOT_ENOUGH_MANA 0
#define SUCCESSFULL_CAST 1
#define MAX_HERO_NAME_SIZE 20
#define MAX_TEAM_SIZE 4



enum HeroStatus {
    ALIVE, DEAD
};

enum HeroClasses {
    // Human Race
    PALADIN, ARCH_MAGE,
    // Undead Race
    DEATH_KNIGHT, DRAW_RANGER,
};

#endif /* DEFINES_H_ */
