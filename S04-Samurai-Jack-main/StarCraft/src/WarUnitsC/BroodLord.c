#include "WarUnitsH/BroodLord.h"


// 2 broodlings, losing 1 each attack, then resetting. It will attack with 2, then with 1, then alone and reset as soon as the alone attack is done.

/**
 * This is a Broodlord generator.
 * @return returns a pointer to the new Broodlord.
 */
struct BroodLord *newBroodLord(void) {

    struct BroodLord *self = (struct BroodLord *) malloc(sizeof(struct BroodLord));
    if (self == NULL) {
        printErrorStatus(ERR_ALLOCATE_BROODLORD);
        return FALSE;
    }
    self->zergUnit.BasicUnit.unitType = BROODLORD;     //4
    self->zergUnit.BasicUnit.health = BROODLORD_HEALTH;
    self->zergUnit.BasicUnit.damage = BROODLORD_DAMAGE;
    self->armor = BROODLORD_ARMOR;
    self->broodlingCounter = BROODLORD_BROODLINGS_COUNT;
    self->zergUnit.BasicUnit.raceType = ZERG;

    return self;
}

/**
 * This will calculate the amount of damage the BroodLord will take.
 * @param currentUnit current BroodLord
 * @param incomingDamage the damage currently aimed at BroodLord
 * @return
 */
void damageReceivedBroodLord(struct BroodLord *self, int16_t incomingDamage) {
    float armorResistance= 100 - self->armor;
    armorResistance/=100;
    int16_t dmg =  (incomingDamage * armorResistance);
    self->zergUnit.BasicUnit.health  -= dmg;  //calculates reduced dmg taken of armor %

}

/**
 * This function calculates the Brood Lord damage according to its broodling counter.
 * @param self Broodlord pointer to the current BroodLord.
 * @return the damage in int_16t
 */
int16_t broodLordAttack(struct BroodLord *self) {
    if (self->broodlingCounter == -1) {  //it is -1 because of the attacks count, so we do 3*dmg ->
        self->broodlingCounter = BROODLORD_BROODLINGS_COUNT;
    }
    int16_t damageFromBroodlings = self->zergUnit.BasicUnit.damage * self->broodlingCounter;
    self->broodlingCounter--;
    return damageFromBroodlings + self->zergUnit.BasicUnit.damage;

}
