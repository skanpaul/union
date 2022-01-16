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
void reset_mem(bool *memory);
void display_char(char *text, bool *memory);

/* ************************************************************************** */
int main(int argc, char **argv)
{
	bool memory[256];
	char *text;

	reset_mem(memory);
	if (argc == 3)
	{
		text = argv[1];
		display_char(text, memory);

		text = argv[2];
		display_char(text, memory);
	}
	write(1, "\n", 1);
}

/* ************************************************************************** */
void reset_mem(bool *memory)
{
	int i;

	i = 0;
	while (i < 256)
	{
		memory[i] = false;
		i++;
	}
}

/* ************************************************************************** */
void display_char(char *text, bool *memory)
{
	int i;

	i = 0;
	while (text[i] != '\0')
	{
		if (memory[(unsigned char)text[i]] == false)
		{
			memory[(unsigned char)text[i]] = true;
			write(1, &text[i], 1);
		}
		i++;
	}
}