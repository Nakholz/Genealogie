/*
** main.c for  in /home/arnhol_m/rendu/synth/FASTAtools/srcs
**
** Made by martin Arnholz
** Login   <arnhol_m@epitech.net>
**
** Started on  Wed Jun 24 20:50:56 2015 martin Arnholz
** Last update Sat Jul  4 23:17:33 2015 martin Arnholz
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "my.h"

void	dir_tolist(t_list *list, char *repo)
{
  struct dirent *read;
  DIR	*rep;
  char	*save;

  if ((rep = opendir(repo)) == NULL)
    {
      dprintf(2 ,"Famille incorrecte\n");
      return;
    }
  while ((read = readdir(rep)))
    if (read->d_name[0] != '.')
      {
	if ((save = malloc(sizeof(char) * strlen(read->d_name) + strlen(repo) + 2)) == 0)
	  return;
	save = strcat(save, repo);
	save = strcat(strcat(strcat(save ,"/") ,read->d_name) ,"\0");
	add_str(&list, read->d_name, save);
	save = NULL;
      }
}

int	main(int ac, char **av)
{
  t_list *list;
  char	 *repo;
  int	 opt;
  void  (*option[7])(t_list *, char *);

  repo = strdup(av[1]);
  if (ac != 3)
    {
      printf("usage : repository(family) file(name)\n");
      return (0);
    }
  else
    {
      list = init_list();
      opt = atoi(get_next_line(0));
      dir_tolist(list, repo);
      croi_list(list);
      option[1] = &ex_opt1;
      option[2] = &ex_opt2;
      option[opt](list ,av[2]);
    }
  return (0);
}
