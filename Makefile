##
## Makefile for  in /home/arnhol_m/rendu/synth/automakefile
## 
## Made by martin Arnholz
## Login   <arnhol_m@epitech.net>
## 
## Started on  Mon Jun 22 18:05:57 2015 martin Arnholz
## Last update Sat Jul  4 19:05:04 2015 martin Arnholz
##

CC	= gcc -g

CFLAGS	= -W -Wall -Wextra -I./include/

RM	= rm -f

NAME	= genealogie

SRC	= srcs/main.c \
	  srcs/list.c \
	  srcs/print_opt.c \
	  srcs/stat.c \
	  srcs/strtok.c \
	  srcs/get_next_line.c \
	  srcs/opt.c \
	  srcs/get_info.c \
	  srcs/to_hum.c

OBJS	= $(SRC:.c=.o)

all	: $(NAME)
	  @echo "$(NAME) \\033[1;36m COMPILATION FINISHED \\033[0;39m"

.c.o	:
	 @$(CC) $(CFLAGS) -c -o $@ $<
	 @echo " $(CC) $(CFLAGS) -c -o $@ $< \\033[1;32m OK \\033[0;39m"

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
	@$(RM) $(OBJS)
	@$(RM) *~
	@echo " $(RM) $(OBJS) \\033[1;31m DELETING \\033[0;39m"
	@echo " $(RM) *~ \\033[1;31m DELETING \\033[0;39m"

fclean	: clean
	@$(RM) $(NAME)
	@echo " $(RM) *~ \\033[1;31m DELETING \\033[0;39m"

re	: fclean all

.PHONY	: fclean all re
