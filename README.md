# Pathetic Object Oriented Platform (poop)

> Beware, shitty macro magic awaits -- Gandalf

So this is a... thing. It uses macros for at least encapsulating methods + data in the same structure. You can technically have polymorphism and inheritance in here (ducktyped, because macros), but it doesn't have a good way of doing it (I'm looking for a way for defining classes better).

## How to use

You define a struct with the name of the class (for this example it is `Object`), this will have a pointer to its vtable struct (methods defined for that class). It has to be called `m`.  
  
All classes also have a method called `delete`, that takes a `<class>**`, frees all memory and resources, and nullifies the given pointer.
  
You halso have to have a global function called `Init<class>` that receives a `<class>*` and initializes it (giving default values, but most important, it sets the `m` and `delete` member).  
  
Example usage:

```

typedef struct { ...; ObjectVT* m; } Object;
typedef struct { ...; void(*delete)(Object**); } ObjectVT;
InitObject(Object* self) { ... }

int main() {
    Object* obj = new(Object); // This mallocs and calls ObjectInit
    call(obj, someMethod, someArg); // You can also do obj->m->someMethod(obj, someArg)
    delete(obj) // This will call destructor
    ...
}

```

## TODO

* Less shitty dynamic dispatch
* Common steps of inialization (VTable setting, nullifying) abstracted.
* Finding a block library for simplicity
* Inheritance
* Private members