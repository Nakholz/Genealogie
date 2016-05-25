/*
** get_info.c in /home/nakholz/rendu/Github/genealogie/srcs
** 
** Made by Arnholz Martin
** Login : arnhol_m
**
** Started on  Sat Jul  4 10:36:35 2015 martin Arnholz
** Last update Wed May 25 11:54:41 2016 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char	*get_name(char *lastname)
{
  char	 *save;
  int	i;
  int	x;

  x = 0;
  i = 0;
  if ((save = malloc(sizeof(char) * strlen(lastname))) == 0)
    return (NULL);
  while (lastname[i])
    {
      if (lastname[i] == '/')
	{
	  i++;
	  while (lastname[i] != '/')
	    {
	      save[x] = lastname[i];
	      i++;
	      x++;
	    }
	}
      i++;
    }
  return(save);
}
