#include <unistd.h>
#include <stdio.h>

#define SIZE 16

void	ft_init_comb(int comb[16]);
int		ft_next_comb(int comb[16]);
void	ft_putchar(char c);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//simple print function for the whole grid
void	ft_print_comb(int comb[SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(comb[4 * i + j] + 48);
			if (j < 4)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int main(int argc, char **argv)
{
	int i = 0;
	int changed = 1;
	int comb[SIZE];

	ft_init_comb(comb);
	ft_print_comb(comb);
	
	/* This benchmarks how long all permutations take
	while(changed)
	{
		changed = ft_next_comb(comb);
		i++;
		if (i % 1000000 == 0)
		{
			printf("%d", i);
			printf("\n");
			//ft_print_comb(comb);


		}

		//printf("\n");
	}
	*/

}