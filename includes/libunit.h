#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include "../libft/libft.h"
# include "colors.h"
# define LU_KO -1
# define LU_OK 0
# define LU_SEGV 1
# define LU_BUS 2

typedef struct s_test
{
    char *name;
    int (*func)(void);
    struct s_test *next;
} t_test;

void load_test(t_test **list, char *name, int (*f)(void));
int launch_tests(t_test **list, char *func_name);
void clear_tests(t_test **list);

void print_header(const char *title);
void print_result(const char *func_name, const char *test_name, int result);

void ft_write_colored(int fd, char *color, char *str);


int ft_strlen_launcher(void);
int ft_strlen_empty_test(void);
int ft_strlen_basic_test(void);

int ft_atoi_launcher(void);
int ft_atoi_basic_test(void);
int ft_atoi_negative_test(void);
int ft_atoi_zero_test(void);
int ft_atoi_whitespace_test(void);
int ft_atoi_sign_test(void);
int ft_atoi_mixed_test(void);
int ft_atoi_large_positive_test(void);
int ft_atoi_large_negative_test(void);
int ft_atoi_leading_zeros_test(void);
int ft_atoi_empty_string_test(void);

#endif