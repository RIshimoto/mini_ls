/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:57:30 by rishimot          #+#    #+#             */
/*   Updated: 2020/07/11 20:49:24 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isspace(const char *s)
{
	size_t	i;

	i = 0;
	while ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n') ||\
			(s[i] == '\v') || (s[i] == '\r') || (s[i] == '\f'))
		i++;
	return (i);
}

int				ft_atoi(const char *nptr)
{
	long int	num;
	size_t		i;
	int			minus;

	i = ft_isspace(nptr);
	minus = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	num = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * minus);
}
