#include "../includes/libunit.h"

int main(void)
{
	int result;

    result = 0;
    result += ft_strlen_launcher();
    if (result != 0)
        return (-1);
    return (0);
}
