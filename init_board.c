/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:36:11 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/14 17:40:24 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>

#include "checker.h"

int	countwords(char *str)
{
	int words;
	int i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i]))
			i++;
		else if (is_digit(str[i]) && is_sep(str[i + 1]))
		{
			words++;
			i++;
		}
		else
			return (-1);
	}
	return (words);
}

int get_grid_size(char *str)
{
	int count;

	count = countwords(str);
	if (count % 4)
		return (-1);
	return (count / 4);
}

int set_views(t_board *board, char *str)
{
	int i;
	int count;


	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '0' + board->size)
		{
			board->view[count] = str[i] - 48;
			count++;
		}
		else if (str[i] != ' ')
			return (-1);
		i++;
	}
	i = 0;
	while (i < board->size * board->size)
	{
		board->grid[i] = 0;
		i++;
	}
	return (0);
}

int init_board(t_board *board, char *str)
{
	board->size = get_grid_size(str);
	if (board->size == -1) 
		return (-1);
	memset(board->grid, 0, sizeof(int) * MAX_GRID);
	memset(board->grid, 0, sizeof(int) * MAX_GRID * MAX_GRID);
	if (set_views(board, str))
		return (-1);
	return (0);
}

