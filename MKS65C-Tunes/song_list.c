/*
 * A linked list with each node representing a song
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_list.h"

void print_song(struct song_node *n)
{
    if (n){
        printf("[%s - %s]\n", n->artist, n->name);
    }
}

void print_list(struct song_node *n)
{
    while (n)
    {
        print_song(n);
        n = n->next;
    }
}

struct song_node *add_node(struct song_node *list, char *artist, char *name)
{
    /*
     * Add a song before the given node.
     */

    struct song_node *new_node = malloc(sizeof(struct song_node));
    new_node->next = list;
    strncpy(new_node->artist, artist, 100);
    strncpy(new_node->name, name, 100);
    new_node->name[100 - 1] = 0; new_node->artist[100 - 1] = 0;
    return new_node;
}

struct song_node *add_node_sorted(struct song_node *list, char *artist, char *name)
{
    /*
     * Adds a song in alphabetical order, first by the artist name and then the song name.
     *
     * Returns a pointer to the beginning of the list. 
     */

    // Empty list, add to list
    if (list == NULL)
    {
        return add_node(list, artist, name);
    }

    struct song_node *cur = list;
    struct song_node *prev = NULL;
    struct song_node *new_node;

    /* Find a position to add the node */
    while (cur != NULL && strcmp(artist, cur->artist) > 0)
    {
        prev = cur;
        cur = cur->next;
    }

    /* Same artist name, sort by song name instead */
    while (cur != NULL && strcmp(artist, cur->artist) == 0 && strcmp(name, cur->name) > 0)
    {
        prev = cur;
        cur = cur->next;
    }

    /* Insert to found position */
    new_node = add_node(cur, artist, name);
    if (prev == NULL)
    {
        return new_node;
    }
    prev->next = new_node;
    return list;
}

struct song_node *find_node(struct song_node *list, char *artist, char *name)
{
    /*
     * Finds a song with the given artist and name in the list and returns a pointer to it.
     *
     * If not found, returns a null pointer.
     */
    for (; list != NULL; list = list->next)
    {
        if (strcmp(list->artist, artist) == 0 && strcmp(list->name, name) == 0)
        {
            return list;
        }
    }
    return 0;
}

struct song_node *random_node(struct song_node *list)
{
    /*
     * Returns a pointer to the random song from the list.
     */
    int len = 0;
    struct song_node *temp = list;
    for (; temp; temp = temp->next, len++);
    // can't divide by 0
    if (!len){
        return 0;
    }
    int rand_index = rand() % len;
    for (temp = list; rand_index != 0; temp=temp->next, rand_index--);
    return temp;
}

struct song_node *find_node_artist(struct song_node *list, char *artist)
{
    /*
     * Finds the first song in the list by the given artist and returns a pointer to it.
     * If not found, returns a null pointer.
     */

    for (; list != NULL; list = list->next)
    {
        if (strcmp(list->artist, artist) == 0)
        {
            return list;
        }
    }
}

struct song_node *remove_node(struct song_node *list, struct song_node *to_rm)
{
    /*
     * Remove to_rm from list.
     *
     * Returns a pointer to the beginning of the list.
     */
    if (!to_rm){
        return list;
    }
    if (list == to_rm)
    {
        struct song_node *new_head = to_rm->next;
        free(to_rm);
        return new_head;
    }
    struct song_node *cur = list;
    while (cur != NULL)
    {
        if (cur->next == to_rm)
        {
            cur->next = to_rm->next;
            free(to_rm);
            return list;
        }
        cur = cur->next;
    }
}

struct song_node *free_list(struct song_node *list)
{
    struct song_node *temp = list;
    while (list)
    {
        temp = list;
        list = list->next;
        free(temp);
    }
    return 0;
}
