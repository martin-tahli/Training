#include "Vector.h"
#include "ErrorHandler.h"

/**
 * This will initialise the vector.
 * @param vec pointer to the vector.
 * @param initialCapacity the initial capacity of the vector.
 */
void vectorInit(Vector *vec, size_t initialCapacity) {

    vec->capacity = initialCapacity;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity);
    if(vec == NULL)
    {
        printErrorStatus(ERR_MMU_VECTOR_INIT);
        return;
    }
}

/** \n
 * This function is to get the size(in number of existing items) of the vector.
 * @param v pointer to the vector
 * @return size of the existing items in numeric form.
 */
size_t vectorGetSize(Vector *v) {
    return v->size;
}

/** \n
 * This function is to check whether the vector is empty or not.
 * @param vec pointer to the vector.
 * @return True if empty, False if not.
 */
 /*
bool vectorIsEmpty(Vector *vec) {
    return vec->size == 0;
}
*/
/** \n
 * This function is to resize the vector.
 * @param vec pointer to the vector.
 * @param capacity the new capacity desired.
 */
 /*
void vectorResize(Vector *vec, size_t capacity) {
    void **items = realloc(vec->items, sizeof(void *) * capacity);
    if (items) {
        vec->items = items;
        vec->capacity = capacity;
    }
    if (vec->size >= capacity) {
        vec->size = capacity;
    }
}
*/
/** \n
 * This function is to add an item at the end of the vector
 * @param vec pointer to the vector
 * @param item the item to add
 */
 /*
void vectorPush(Vector *vec, void *item) {
    // this will check whether we are at max or not, and if we are it will increase capacity * 2
    if (vec->capacity == vec->size) {
        vectorResize(vec, vec->capacity * 2);
    }
    vec->items[vec->size] = item;
    vec->size++;
}
*/
/** \n
 * This function is to set an item in the vector.
 * @param vec pointer to the vector.
 * @param idx the desired index.
 * @param item pointer to the item we wish to set.
 */
void vectorSet(Vector *vec, size_t idx, void *item) {
    vec->size++;
    vec->items[idx] = item;
}


/** \n
 * This function is to get an element from our vector at a desired index
 * @param vec pointer to the vector.
 * @param idx the desired index.
 * @return the item at that index as void pointer.
 */
void *vectorGet(Vector *vec, size_t idx) {
    if (idx < vec->size) {
        return vec->items[idx];
    }
    return NULL;
}

/** \n
 * This function is to refer to the last item of the vector.
 * @param vec pointer to the vector.
 * @return the last (existing) item of the vector.
 */
struct basicUnit *vectorBack(Vector *vec) {
    if (0 == vec->size) {
        return NULL;
    }

    return vec->items[vec->size - 1];
}

/** \n
 * This is to remove an item at a specific index from the vector.
 * @param vec pointer to the vector.
 * @param idx the desired index.
 */
 /*
void vectorDelete(Vector *vec, size_t idx) {
    if (idx >= vec->size) {
        return;
    }

    vec->items[idx] = NULL;

    for (size_t i = idx; i < vec->size - 1; ++i) {
        vec->items[i] = vec->items[i + 1];
        vec->items[i + 1] = NULL;
    }

    vec->size--;
}
*/
/** \n
 * This function is to decrease the size (in existing items) of the vector by 1.\n
 * This DOES NOT remove the item, just reduces size by 1.
 * @param vec pointer to the vector.
 */
void vectorPop(Vector *vec) {
    if (vec->size == 0) {
        return;
    }

    vec->size--;
}

//typedef struct {
//    void **items;
//    size_t capacity;
//    size_t size;
//} Vector;

//void full(){
//    Vector *vec= malloc();
//     vecAdd(1,2,3);
//    vectorFree(vec);
//    print(vec);
//}


void vectorFree(Vector *vec) {
    if (vec->items != NULL) {
        free(vec->items);
        vec->items = NULL;
        vec->size = 0;
        vec->capacity = 0;
    }

}
