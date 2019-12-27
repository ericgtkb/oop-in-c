#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cat.h"


// These are all private since they are only defined here.
typedef struct _CatAttributes CatAttributes;
typedef struct _CatMethods CatMethods;

typedef struct _Cat {
    // Notice the order is the same as in Animal, so that the pointer points to the correct member after casting
    Attributes *attributes;
    Methods *methods;

    // Cat specific attributes and methods
    CatAttributes *cat_attributes;
    CatMethods *cat_methods;
} Cat;

struct _CatAttributes {
    char breed[50];
};

typedef void _meow(Cat *);

struct _CatMethods {
    _meow *meow;
};

static void cat_walk(Animal *this) {
    printf("%s, the %s is walking...\n", this->attributes->name, ((Cat *) this)->cat_attributes->breed);
}

static void cat_make_sound(Animal *this) {
    printf("Calling cat's make sound method instead...\n");
    ((Cat *) this)->cat_methods->meow((Cat *) this);
}

static void cat_meow(Cat *this) {
    printf("%s, the %s is meowing...\n", this->attributes->name, this->cat_attributes->breed);
}

static Methods cat_animal_methods = {cat_walk, cat_make_sound};

static CatMethods cat_cat_methods = {cat_meow};


Animal *new_cat(const char *name, const char *breed) {
    Cat *cat = malloc(sizeof(Cat));
    initialize_cat(cat, name, breed);

    return (Animal *) cat;
}

void initialize_cat(Cat *cat, const char *name, const char *breed) {
    // Initialize attributes and methods
    initialize_animal((Animal *) cat, name);

    // Replace methods with cat_animal_methods
    cat->methods = &cat_animal_methods;
    cat->cat_attributes = malloc(sizeof(CatAttributes));
    strcpy(cat->cat_attributes->breed, breed);
    cat->cat_methods = &cat_cat_methods;
}

void del_cat(Cat *cat) {
    free(cat->cat_attributes);
    del_animal((Animal *) cat);
}
