/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** linked
*/

#include "../../include/bsmyhunter.h"
#include <stdlib.h>

void add_in_linked(linked_t **begin, sprite_t *data)
{
    linked_t *new = malloc(sizeof(linked_t));
    linked_t *tmp = *begin;

    new->data = data;
    new->next = NULL;
    if (*begin == NULL) {
        *begin = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}
