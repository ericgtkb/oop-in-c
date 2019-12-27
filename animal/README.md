# Polymorphism
The Animal class defines some attributes and methods. Since they are defined in the .h file they are all public.

The Cat class "inherits" from the animal class but overwrites the methods with Cat's implementation. In addition, the Cat class also defines some additional attributes and methods, but since they are not exposed in the .h file they are all private to the client.