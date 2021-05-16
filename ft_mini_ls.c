/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:24:31 by rishimot          #+#    #+#             */
/*   Updated: 2020/12/04 23:39:45 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mini_ls.h"

static void				put_list(t_list *lst)
{
	t_list *tmp;

	while (lst->next != NULL)
	{
		ft_putstr_fd(((t_file_info *)lst->content)->name, 1);
		write(1, &"\n", 1);
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
	free(lst);
}

static t_list			*store_string(t_list *lst, t_file_info *nf,\
	t_options option)
{
	t_list		*new;
	t_list		*top;
	t_list		*pre;

	top = lst;
	pre = lst;
	new = ft_lstnew(nf);
	while (lst->next != NULL)
	{
		if (option.s && filesize_cmp(lst, nf) > 0)
			break ;
		else if (!option.s && filetime_cmp(lst, nf) > 0)
			break ;
		pre = lst;
		lst = lst->next;
	}
	if (lst == top)
	{
		new->next = lst;
		return (new);
	}
	new->next = pre->next;
	pre->next = new;
	return (top);
}

static t_list			*list_dir(t_list *lst, DIR *dir, t_options option)
{
	t_file_info		*new_file;
	struct dirent	*dp;
	struct stat		stat_buf;

	while ((dp = readdir(dir)) != NULL)
	{
		if (dp->d_name[0] == '.')
			continue ;
		if ((new_file = (t_file_info *)malloc(sizeof(t_file_info))) == NULL)
			break ;
		new_file->name = dp->d_name;
		if (stat(new_file->name, &stat_buf) == 0)
		{
			new_file->time = stat_buf.st_mtimespec;
			new_file->size = stat_buf.st_size;
		}
		lst = store_string(lst, new_file, option);
	}
	closedir(dir);
	return (lst);
}

int						main(int argc, char **argv)
{
	t_list		*lst;
	DIR			*dir;
	t_options	option;

	option.s = 0;
	if (argc == 2)
		if (ft_memcmp(argv[1], "-S", 2) == 0)
			option.s = 1;
	if (argc >= 3)
	{
		write(2, "too argument\n", 13);
		return (1);
	}
	if ((dir = opendir(".")) == NULL)
	{
		perror("open dir error");
		return (1);
	}
	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (0);
	lst->next = NULL;
	lst = list_dir(lst, dir, option);
	put_list(lst);
	return (0);
}
