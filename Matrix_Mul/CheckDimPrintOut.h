
void PrintfArray(float *array, int width, int column)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < column; j++)
		{
			int temp = i * column + j;
			printf("  %f", array[temp]);
		}
		printf("\n");
	}
	printf("\n");
}

void CheckDim(int width_a, int column_a, int width_b, int column_b, int width_c, int column_c)
{
	if (column_a != width_b)
	{
		printf("column of a is %d and width of b is %d. They are not equal!", column_a, width_b);
		exit(0);
	}
		
	if (width_a != width_c)
	{
		printf("width of a is %d and width of c is %d. They are not equal!", width_a, width_c);
		exit(0);
	}
		
	if (column_b != column_c)
	{
		printf("column of b is %d and column of c is %d. They are not equal!", column_b, column_c);
		exit(0);
	}
}