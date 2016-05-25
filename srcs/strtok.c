/*
** strtok.c in /home/nakholz/rendu/Github/genealogie/srcs
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Fri Jul  3 15:11:41 2015 martin Arnholz
** Last update Wed May 25 11:55:56 2016 
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int     count_word(char *str ,char sep)
{
  int   i;
  int   o;

  i = 0;
  o = 0;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
        o++;
      i++;
    }
  o++;
  return (o);
}

int     size_dtab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

int    count_char(char *str, int i, char sep)
{
  while (str[i] != sep && str[i] != '\0')
    i++;
  return (i);
}

char    **my_str_to_wordtab(char *str ,char sep)
{
  char   **tab;
  int   i;
  int   y;
  int   x;

  y = 0;
  i = 0;
  if ((tab = malloc(sizeof(char*) * (count_word(str ,sep) + 1))) == 0)
    return (NULL);
  while (str[i] != '\0')
    {
      if ((tab[y] = malloc(sizeof(char) * (count_char(str, i, sep) + 1))) == 0)
	return(NULL);
      x = 0;
      while (str[i] != sep && str[i] != '\0')
        {
          tab[y][x] = str[i];
          x++;
          i++;
        }
      if (str[i] == '\0')
        i--;
      i++;
      y++;
    }
  tab[y] = NULL;
  return (tab);
}
