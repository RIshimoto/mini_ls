/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileinfo_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:43:53 by rishimot          #+#    #+#             */
/*   Updated: 2020/12/04 23:43:55 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_mini_ls.h"

int				filetime_cmp(t_list *lst, t_file_info *nf)
{
	int				len;
	t_file_info		*of;

	len = ft_strlen(nf->name);
	of = (t_file_info*)lst->content;
	if (of->time.tv_sec > nf->time.tv_sec)
		return (1);
	else if (of->time.tv_sec == nf->time.tv_sec)
	{
		if (of->time.tv_nsec > nf->time.tv_nsec)
			return (1);
		else if (of->time.tv_nsec == nf->time.tv_nsec)
			if (ft_strncmp(nf->name, of->name, len) >= 0)
				return (1);
	}
	return (0);
}

int				filesize_cmp(t_list *lst, t_file_info *nf)
{
	int				len;
	t_file_info		*of;

	len = ft_strlen(nf->name);
	of = (t_file_info*)lst->content;
	if (of->size > nf->size)
		return (1);
	else if (of->size == nf->size)
	{
		if (ft_strncmp(nf->name, of->name, len) >= 0)
			return (1);
	}
	return (0);
}
