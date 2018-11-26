#ifndef __OOP_H__
#define __OOP_H__

#include <stdlib.h>
#include <string.h>

// Every object in this system will be pointed by this bad boy eventually
void* ___self;

#define constructor(class, ...) \
    void _CONSTRUCTOR_##class(class* self) { \
        memset(self, '\0', sizeof(class)); \
        self->m = &class##_VT; \
        __VA_ARGS__ \
    }

#define call(object, method, args...) object->m->method(object, args)

#define new(class)( \
    ___self = malloc(sizeof(class)), \
    _CONSTRUCTOR_##class(___self), \
    ___self)

#define delete(object) object->m->delete(&object)

#endif