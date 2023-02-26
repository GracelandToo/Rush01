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
#include "ft_verify_solution.c"

int main(void)
{
	int parameters[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	int comb[4][4] = {
    {1, 2, 3, 4},
    {2, 3, 4, 1},
	{3, 4, 1, 2},
	{4, 1, 2, 3}
	};

	printf("%i",ft_verify_solvability(parameters, 0));
	printf("%i", ft_verify_rows(comb));
	printf("%i", ft_verify_columns(comb));
	printf("%i", ft_verify_solution(comb, parameters));
	ft_print_comb(comb);
}
