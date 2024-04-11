#ifndef ORDENAMIENTOS_H_INCLUDED
#define ORDENAMIENTOS_H_INCLUDED

void buuble_sort (void *vec, size_t mem, size_t tamanio, int (*cmp) (void*, void*) );
 /// int (*cmp) es un puntero a funcion y tengo que especificar lo que tiene adentro (void* x2)

 void show (void *vec, void (*sh)(void*));


#endif // ORDENAMIENTOS_H_INCLUDED
