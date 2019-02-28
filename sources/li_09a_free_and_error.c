/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_09a_free_and_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 05:32:29 by jdouniol          #+#    #+#             */
/*   Updated: 2019/02/28 17:46:46 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_error_tube(char ***tab_tube)
{
	int		i;

	i = -1;
	while ((*tab_tube)[++i])
		free((*tab_tube)[i]);
	ft_free_them(1, *tab_tube);
	return (ERROR);
}

void	ft_error(int nb)
{
	if (nb == 42)
		exit(1);
	if (nb)
	{
		write(STDERR_FILENO, "ERROR\n", 6);
		exit(1);
	}
}

void	free_room(t_room *room)
{
	t_room	*tmp;

	while (room)
	{
		tmp = room->next;
		free(room->name_room);
		free(room->tab);
		free(room);
		room = tmp;
	}
}

void	free_bfs(t_files *tmp)
{
	free_path(tmp->path);
	free(tmp);
}

<<<<<<< HEAD
int		ft_multi_dash(char *line)
=======
int		ft_multi_dash(char * line)
>>>>>>> 837f308956c6b4a1b4e6f5c67323fdaf0c0ff64d
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i++])
		if (line[i] == '-')
			count++;
	return (count);
}
