#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"

static void generic_walk(Animal *this) {
    printf("%s is walking... just a normal animal walking...\n", this->attributes->name);
}

static void generic_make_sound(Animal *this) {
    printf("%s is making sound... Just a normal animal making some generic sound...\n", this->attributes->name);
}

// Define the methods here, so that we don't have to allocate space for methods for all animals
// Note however, attributes are for each individual animal
static Methods animal_methods = {generic_walk, generic_make_sound};

Animal *new_animal(const char *name) {
    Animal *animal = malloc(sizeof(Animal));
    initialize_animal(animal, name);

    return animal;
}

void initialize_animal(Animal *animal, const char *name) {
    animal->attributes = malloc(sizeof(Attributes));
    animal->methods = &animal_methods;
    strcpy(animal->attributes->name, name);
}

void del_animal(Animal *animal) {
    free(animal->attributes);
}


