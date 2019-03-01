/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_09e_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdouniol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:31:18 by jdouniol          #+#    #+#             */
/*   Updated: 2019/02/28 18:31:20 by jdouniol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_bonus_usage(char *av, int error)
{
	if (error == NOT_A_VALID_BONUS)
		ft_printf("ERROR USAGE, please put a valid bonus -a & uint or/and -l\
			& nothing or/and -m & nothing & uint<=nb_lem [%s]\n", av);
	if (error == ERROR_ANT_IS_NOT_A_NUMBER)
		ft_printf("ERROR USAGE, please put an unsigned integer [%s]\n", av);
	if (error == ERROR_IS_NOT_A_POSITIVE_INTEGER)
		ft_printf("ERROR USAGE, please put an unsigned integer [%s]\n", av);
	if (error == ERROR_IS_NOT_A_VALID_FILE)
		ft_printf("ERROR USAGE, please put a valid file (nb_lem/rooms/pipe)\
			[%s]\n", av);
	if (error == ERROR_IS_NOT_A_VALID_LEM)
		ft_printf("ERROR USAGE, please put a valid ant number [%s]\n", av);
	return ;
}

int		ft_bonus_ants(char *av, t_all *elem)
{
	int			new_nb_ants;
	long long	tmp;

	if (av)
	{
		if (ft_str_is_number(av))
		{
			tmp = ft_atoll(av);
			if (tmp >= 1 && tmp < INT_MAX)
			{
				new_nb_ants = ft_atoi(av);
				elem->number_ants = new_nb_ants;
			}
			else
				ft_bonus_usage(av, ERROR_IS_NOT_A_POSITIVE_INTEGER);
		}
		else
			ft_bonus_usage(av, ERROR_ANT_IS_NOT_A_NUMBER);
	}
	else
		ft_bonus_usage(av, ERROR_ANT_IS_NOT_A_NUMBER);
	return (1);
}

int		ft_bonus_line(t_all *elem)
{
	elem->show_line = 1;
	return (1);
}

int		ft_bonus_color(char *av, t_all *elem)
{
	int			nb_ant_to_color;
	long long	tmp;

	if (av)
	{
		if (ft_str_is_number(av))
		{
			tmp = ft_atoll(av);
			if (tmp >= 1 && tmp <= elem->number_ants)
			{
				nb_ant_to_color = ft_atoi(av);
				elem->nb_ant_to_color = nb_ant_to_color;
			}
			else
				ft_bonus_usage(av, ERROR_IS_NOT_A_VALID_LEM);
		}
		else
			ft_bonus_usage(av, ERROR_IS_NOT_A_POSITIVE_INTEGER);
	}
	return (1);
}

void	ft_bonus(int ac, char **av, t_all *elem)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-a") == 0)
			i++ && ft_bonus_ants(av[i], elem);
		else if (ft_strcmp(av[i], "-l") == 0)
			ft_bonus_line(elem);
		else if (ft_strcmp(av[i], "-c") == 0)
			i++ && ft_bonus_color(av[i], elem);
		else if (ft_strcmp(av[i], "-m") == 0 && elem->number_rooms < 20)
			ft_print_matrice(elem);
		else
		{
			ft_bonus_usage(av[i], NOT_A_VALID_BONUS);
		}
	}
	return ;
}
