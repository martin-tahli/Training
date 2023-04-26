#ifndef VECTOR_H_
#define VECTOR_H_


#include <stddef.h>
#include <stdbool.h>

typedef struct {
  void **items;
  int capacity;
  int size;
} Vector;

void vectorInit(Vector *vec, int initialCapacity);
int vectorGetSize(Vector *vec);
bool vectorIsEmpty(Vector *vec);
void vectorResize(Vector *vec, int newSize);
void vectorPush(Vector *vec, void *elem);
void vectorSet(Vector *vec, int idx, void *elem);
void *vectorGet(Vector *vec, int idx);
void *vectorBack(Vector *vec);
void vectorDelete(Vector *vec, int idx);
void vectorPop(Vector *vec);
void vectorFree(Vector *vec);

#endif /* VECTOR_H_ */
