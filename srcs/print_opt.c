/*
** print_opt.c in /home/nakholz/rendu/Github/genealogie/srcs
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Thu Jul  2 21:14:36 2015 martin Arnholz
** Last update Wed May 25 11:55:33 2016 
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void    print_list(t_list *list)
{
  t_elem *elem;

  elem = list->first;
  while (elem != NULL)
    {
      printf("%s\n", elem->name);
      printf("%d\n", elem->time);
      elem = elem->next;
    }
}

void    print_0(t_list *list)
{
  t_elem *elem;

  elem = list->first;
  while (elem != NULL)
    {
      if (elem == list->first)
	printf("%s", elem->name);
      else
	printf(" / %s", elem->name);
      elem = elem->next;
    }
  printf("\n");
}

char	**sort_tab(char *str, int k)
{
  char	**new;
  int	a;
  
  a = 0;
  if ((new = malloc(sizeof(char *) * strlen(str) - k - 1)) == 0)
    return (0);
  while (a < k)
    {
      if ((new[a] = malloc(sizeof(char) * k)) == 0)
	return (0);
      a++;
    }
  return (new);
}

char	**fill_tab(char *str, int k)
{
  int	i;
  int	x;
  
  i = 0;
  x = 0;
  while (str[i])
    {
      while (x < k)
	{
	  printf("%c", str[x]);
	  x++;
	}
      x = 0;
      i++;
    }
  return (0);
}

char	**alpha(char **tab)
{
  int	i;
  
  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s\n", tab[i]);
      i++;
    }
  return (tab);
}
