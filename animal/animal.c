#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"

static void generic_walk() {
    printf("Just a normal animal walking...\n");
}

static void generic_make_sound() {
    printf("Just a normal animal making some generic sound...\n");
}

Animal *new_animal(const char *name) {
    Animal *animal = malloc(sizeof(Animal));
    animal->attributes = malloc(sizeof(Attributes));
    animal->methods = malloc(sizeof(Methods));
    strcpy(animal->attributes->name, name);
    animal->methods->walk = generic_walk;
    animal->methods->make_sound = generic_make_sound;

    return animal;
}

void initialize_animal(Animal *animal, const char *name) {
    animal->attributes = malloc(sizeof(Attributes));
    animal->methods = malloc(sizeof(Methods));
    strcpy(animal->attributes->name, name);
    animal->methods->walk = generic_walk;
    animal->methods->make_sound = generic_make_sound;
}

void del_animal(Animal *animal) {
    free(animal->attributes);
    free(animal->methods);
}


