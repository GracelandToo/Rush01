/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsilva-g <dsilva-g@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:10:37 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/02/25 22:30:54 by dsilva-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

void ft_print_error(char *error_msg)
{
	write(2, "ERROR: ", 7);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
}

int main(int argc, char **argv)
{
	int		index;
	int		index_i;
	int		input[16];
	int		error;
	int		rest_length;
	char	*str_rest;
	int 	loop;

	index = 0;
	index_i = 0;
	error = 0;
	str_rest = argv[1];
	rest_length = ft_strlen(str_rest);
	printf("longitud string rest %d\n", rest_length);
	printf("contenido string rest %s\n", str_rest);
	if (argc != 2)
		error = 1;
	while ((error == 0) && (index < rest_length) && (str_rest[index] != '\0')) 
	{
		if (str_rest[index] == ' ')
			index++;
		else if ((str_rest[index] < '1') || (str_rest[index] > '4' ))
			error = 2;
		else if ((str_rest[index + 1] != ' ') && (str_rest[index + 1] != '\0'))
			error = 3;
		else
		{
			input[index_i] = (str_rest[index] - 48);
			// printf("%d-", input[index_i]);
			index++;
			index_i++;
		}
	}

	//printf("\n%d\n", index);
	printf("Contenido de array -> input: ");
	for (loop = 0; loop < 16; loop++)
		printf("%d", input[loop]);
	
	if (error == 1)
	{
		ft_print_error("Only 1 argument required\n");
	}
	else if (error == 2)
	{
		ft_print_error("Incorrect value: Out of range, only number from 1 to 4 admited.\n");
	}
	else if (error == 3)
	{
		ft_print_error("Incorrect value: Too many or few digits, only 1 digit.\n");
	}
	else if (index_i < 15)
	{
		//error = 4;
		ft_print_error("Too few values, 16 required\n");
	}
	else if	(index_i > 16)
	{
		//error = 5;
		ft_print_error("Too many values, 16 required\n");
	}

	// acá verify y generación de combinanciones
}
