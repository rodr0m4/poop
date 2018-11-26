#include <stdio.h>
#include <stdlib.h>
#import "poop.h"

typedef struct {
    struct ObjectVT* m;
    int number;
} Object;

struct ObjectVT {
    void (*println)(Object*, char*);
    void (*delete)(Object**);
};

void _ObjectDelete(Object** ptr) {
    Object* obj = *ptr;

    free(obj);

    *ptr = NULL;
}

void _ObjectPrintln(Object* self, char* format) {
    printf(format, self->number);
    printf("\n");
};

struct ObjectVT Object_VT = {
    .println = _ObjectPrintln,
    .delete = _ObjectDelete
};

constructor(Object,
    self->number = 0;
)

int main() {
    Object* obj = new(Object);

    obj->number = 2;
    call(obj, println, "This should print two: %d");

    obj->number = 15;
    call(obj, println, "This should pint fifteen: %d");

    delete(obj);
    return 0;
}