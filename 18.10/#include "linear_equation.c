#include "linear_equation.h"
#include <stdio.h>

double linear_equation(double *radioactivity, double *time, int N)
{
	double TimeSum = 0;
	double RadioactivityTimeSum = 0;

	for (int i = 0; i < N; i++)
	{
		TimeSum += (time[i] * time[i]);
		RadioactivityTimeSum += (time[i] * (1.0 - radioactivity[i]));
	}

	return (TimeSum / RadioactivityTimeSum);
}