/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_toolbox2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xueyan_wang <xueyan_wang@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 23:52:06 by xueyan_wang       #+#    #+#             */
/*   Updated: 2026/03/28 00:31:30 by xueyan_wang      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\n' || line[i] == '\r'))
		i++;
	return (line[i] == '\0');
}

int	is_map_line(char *line)
{
	char	*p;

	p = line;
	while (*p == ' ' || *p == '\t')
		p++;
	if ((*p == 'N' && *(p+1) == 'O') ||
		(*p == 'S' && *(p+1) == 'O') ||
		(*p == 'W' && *(p+1) == 'E') ||
		(*p == 'E' && *(p+1) == 'A') ||
		(*p == 'F' && *(p+1) == ' ') ||
		(*p == 'C' && *(p+1) == ' '))
		return (0);
	return (*p == '0' || *p == '1' || *p == 'N' || *p == 'S'
		|| *p == 'E' || *p == 'W' || *p == ' ');
}