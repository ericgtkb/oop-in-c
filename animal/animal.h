#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H

typedef struct _Attributes Attributes;
typedef struct _Methods Methods;

typedef struct _Animal {
    Attributes *attributes;
    Methods *methods;
} Animal;


struct _Attributes {
    char name[50];
};

typedef void _walk(void);
typedef void _make_sound(void);

struct _Methods {
    _walk *walk;
    _make_sound *make_sound;
};

Animal *new_animal(const char *name);
void initialize_animal(Animal * animal, const char *name);
void del_animal(Animal *animal);

#endif //ANIMAL_ANIMAL_H
