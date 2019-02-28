/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fallouch <fallouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:09:32 by fallouch          #+#    #+#             */
/*   Updated: 2019/02/28 17:50:25 by fallouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_bonus(t_bonus *bonus, int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-a") && ft_printf("ICI") && av[i + 1])
		{
			if ((bonus->tracked_ant = ft_atoll(av[i + 1])) < 0)
			{
				ft_printf("Error: Bad Ant Number\n");
				return (0);
			}
		}
		else if (ft_strcmp(av[i], "-l"))
			bonus->print_lines = 1;
		else
		{
			ft_printf("UNKNOWN OPTIONS\nusage:\n\t-a N\t: Color ant N\n\t \
				-l\t: Print number of output lines");
			return (0);
		}
		i++;
	}
	return (1);
}
