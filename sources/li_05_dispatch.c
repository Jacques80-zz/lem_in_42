/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_05_dispatch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 05:32:01 by jdouniol          #+#    #+#             */
/*   Updated: 2019/02/25 20:22:53 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	remove_ant(t_ant **ant)
{
	t_ant		*tmp;
	t_ant		*tmp_ant;

	while (*ant && (*ant)->path->room->status == END)
	{
		tmp = (*ant)->next;
		free_path((*ant)->tmp_path);
		free(*ant);
		*ant = tmp;
		if (tmp)
			tmp->prev = NULL;
	}
	tmp_ant = *ant;
	while (tmp_ant && (tmp = tmp_ant->next) + 1)
	{
		if (tmp_ant->path->room->status == END)
		{
			tmp_ant->prev->next = tmp;
			if (tmp)
				tmp->prev = tmp_ant->prev;
			free_path(tmp_ant->tmp_path);
			free(tmp_ant);
		}
		tmp_ant = tmp;
	}
}

void	ft_color_ant(t_all *elem, t_ant *ant)
{
	while (ant)
	{
		ant->path = ant->path->next;
		if (ant->nb == elem->nb_ant_to_color)
		{
			ft_printf("\033[1;31m");
			ft_printf("L%d-%s", ant->nb, ant->path->room->name_room);
			ft_printf("\033[0m");
			ant->next ? ft_putchar(' ') : ft_putchar('\n');
			ant = ant->next;
		}
		else
		{
			ft_printf("L%d-%s", ant->nb, ant->path->room->name_room);
			ant->next ? ft_putchar(' ') : ft_putchar('\n');
			ant = ant->next;
		}
	}
}

void	move_ant_bis(t_ant **ptr_ant, t_all *elem)
{
	t_ant		*ant;
	static int	nb_line = 0;

	ant = *ptr_ant;
	if (elem->nb_ant_to_color >= 0)
		ft_color_ant(elem, ant);
	else
	{
		while (ant)
		{
			ant->path = ant->path->next;
			ft_printf("L%d-%s", ant->nb, ant->path->room->name_room);
			ant->next ? ft_putchar(' ') : ft_putchar('\n');
			ant = ant->next;
		}
	}
	nb_line++;
	remove_ant(ptr_ant);
	if (elem->show_line && !*ptr_ant)
		ft_printf("number lines = %d\n", nb_line);
}

void	ft_dispatch_short(t_all elem, t_path *path)
{
	t_ant		*ant;

	ant = NULL;
	while (elem.number_ants)
	{
		add_ant(&ant, elem.number_ants--, path);
		move_ant_bis(&ant, &elem);
	}
	while (ant)
		move_ant_bis(&ant, &elem);
}

void	ft_dispatch(t_all elem, t_tab_path *tab)
{
	t_ant		*ant;
	t_tab_path	*tmp;
	int			nb;
	int			ret;

	ant = NULL;
	if (path_size(elem.shortest_path) - 2 > elem.number_ants
		&& path_size(elem.shortest_path) < path_size(tab->path))
		return (ft_dispatch_short(elem, elem.shortest_path));
	while (elem.number_ants)
	{
		tmp = tab;
		nb = 1;
		while (tmp && elem.number_ants)
		{
			ret = ft_nb_path(elem, tab, 1, 0);
			if (nb <= ret)
				add_ant(&ant, elem.number_ants--, tmp->path);
			tmp = tmp->next;
			nb++;
		}
		move_ant_bis(&ant, &elem);
	}
	while (ant)
		move_ant_bis(&ant, &elem);
}
