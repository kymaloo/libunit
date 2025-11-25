#include "../includes/libunit.h"
#include <stdio.h>

void load_test(t_test **list, char *name, int (*f)(void))
{
    t_test *node;
    node = (t_test *)malloc(sizeof(t_test));
    if (!node)
        return ;
    node->name = name;
    node->func = f;
    node->next = NULL;
    if (!*list)
        *list = node;
    else
    {
        t_test *it = *list;
        while (it->next)
            it = it->next;
        it->next = node;
    }
}

void clear_tests(t_test **list)
{
    t_test *it;
    t_test *tmp;
    if (!list || !*list)
        return ;
    it = *list;
    while (it)
    {
        tmp = it->next;
        free(it);
        it = tmp;
    }
    *list = NULL;
}

void print_header(const char *title)
{
    if (!title)
        title = "TESTS";
    ft_write_colored(1, (char *)LU_BOLD LU_BLUE, "=== ");
    ft_write_colored(1, (char *)LU_BOLD LU_BLUE, (char *)title);
    ft_write_colored(1, (char *)LU_BOLD LU_BLUE, " ===");
    write(1, "\n", 1);
}

void print_result(const char *func_name, const char *test_name, int result)
{
    const char *status;
    const char *col;

    if (result == LU_OK)
        status = "OK", col = LU_GREEN;
    else if (result == LU_KO)
        status = "KO", col = LU_RED;
    else if (result == LU_SEGV)
        status = "SIGSEGV", col = LU_RED;
    else if (result == LU_BUS)
        status = "SIGBUS", col = LU_RED;
    write(1, (char *)func_name, ft_strlen(func_name));
    write(1, ":", 1);
    write(1, (char *)test_name, ft_strlen(test_name));
    write(1, ":", 1);
    ft_write_colored(1, (char *)col, (char *)status);
    write(1, "\n", 1);
}

int launch_tests(t_test **list, char *func_name)
{
    t_test *tmp;
    int total;
    int passed;
    int result;

    total = 0;
    passed = 0;
    tmp = *list;
    if (!tmp)
        return (0);
    print_header(func_name);
    while (tmp)
    {
        total++;
        result = tmp->func();
        print_result(func_name, tmp->name, result);
        if (result == LU_OK)
            passed++;
        tmp = tmp->next;
    }
    if (passed != total)
        return (-1);
    return (0);
}

void ft_write_colored(int fd, char *color, char *str)
{
    write(fd, color, ft_strlen(color));
    write(fd, str, ft_strlen(str));
    write(fd, LU_RESET, ft_strlen(LU_RESET));
}
