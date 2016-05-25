/*
** to_hum.c for  in /home/arnhol_m/rendu/synth/genealogie/srcs
** 
** Made by martin Arnholz
** Login   <arnhol_m@epitech.net>
** 
** Started on  Sat Jul  4 18:39:54 2015 martin Arnholz
** Last update Sat Jul  4 20:51:21 2015 martin Arnholz
*/

#include <stdio.h>

void	month(int month)
{
if (month == 0)
  printf("janvier ");
 else if (month == 1)
   printf("février ");
 else if (month == 2)
  printf("mars ");
 else if (month == 3)
  printf("avril ");
 else if (month == 4)
  printf("mai ");
 else if (month == 5)
  printf("juin ");
 else if (month == 6)
  printf("juillet ");
 else if (month == 7)
  printf("aôut ");
 else if (month == 8)
  printf("septembre ");
 else if (month == 9)
  printf("octobre ");
 else if (month == 10)
  printf("novembre ");
 else if (month == 11)
  printf("décembre ");
}
