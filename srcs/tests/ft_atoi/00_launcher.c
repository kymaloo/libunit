#include "../../../includes/libunit.h"

int ft_atoi_launcher(void)
{
    t_test *tests = NULL;

    load_test(&tests, "Basic atoi test", &ft_atoi_basic_test);
    load_test(&tests, "Negative number test", &ft_atoi_negative_test);
    load_test(&tests, "Zero test", &ft_atoi_zero_test);
    load_test(&tests, "Whitespace test", &ft_atoi_whitespace_test);
    load_test(&tests, "Sign test", &ft_atoi_sign_test);
    load_test(&tests, "Mixed alphanumeric test", &ft_atoi_mixed_test);
    load_test(&tests, "Large positive number", &ft_atoi_large_positive_test);
    load_test(&tests, "Large negative number", &ft_atoi_large_negative_test);
    load_test(&tests, "Leading zeros", &ft_atoi_leading_zeros_test);
    load_test(&tests, "Empty string", &ft_atoi_empty_string_test);

    int result = launch_tests(&tests, "ft_atoi");

    clear_tests(&tests);
    return result;
}
