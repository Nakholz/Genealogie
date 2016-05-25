/*
** my.h in /home/nakholz/rendu/Github/genealogie
** 
** Made by Arnholz Martin
** Login : arnhol_m
** 
** Started on  Sat Jul  4 10:45:22 2015 martin Arnholz
** Last update Wed May 25 11:56:58 2016 
*/

#ifndef MY_H_
#define MY_H_

#include <sys/stat.h>

typedef struct s_elem
{
  char		*name;
  char		*path;
  char		*forename;
  char		*lastname;
  int		time;
  struct	stat info;
  struct	s_elem *next;
  struct	s_elem *previous;
}	t_elem;

typedef struct s_list
{
  struct	s_elem *first;
  struct	s_elem *last;
}	t_list;

t_list  *init_list();
int     add_elem(t_list **list, int nb);
void	print_list(t_list *list);
void	free_list(t_list *list);
int	add_str(t_list **list, char *forename, char *save);
char	*my_strdup(char *str);
int	my_strlen(char *str);
char    *get_next_line(const int fd);
char	*att_bal(char *str);
int	check_double(t_list *list ,char *str);
int	is_alpha(char c);
char	*get_att(char *str);
int	o_this(t_list *list);
int	r_fasta();
int	r_ufasta();
int	r_revfasta();
char	*c_create(char *str);
char	*get_next_line(const int fd);
void    print_2(t_list *list);
void    print_3(t_list *list);
void    print_4(t_list *list ,int k);
int     add_seq(t_list **list, char *str);
int     check_seq(t_list *list ,char *str);
void    m_seq(t_list *list ,int k);
int     size_tab(char *path);
int     n_swap(char *str1, char *str2);
char    **alph(char **tab);
char    **my_files_synthese(char *path);
void	dir_tolist(t_list *list, char *repo);
int	stat_lchange(char *path);
int     my_revlist(t_elem **begin);
char    **my_str_to_wordtab(char *str ,char sep);
int     stat_lchange(char *path);
int     sup(int va1, int va2);
void    croi_list(t_list *list);
void	print_0(t_list *list);
void    ex_opt1(t_list *list ,char *str);
void    ex_opt2(t_list *list ,char *str);
char    *get_name(char *lastname);
char	*get_date();
void	month(int month);
int	stat_size(char *path);
int     stat_right(char *path);
int     stat_inode(char *path);

#endif
