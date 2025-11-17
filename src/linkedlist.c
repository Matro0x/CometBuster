#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
  return NULL;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
  list_ptr new_node = (list_ptr)malloc(sizeof(s_list_node_t));
  if(!new_node){
    printf("error:Cannot allocate memory for new list node\n");
    return list;
  }
  new_node -> data = sprite;
  new_node -> next = list;
  return new_node;
}

/* Return the length of a list
 * */
int list_length(list_ptr l)
{
  int count = 0;
  list_ptr current = l;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

/* Reverse the order of a list
 * */
void list_reverse(list_ptr * l)
{
  list_ptr prev = NULL;
  list_ptr current = *l;
  list_ptr next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *l = prev;
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  if (list == NULL) return NULL; 
  list_ptr new_list = NULL;
  list_ptr current = list;
  list_ptr *last_ptr = &new_list;
   while (current != NULL) {
    list_ptr new_node = (list_ptr)malloc(sizeof(s_list_node_t));
    if (!new_node) {
      list_ptr temp = new_list;
      while (temp != NULL) {
        list_ptr next = temp->next;
        free(temp);
        temp = next;
      }
      return NULL;
    }
    new_node->data = current->data;  
    new_node->next = NULL;
    *last_ptr = new_node;
    last_ptr = &(new_node->next);
    current = current->next;
  }
  return new_list;
}

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  return (l == NULL);
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
  if (l == NULL) return NULL;
  return l->data;
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  if (l == NULL) return NULL;
  return l->next;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  if (l == NULL || *l == NULL) return NULL;
  if ((*l)->next == NULL) {
    sprite_t sprite = (*l)->data;
    free(*l);
    *l = NULL;
    return sprite;
  }
  list_ptr current = *l;
  while (current->next->next != NULL) {
    current = current->next;
  }
  sprite_t sprite = current->next->data;
  free(current->next);
  current->next = NULL;
  return sprite;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
  if (l == NULL || *l == NULL || elt == NULL) return;
  if (*l == elt) {
    *l = elt->next;
    free(elt);
    return;
  }
  list_ptr current = *l;
  while (current != NULL && current->next != elt) {
    current = current->next;
  }
  if (current != NULL) {
    current->next = elt->next;
    free(elt);
  }
}

/* Wipe out a list. 
 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
  list_ptr current = l;
  while (current != NULL) {
    list_ptr next = current->next;
    if (current->data != NULL) {
      sprite_free(current->data);
    }
    free(current);
    current = next;
  }
}
