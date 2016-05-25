/*
** list.c in /home/nakholz/rendu/Github/genealogie/srcs
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
**
** Started on  Tue Jun 16 09:14:46 2015 Martin Arnholz
** Last update Wed May 25 11:55:04 2016 
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

t_list	*init_list()
{
  t_list *list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (0);
  list->first = NULL;
  list->last = NULL;
  return (list);
}

int     my_revlist(t_elem **begin)
{
  t_elem *tmpnext;
  t_elem *tmplist;

  if ((*begin) != NULL)
    {
      tmpnext = (*begin)->next;
      (*begin)->next = NULL;
      while (tmpnext != NULL)
        {
          tmplist = tmpnext->next;
          tmpnext->next = (*begin);
          (*begin) = tmpnext;
          tmpnext = tmplist;
        }
    }
  return (0);
}

int     add_elem(t_list **list, int nb)
{
  t_elem *elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (0);
  elem->time = nb;
  elem->next = (*list)->first;
  (*list)->first = elem;
  return (0);
}

int	add_str(t_list **list, char *forename, char *save)
{
  t_elem *elem;
  
  if ((elem = malloc(sizeof(t_elem))) == NULL)
    return (0);
  elem->name = forename;
  elem->path = save;
  elem->forename = forename;
  elem->lastname = get_name(save);
  elem->time = stat_lchange(save);
  stat(save, &(elem->info));
  if ((*list)->first == NULL && (*list)->last == NULL)
    {
      elem->next = NULL;
      elem->previous = NULL;
      (*list)->first = elem;
      (*list)->last = elem;
    }
  else
    {
      elem->previous = (*list)->last;
      elem->next = NULL;
      (*list)->last->next = elem;
      (*list)->last = elem;
    }
  return (0);
}
