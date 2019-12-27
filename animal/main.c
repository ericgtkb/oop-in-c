#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "cat.h"

int main() {
    // Note this implementation exposes this to client code, and one may call a method with some other object

    Animal *animal_ptr = new_animal("Unknown animal");
    printf("This is an unknown animal, it's name is %s.\n", animal_ptr->attributes->name);
    animal_ptr->methods->walk(animal_ptr);
    animal_ptr->methods->make_sound(animal_ptr);

    Animal *cat_ptr = new_cat("Cheeto", "tabby");
    cat_ptr->methods->walk(cat_ptr);
    cat_ptr->methods->make_sound(cat_ptr);

    // Calling cat only methods
    // Error main.c doesn't know what Cat class actually look like
    // ((Cat *) cat_ptr)->cat_methods->meow((Cat *) cat_ptr);

    Animal animal;
    initialize_animal(&animal, "Another animal");
    printf("This is another unknown animal, it's name is %s.\n", animal.attributes->name);
    animal.methods->walk(&animal);
    animal.methods->make_sound(&animal);

    // Calling animal's method but with cat_ptr
    animal.methods->make_sound(cat_ptr);
    // This shows that we shouldn't call methods that take a this pointer from client code

    del_animal(animal_ptr);
    del_cat((Cat *) cat_ptr);
    del_animal(&animal);
    free(cat_ptr);
    free(animal_ptr);
    return 0;
}
