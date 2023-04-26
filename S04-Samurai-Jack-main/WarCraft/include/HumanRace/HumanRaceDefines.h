
#ifndef S04_SAMURAI_JACK_HUMANRACEDEFINES_H
#define S04_SAMURAI_JACK_HUMANRACEDEFINES_H


//-----------------------------PALADIN CLASS----------------------------
#define NO_DEAD_ALLY 0


enum PaladinStats {
    MAX_PALADIN_HEALTH = 500,
    MAX_PALADIN_ARMOR = 40,
    MAX_PALADIN_MANA = 300,
    PALADIN_ARMOR = 10,
    PALADIN_BASE_MANA_REGEN = 40,
    PALADIN_DAMAGE = 20
};

enum SpellsPaladin {
    PALADIN_ARMOR_BUFF = 1,
    FLASH_LIGHT = 2,
    REVIVE = 3,

};

enum FlashLight {
    FLASH_LIGHT_MANA_COST = 50,
    FLASH_LIGHT_HEAL = 70,
};
enum DevotionAura {
    DEVOTION_AURA_MANA_COST = 100,
    DEVOTION_AURA_BUFF = 30,
};

enum Revive {
    REVIVE_MANA_COST = 250,
    REVIVE_HEALTH = 250
};


//-----------------------------ARCH MAGE CLASS ----------------------
enum ArchMageStats {
    MAX_ARCH_MAGE_HEALTH = 400,
    MAX_ARCH_MAGE_ARMOR = 80,
    MAX_ARCH_MAGE_MANA = 360,
    ARCH_MAGE_ARMOR = 5,
    ARCH_MAGE_BASE_MANA_REGEN = 60,
    ARCH_MAGE_DAMAGE = 20
};


enum ArchMageSpells {
    ARCH_MAGE_NORMAL_DAMAGE = 1,
    SUMMON_WATER_ELEMENTAL = 2,
    MANA_BLAST = 3
};

enum SummonWaterElemental{
    SUMMON_WATER_ELEMENTAL_MANA_COST = 120,
    WATER_ELEMENTAL_COUNT = 3,
    WATER_ELEMENTAL_DAMAGE = 40
};

#endif
