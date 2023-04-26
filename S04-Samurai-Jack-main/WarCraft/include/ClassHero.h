
#ifndef S04_SAMURAI_JACK_CLASSHERO_H
#define S04_SAMURAI_JACK_CLASSHERO_H



typedef struct Hero Hero;


struct Hero *initHero(void);

//getters
char *GetHeroName(struct Hero *currentHero);

int GetHeroHealth(struct Hero *currentHero);

int GetHeroArmor(struct Hero *currentHero);

int GetHeroClassID(struct Hero *currentHero);

int GetHeroStatus(struct Hero *currentHero);

void *GetFuncPtrAttack(struct Hero *currentHero);

int GetHeroMaxHealth(struct Hero *currentHero);

int GetHeroMaxArmor(struct Hero *currentHero);

//setters
void SetHeroDamage(struct Hero **self, int damage);

void SetFuncPtrMenu(struct Hero **self, void *funcName);

void SetHeroName(struct Hero **self, char *NewName);

void SetHeroHealth(struct Hero **self, int NewHealth);

void SetHeroArmor(struct Hero **self, int NewArmor);

void SetHeroClassID(struct Hero **self, int NewClass);

void SetHeroStatus(struct Hero **self, int NewStatus);

void SetHeroMaxHealth(struct Hero** self, int maxHP);

void SetHeroMaxArmor(struct Hero** self, int maxArmor);


#endif //S04_SAMURAI_JACK_CLASSHERO_H
