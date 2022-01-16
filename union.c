/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:32:15 by ski               #+#    #+#             */
/*   Updated: 2022/01/16 10:32:17 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "union.h"

/* ************************************************************************** */
static void display(char *text, char *memory);

/* ************************************************************************** */
int main(int argc, char **argv)
{
	char *text1;
	char *text2;
	char *memory;

	if ((argc == 1) || (argc > 3))
	{
		write(1, "/n", 1);
		return (-1);
	}

	text1 = argv[1];
	text2 = argv[2];

	memory = (char *)malloc(1 * sizeof(char));
	if (!memory)
		return (-1);
	memory[0] = '\0';

	display(text1, memory);
	display(text2, memory);

	write(1, "\n", 1);

	if (memory != NULL)
		free(memory);
	return (0);
}

/* ************************************************************************** */
static void display(char *text, char *memory)
{
	int i;

	i = 0;
	while (text[i] != '\0')
	{
		if (!is_char_used(text[i], memory))
		{
			write(1, &text[i], 1);
			memory = update_memory(text[i], memory);
		}
		i++;
	}
}