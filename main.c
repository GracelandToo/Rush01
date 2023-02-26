/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:10:37 by dsilva-g          #+#    #+#             */
/*   Updated: 2023/02/25 23:15:24 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_verify.c"
#include "ft_print_2d.c"


int ft_verify_top(int comb[4][4], int parameters[16], int i, int j)
{
	int row;
	int height;
	int visible;
	
	while (++i < 4)
	{
		row = 0;
		visible = 1;
		height = comb[0][++j];
		while (++row <= 3)
		{
			if(comb[row][j] > height)
			{
				height = comb[row][j];
				visible++;
			}
		}
		if(visible < parameters[i])
			return 0;
	}
	return (1);
}

int ft_verify_down(int comb[4][4], int parameters[16], int i, int col)
{
	int row;
	int height;
	int visible;
	
	while (++i < 8)
	{
		row = 4;
		visible = 1;
		height = comb[3][++col];
		while (--row >= 0)
		{
			if(comb[row][col] > height)
			{
				height = comb[row][col];
				visible++;
			}
		}
		if(visible < parameters[i])
			return 0;
	}
	return (1);
}

int ft_verify_left(int comb[4][4], int parameters[16], int i, int row)
{
	int column;
	int height;
	int visible;
	
	while (++i < 12)
	{
		column = 0;
		visible = 1;
		height = comb[++row][0];
		while (++column <= 3)
		{
			if(comb[row][column] > height)
			{
				height = comb[row][column];
				visible++;
			}
		}
		if(visible < parameters[i])
			return 0;
	}
	return (1);
}

int ft_verify_right(int comb[4][4], int parameters[16], int i, int row)
{
	int column;
	int height;
	int visible;
	
	while (++i < 16)
	{
		column = 4;
		visible = 1;
		height = comb[++row][3];
		while (--column >= 0)
		{
			if(comb[row][column] > height)
			{
				height = comb[row][column];
				visible++;
			}
		}
		if(visible < parameters[i])
			return 0;
	}
	return (1);
}

int main(void)
{
	int parameters[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	int comb[4][4] = {
    {1, 2, 3, 4},
    {2, 3, 4, 1},
	{3, 4, 1, 2},
	{4, 1, 2, 3}
	};

	ft_verify_solvability(parameters);
	printf("%i", ft_verify_rows(comb));
	printf("%i", ft_verify_columns(comb));
	ft_print_comb(comb);

	//me quedaba sin espacio por declarar variables
	//como solucion saqué dos de ellas y las puse como parametros
	//como para ahorrar espacio estoy operando desde la primera vez que
	//son visibles en el codigo, las envio como uno menos que el valor que deseo
	printf("\n%i", ft_verify_top(comb, parameters, -1, -1));
	printf("\n%i", ft_verify_down(comb, parameters, 3, -1));
	printf("\n%i", ft_verify_left(comb, parameters, 7, -1));
	printf("\n%i", ft_verify_right(comb, parameters, 11, -1));

}