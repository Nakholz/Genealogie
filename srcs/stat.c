/*
** stat.c for  in /home/arnhol_m/rendu/synth/genealogie/srcs
**
** Made by martin Arnholz
** Login   <arnhol_m@epitech.net>
**
** Started on  Fri Jul  3 09:41:37 2015 martin Arnholz
** Last update Sat Jul  4 22:46:27 2015 martin Arnholz
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	stat_lchange(char *path)
{
  struct stat sb;

  if (stat(path ,&sb) == -1)
    return (0);
  else
    return (sb.st_mtime);
}

int	stat_size(char *path)
{
  struct stat sb;
  
  if (stat(path ,&sb) == -1)
    return (0);
  else
    return (sb.st_size);
}

int	stat_right(char *path)
{
  struct stat info;

  stat(path, &info);
  if (info.st_mode & S_IRGRP)
    return (1);
  else 
    return (0);
}

int	stat_inode(char *path)
{
  struct stat sb;
  
  if (stat(path ,&sb) == -1)
    return (0);
  else
    return (sb.st_ino);
}

int     sup(int va1, int va2)
{
  if (va1 > va2)
    return (1);
  else
    return (0);
}

void    croi_list(t_list *list)
{
  t_elem *elem;
  t_elem *tmp;
  int	 swap;
  char	 *save;
  
  elem = list->first;
  tmp = list->first;
  while (elem != NULL)
    {
	while (tmp != NULL)
	  {
	    if (sup(tmp->time ,elem->time))
	      {
		swap = tmp->time;
		save = tmp->name;
		tmp->time = elem->time;
		tmp->name = elem->name;
		elem->time = swap;
		elem->name = save;
	      }
	    tmp = tmp->next;
	  }
	tmp = list->first;
      elem = elem->next;
    }
}
