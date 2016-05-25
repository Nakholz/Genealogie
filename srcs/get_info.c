/*
** get_info.c for  in /home/arnhol_m/rendu/synth/genealogie/srcs
**
** Made by martin Arnholz
** Login   <arnhol_m@epitech.net>
**
** Started on  Sat Jul  4 10:36:35 2015 martin Arnholz
** Last update Sat Jul  4 16:18:17 2015 martin Arnholz
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
