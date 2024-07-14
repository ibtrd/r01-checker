/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 02:24:01 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/14 21:41:43 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	duplicate_check(int *grid, int x, int y, int size)
{
	const int	cell = grid[y * size + x];
	int			i;

	i = 0;
	while (i < x)
	{
		if (cell == grid[y * size + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < y)
	{
		if (cell == grid[i * size + x])
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_board *board)
{
	int	y = 0;

	while (y < board->size)
	{
		int x = 0;
		while (x < board->size)
		{
			if (!duplicate_check(board->grid, x, y, board->size))
			{
				printf("❌ \e[30;41;1m FAILURE \e[0m\n");
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}