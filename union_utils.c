/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:51:00 by ski               #+#    #+#             */
/*   Updated: 2022/01/16 10:51:03 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "union.h"

/* ************************************************************************** */
int ft_strlen(char *str)
{
	int pos;	
	if(!str)
		return (0);	
	pos = 0;
	while (str[pos] != '\0')
		pos++;
	return (pos);
}

/* ************************************************************************** */
bool is_char_used (char c, char *memory)
{
	int i;

	i = 0;
	while (memory[i] != '\0')
	{
		if (memory[i] == c)
			return (true);
		i++;
	}
	return (false);
}

/* ************************************************************************** */
char *update_memory(char c, char *old_mem)
{
	char *new_mem;
	int i;
	int len;

	len = ft_strlen(old_mem);
	new_mem = (char *)malloc((len + 2) * sizeof(char));
	if(!new_mem)
	 	return(old_mem);
	i = 0;
	while (i < len)
	{
		new_mem[i] = old_mem[i];
		i++;
	}
	new_mem[i] = c;
	new_mem[i + 1] = '\0';
	if (old_mem != NULL)
		free (old_mem);
	return (new_mem);
}