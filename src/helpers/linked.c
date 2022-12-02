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

    if (tmp == NULL) return;
    if (tmp->data == data) {
        *begin = tmp->next;
        free(tmp);
        sfSprite_destroy(data->sprite);
        return;
    }

    while (tmp != NULL && tmp->data != data) {
        prev = tmp;
        tmp = tmp->next;
    }

    prev->next = tmp->next;
    sfSprite_destroy(data->sprite);
    free(tmp);
}
