

#ifndef S04_SAMURAI_JACK_UNDEADRACEDEFINES_H
#define S04_SAMURAI_JACK_UNDEADRACEDEFINES_H


//----------------------------->> Death Knight CLASS <<----------------------------

enum DeathKnightStats {
    MAX_DEATH_KNIGHT_HEALTH = 550,
    MAX_DEATH_KNIGHT_ARMOR = 80,
    DEATH_KNIGHT_ARMOR = 8,
    MAX_DEATH_KNIGHT_MANA = 210,
    DEATH_KNIGHT_BASE_MANA_REGEN = 45,
    DEATH_KNIGHT_DAMAGE = 30,

};
enum SpellsDeathKnight{
    DEATH_KNIGHT_NORMAL_DAMAGE = 1,
    DEATH_COIL = 2,
    ANIMATED_DEAD = 3,
};

enum DeathCoil {
    DEATH_COIL_MANA_COST = 100,
    DEATH_COIL_DAMAGE = 100,
};

enum AnimateDeadSpell{
    ANIMATE_DEAD_MANA_COST = 170,
    SPAWN_GHOUL = 7,
    GHOUL_DAMAGE = 30
};


//------------------------------>> DRAW RANGER Class <<-----------------------------------

enum DrawRangerStats {
    MAX_DRAW_RANGER_HEALTH = 400,
    MAX_DRAW_RANGER_ARMOR = 80,
    DRAW_RANGER_ARMOR = 5,
    MAX_DRAW_RANGER_MANA = 170,
    DRAW_RANGER_BASE_MANA_REGEN = 30,
    DRAW_RANGER_DAMAGE = 30
};


enum DrawRangerSpells {
    DRAW_RANGER_NORMAL_DAMAGE = 1,
    BLACK_ARROWS = 2,
    LIFE_DRAIN = 3
};

enum BlackArrows {
    BLACK_ARROWS_MANA_COST = 80,
    BLACK_ARROWS_DAMAGE = 70,
};

enum LifeDrain {
    LIFE_DRAIN_MANA_COST = 130,
    LIFE_DRAIN_DAMAGE = 180,
    LIFE_DRAIN_HEAL = 90
};

#endif //S04_SAMURAI_JACK_UNDEADRACEDEFINES_H
