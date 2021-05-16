/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_ls.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 05:56:54 by rishimot          #+#    #+#             */
/*   Updated: 2020/12/04 23:40:02 by rishimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINI_LS_H
# define FT_MINI_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

typedef struct		s_content
{
	char			*name;
	struct timespec	time;
	int				size;
}					t_file_info;

typedef struct		s_options
{
	int				s;
}					t_options;

int					filesize_cmp(t_list *lst, t_file_info *nf);
int					filetime_cmp(t_list *lst, t_file_info *nf);

#endif
