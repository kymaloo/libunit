#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
#include <sys/wait.h>
# include "../libft/libft.h"
# include "colors.h"
# define LU_OK 0
# define LU_KO 1
# define LU_SEGV 2
# define LU_BUS 3

typedef struct s_test
{
    char *name;
    int (*func)(void);
    struct s_test *next;
} t_test;

void load_test(t_test **list, char *name, int (*f)(void));
int launch_tests(t_test **list);
void clear_tests(t_test **list);

void print_header(const char *title);
void print_result(const char *func_name, const char *test_name, int result);



int ft_strlen_launcher(void);
int empty_test(void);
int basic_test(void);

#endif