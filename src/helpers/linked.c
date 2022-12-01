/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** linked
*/

#include "../../include/myhunter.h"
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

void remove_from_linked(linked_t **begin, sprite_t *data)
{
    linked_t *tmp = *begin;
    linked_t *prev = NULL;

    sfSprite_destroy(data->sprite);
    if (tmp->data == data) {
        tmp = tmp->next;
        free(*begin);
        *begin = tmp;
        return;
    }

    while (tmp != NULL && tmp->data != data) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return;

    prev->next = tmp->next;
    free(tmp);
}
