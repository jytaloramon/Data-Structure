/**
 * @author Ytalo Ramon
 * @date   14/02/2021
*/

#include "list.h"
#include "../../math/include/math_extend.h"

/**
 * struct _ItemList.
 * attr: data - Payload.
*/
struct _ItemList{
    void *data;
};


/**
 * struct _List.
 * attr: p_front - Index of the first element of the list.
 * attr: p_rear - Index of the last element of the list.
 * attr: size - List size.
 * attr: length - Number of elements currently present in the lists.
 * attr: items - array of elements.
*/
struct _List{
    size_t p_front, p_rear, size, length;
    struct _ItemList *items; 
};

/**
 * Create a new list.
 * @param size List size.
 * @return A list instance or Null in case of error.
*/
List *new_list(int size);

/**
 * Checks if the queue is full.
 * @param queue Queue pointer.
 * @return Or 1 if full or 0 if not full.
*/
int is_full(List *list);