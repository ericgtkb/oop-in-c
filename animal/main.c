#include <stdio.h>
#include <stdlib.h>
#include "animal.h"

int main() {
    Animal *animal_ptr = new_animal("Unknown animal");
    printf("This is an unknown animal, it's name is %s.\n", animal_ptr->attributes->name);
    animal_ptr->methods->walk();
    animal_ptr->methods->make_sound();

    Animal animal;
    initialize_animal(&animal, "Another animal");
    printf("This is another unknown animal, it's name is %s.\n", animal.attributes->name);
    animal.methods->walk();
    animal.methods->make_sound();

    del_animal(animal_ptr);
    del_animal(&animal);
    free(animal_ptr);
    return 0;
}
