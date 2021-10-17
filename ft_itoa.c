/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:56:20 by gmorange          #+#    #+#             */
/*   Updated: 2021/10/17 12:19:37 by gmorange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_toitoa(unsigned int temp, unsigned int n, int sign)
{
	char *nbr;
	int j;

	j = 1;
	if (sign == -1)
		j++;
	while (temp >= 10)
	{
		temp = temp / 10;
		j++;
	}
	if (!(nbr = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	nbr[j] = '\0';
	j--;
	while (j >= 0)
	{
		nbr[j] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (nbr);
}

char		*ft_itoa(int n)
{
	int		sign;
	char	*nbr;

	sign = 0;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	if (!(nbr = ft_toitoa(n, n, sign)))
		return (NULL);
	if (sign == -1)
		nbr[0] = '-';
	return (nbr);
}
