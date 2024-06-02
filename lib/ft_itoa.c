/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meserghi <meserghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:12:06 by meserghi          #+#    #+#             */
/*   Updated: 2024/04/30 10:13:10 by meserghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	len_res(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		nb = -n;
		i++;
	}
	else
		nb = n;
	if (n == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*get_res(char *res, int len, unsigned int nb)
{
	while (nb > 0)
	{
		res[--len] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int				len;
	int				end;
	char			*res;
	unsigned int	nb;

	len = len_res(n);
	end = len;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = 48;
	if (n < 0)
	{
		res[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	res = get_res(res, len, nb);
	res[end] = '\0';
	return (res);
}
