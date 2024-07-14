/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibertran <ibertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:27:25 by ibertran          #+#    #+#             */
/*   Updated: 2024/07/14 22:56:47 by ibertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>

#include "checker.h"

int read_input(t_board *board)
{
	char	*input;
	int		count = 0;

	input = readline(NULL);
	if (!strcmp(input, "Error"))
		return (2);
	while (input)
	{
		int	i = 0;

		if (count == board->size * board->size)
			return (-1);
		while (input[i])
		{
			if (i % 2 == 0)
			{
				if (input[i] < '1' || input[i] > ('0' + board->size))
					return (-1);
				board->grid[count] = input[i] - 48;
				count++;
			}
			else if (input[i] != ' ')
				return (-1);
			i++;
		}
		if (count % board->size)
			return (-1);
		free(input);
		input = readline(NULL);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_board	board;

	if (ac != 2 || init_board(&board, av[1]))
	{
		dprintf(STDERR_FILENO, "checker: Error: invalid argument\n");
		return (2);
	}
	int status = read_input(&board);
	if (status == -1)
	{
		dprintf(STDERR_FILENO, "checker: Error: invalid input\n");
		return (2);
	}
	else if (status)
		return (2);
	return (check_duplicates(&board) || check_views(&board));
}
