/*
** prerequis.c for  in /home/arnhol_m/rendu/synth/genealogie
**
** Made by martin Arnholz
** Login   <arnhol_m@epitech.net>
**
** Started on  Thu Jul  2 09:23:23 2015 martin Arnholz
** Last update Sat Jul  4 15:19:06 2015 martin Arnholz
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int	size_tab(char *path)
{
  int	i;
  struct dirent *read;
  DIR *rep;
  
  i = 0;
  rep = opendir(path);
  while ((read = readdir(rep)))
    if (read->d_name[0] != '.')
      i++;
  return (i);
}

int	n_swap(char *str1, char *str2)
{
  if (strcasecmpq(str2 ,str1) > 0)
    return (1);
  else
    return (0);
}

char	 **alph(char **tab)
{
  int	i;
  int	c;
  char	*swap;

  i = 0;
  c = 0;
  while (tab[i] != NULL)
    {
      while (tab[c] != NULL)
	{
	  if (n_swap(tab[i], tab[c]) == 1)
	    {
	      swap = tab[i];
	      tab[i] = tab[c];
	      tab[c] = swap;
	    }
	  c++;
	}
      c = 0;
      i++;
    }
  return (tab);
}

int	my_files_synthese(char *path)
{
  struct dirent *read;
  char **tab;
  int	i;
  DIR *rep;
  
  i = 0;
  if (!path)
    return (0);
  if ((tab = malloc(sizeof(char *) * size_tab(path))) == 0)
    return (0);
  rep = opendir(path);
  while ((read = readdir(rep)))
    if (read->d_name[0] != '.')
      {
	if ((tab[i] = malloc(sizeof(char) * strlen(read->d_name))) == 0)
	  return (0);
	tab[i] = read->d_name;
	i++;
      }
  tab[i] = NULL;
  tab = alph(tab);
  i = 0;
  while (tab[i] != NULL)
    {
      printf("%s\n", tab[i]);
      i++;
    }
  return (0);
}
