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

/*me quedaba sin espacio por declarar variables
como solucion saqué dos de ellas y las puse como parametros.
Para ahorrar espacio estoy operando sobre ellas (++) desde la primera vez que
son visibles en el codigo, entonces las envio como uno menos que el valor que en realidad deseo*/
int ft_verify_solution(int comb[4][4], int parameters[16])
{
	if((ft_verify_top(comb, parameters, -1, -1)) && \
	(ft_verify_down(comb, parameters, 3, -1)) && \
	(ft_verify_left(comb, parameters, 7, -1)) && \
	(ft_verify_right(comb, parameters, 11, -1)))
	{
		return (1);
	}
	return (0);
}
