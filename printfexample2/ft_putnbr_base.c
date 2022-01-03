/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserwyn <sserwyn@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:04:49 by sserwyn           #+#    #+#             */
/*   Updated: 2021/11/24 14:17:27 by sserwyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	count_16_in_nbr(unsigned int p);

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

static void	print_result(int clz, char *base, long int in_base, long int nbr)
{
	int	i;
	int	is_first_zero;

	is_first_zero = 1;
	while (nbr != 0)
	{
		in_base = in_base * ft_strlen(base) + nbr % ft_strlen(base);
		if (nbr % ft_strlen(base) == 0 && is_first_zero)
			clz++;
		if (is_first_zero && nbr % ft_strlen(base) != 0)
			is_first_zero = 0;
		nbr /= ft_strlen(base);
	}
	while (in_base != 0)
	{
		write(1, &base[in_base % ft_strlen(base)], 1);
		in_base /= ft_strlen(base);
	}
	i = 0;
	while (i < clz)
	{
		write(1, &base[0], 1);
		i++;
	}
}

static int	plus_minus_check(char a, char b)
{
	return (a == b || a == '+' || b == '+' || a == '-' || b == '-');
}

static int	not_invalid_argument(char *base, int base_size)
{
	int	i;
	int	j;
	int	is_good;

	is_good = 1;
	if ((base_size == 10 || base_size == 2) && base_size > 1)
		is_good = 1;
	else if (base_size == 16 || base_size == 8)
		is_good = 1;
	else
		return (0);
	i = 0;
	while (i < base_size - 1)
	{
		j = i + 1;
		while (j < base_size)
		{
			if (plus_minus_check(base[i], base[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (is_good);
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *count_symbols)
{
	long int	in_base;
	int			count_leading_zeros;
	long int	long_nbr;

	long_nbr = nbr;
	count_leading_zeros = 0;
	in_base = 0;
	if (!not_invalid_argument(base, ft_strlen(base)))
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		(*count_symbols)++;
		return ;
	}
	if (long_nbr < 0)
	{
		write(1, "-", 1);
		(*count_symbols)++;
		long_nbr *= -1;
	}
	print_result(count_leading_zeros, base, in_base, long_nbr);
	*count_symbols += count_16_in_nbr(nbr);
}
