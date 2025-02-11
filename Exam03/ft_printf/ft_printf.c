
# include <unistd.h>
# include <stdarg.h>


int	ft_reverse_str(char *str_digit, int len_digit)
{
	int	size = 0;

	while (--len_digit >= 0)
		size += write(1, &str_digit[len_digit], 1);
	return (size);
}

int	ft_write_str(char *str)
{
	int	size = 0;

	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
		size += write(1, str++, 1);
	return (size);
}

int	ft_write_nbr(int num)
{
	char	digits[32];
	int idx = 0;
	int size = 0;

	if (!num)
		return (write(1, "0", 1));
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		num *= -1;
		size += write(1, "-", 1);
	}
	while (num > 0)
	{
		digits[idx++] = (num % 10) + '0';
		num = num / 10;
	}
	return (ft_reverse_str(digits, idx) + size);
}

int	ft_write_hexa(unsigned int num, char type)
{
	char	hex_digits[32];
    int     size = 0;

	if (!num)
		return (write(1, "0", 1));
	int idx = 0;
	int left = 0;
	while (num > 0)
	{
		hex_digits[idx++] = "0123456789abcdef"[num % 16];
		num = num / 16;
	}
	return (ft_reverse_str(hex_digits, idx));
}

int	ft_printf(const char *str, ...)
{
	int		size = 0;
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		if ((*str == '%') && ((*(str + 1) == 's') || (*(str + 1) == 'd') || (*(str + 1) == 'x')))
        {
            str++;
            if (*str == 's')
                size += ft_write_str(va_arg(args, char *));
            else if (*str == 'd')
                size += ft_write_nbr(va_arg(args, int));
            else if (*str == 'x')
                size += ft_write_hexa(va_arg(args, unsigned int), *str);   
        }
		else
			size += write(1, str, 1);
		str++;
	}
	return (va_end(args), size);
}

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {   
//     int res1 = ft_printf("my name is %s and Hexadecimal for %d is %x and max %d\n", "abdullah", 0, 42, -2147483648);
//     int res2 = printf("my name is %s and Hexadecimal for %d is %x and max %ld\n", "abdullah", 0, 42, -2147483648);
//     printf("%d\n", res1);
//     printf("%d\n", res2);
// }
