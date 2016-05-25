/*
** opt.c in /home/nakholz/rendu/Github/genealogie/srcs
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Sat Jul  4 01:59:36 2015 martin Arnholz
** Last update Wed May 25 11:55:23 2016 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
#include "my.h"

void	ex_opt1(t_list *list ,char *str)
{
  if (str != NULL)
    print_0(list);
}

void	print_file(t_list *list)
{
  t_elem *elem;
  int	fd;
  char  *str;
  
  elem = list->first;
  fd = open(elem->path, O_RDONLY);
  while ((str = get_next_line(fd)) != NULL)
    printf("%s\n", str);
}

void	ex_opt2(t_list *list , char *str)
{
  struct tm	*tb;
  t_elem	*elem;

  if (str == NULL)
    return;
  elem = list->first;
  while (elem != NULL)
    {
      if (strcmp(elem->forename ,str) == 0)
	{
	  printf("%s %s\n", elem->forename, elem->lastname);
	  tb = localtime(&elem->info.st_mtime);
	  printf("né le %d ", tb->tm_mday);
	  month(tb->tm_mon);
	  printf("%d ", (tb->tm_year + 1900));
	  printf("(%02d)\n", (stat_size(elem->path) % 100));
	  if (stat_right(elem->path) == 1)
	    printf("de sexe féminin \n");
	  else if (stat_right(elem->path) == 0)
	    printf("de sexe masculin \n");
	  printf("%d %02d", stat_right(elem->path), (tb->tm_year + 1900) % 100);
	  printf("%02d %02d ", tb->tm_mon+1, (stat_size(elem->path) % 100));
	  printf("%02d\n", stat_inode(elem->path) % 1000000);
	  print_file(list);
	}
      elem = elem->next;
    }
}
