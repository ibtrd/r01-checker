/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:26:08 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/14 21:41:52 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define MAX_GRID 9

typedef struct s_board
{
	int		size;
	int		view[MAX_GRID * 4];
	int		grid[MAX_GRID * MAX_GRID];
}	t_board;

int	is_sep(char c);
int	is_digit(char c);
int	get_grid_size(char *str);
int	init_board(t_board *ptr, char *arg);

int	check_duplicates(t_board *board);
int	check_views(t_board *board);

#endif