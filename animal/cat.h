#ifndef ANIMAL_CAT_H
#define ANIMAL_CAT_H

#include "animal.h"

typedef struct _Cat Cat;

Animal *new_cat(const char *name, const char *breed);
void initialize_cat(Cat *cat, const char *name, const char *breed);
void del_cat(Cat *cat);
#endif //ANIMAL_CAT_H
