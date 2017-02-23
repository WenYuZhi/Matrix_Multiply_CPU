
#include <stdlib.h>
#include <stdio.h>
#include "time.h"
#include"CheckDimPrintOut.h"

int main()
{
	struct MatrixSize {
		int width_a;
		int column_a;
		int width_b;
		int column_b;
		int width_c;
		int column_c;
	} MatrixSize = { 300, 300, 300, 200, 300, 200 };
	
	float *a, *b, *c;
	float Cvalue = 0.0;

	clock_t timestart = clock();
	CheckDim(MatrixSize.width_a, MatrixSize.column_a, MatrixSize.width_b, MatrixSize.column_b, MatrixSize.width_c, MatrixSize.column_c);
	a = (float*)malloc(MatrixSize.width_a * MatrixSize.column_a * sizeof(float));
	b = (float*)malloc(MatrixSize.width_b * MatrixSize.column_b * sizeof(float));
	c = (float*)malloc(MatrixSize.width_c * MatrixSize.column_c * sizeof(float));

	
	for (int i = 0; i < MatrixSize.width_a; i++)
		for (int j = 0; j < MatrixSize.column_a; j++)
			a[i * MatrixSize.column_a + j] = 1.0;

	for (int i = 0; i < MatrixSize.width_b; i++)
		for (int j = 0; j < MatrixSize.column_b; j++)
			b[i * MatrixSize.column_b + j] = 2.0;


	for (int i = 0; i < MatrixSize.width_c; i++)
		for (int j = 0; j < MatrixSize.column_c; j++)
		{
			Cvalue = 0.0;
				for (int k = 0; k < MatrixSize.column_a; k++)
				{
					Cvalue += a[i * MatrixSize.column_a + k] * b[k * MatrixSize.column_b + j];
				}
			c[i * MatrixSize.column_c + j] = Cvalue;
		}

	clock_t timeend = clock();

	//PrintfArray(a, MatrixSize.width_a, MatrixSize.column_a);
	//PrintfArray(b, MatrixSize.width_b, MatrixSize.column_b);
	PrintfArray(c, MatrixSize.width_c, MatrixSize.column_c);

	printf("running time = %ld(msecond)", timeend - timestart);
 
}

