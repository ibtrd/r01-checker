/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 01:23:48 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/14 21:42:39 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int up_view(t_board *board, int col, int size)
{
	const int	view = board->view[col];
	int			highest;
	int			visible;
	int			i;

	highest = 0;
	visible = 0;
	i = 0;
	while (i < size)
	{
		if (board->grid[i * size + col] > highest)
		{
			highest = board->grid[i * size + col];
			visible++;
		}
		i++;
	}
	if (visible > view)
		return (-1);
	return (visible == view);
}

int down_view(t_board *board, int col, int size)
{
	const int	view = board->view[col + size];
	int			highest;
	int			visible;
	int			i;

	highest = 0;
	visible = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (board->grid[i * size + col] > highest)
		{
			highest = board->grid[i * size + col];
			visible++;
		}
		i--;
	}
	if (visible > view)
		return (-1);
	return (visible == view);
}

int left_view(t_board *board, int row, int size)
{
	const int	view = board->view[row + (size * 2)];
	int 		highest;
	int 		visible;
	int 		i;

	highest = 0;
	visible = 0;
	i = 0;
	while (i < size)
	{
		if (board->grid[row * size + i] > highest)
		{
			highest = board->grid[row * size + i];
			visible++;
		}
		i++;
	}
	if (visible > view)
		return (-1);
	return (visible == view);
}

int right_view(t_board *board, int row, int size)
{
	const int	view = board->view[row + (size * 3)];
	int 		highest;
	int 		visible;
	int 		i;

	highest = 0;
	visible = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (board->grid[row * size + i] > highest)
		{
			highest = board->grid[row * size + i];
			visible++;
		}
		i--;
	}
	if (visible > view)
		return (-1);
	return (visible == view);
}

int	check_views(t_board *board)
{
	int i = 0;
	while (i < board->size)
	{
		if (up_view(board, i, board->size) != 1
			|| down_view(board, i, board->size) != 1
			|| left_view(board, i , board->size) != 1
			|| right_view(board, i , board->size) != 1)
		{
			printf("❌ \e[30;41;1m FAILURE \e[0m\n");
			return (1);
		}
		i++;
	}
	printf("\n");
	return (0);
}
