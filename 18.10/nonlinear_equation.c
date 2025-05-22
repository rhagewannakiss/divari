#include  <stdio.h>
#include <stdlib.h>
#include   <math.h>

#include "nonlinear_equation.h"

static double equation_1(double* radioactivity, double* time, int N, double decay_time);


double nonlinear_equation(double* radioactivity, double* time, int N, double precision) {

    double interval_1 = 0.2;
    double interval_2 = 8.2;
    double decay_time = 0;

    while (fabs(interval_2 - interval_1) > 2*precision) {

        decay_time = (interval_1 + interval_2) / 2;

        double sum_interval_1 = equation_1(radioactivity, time, N, interval_1);
        double sum_interval_2 = equation_1(radioactivity, time, N, interval_2);
        double sum_decay_time = equation_1(radioactivity, time, N, decay_time);

        if (sum_interval_1 * sum_decay_time < 0) {
            interval_2 = decay_time;
        } else if (sum_decay_time * sum_interval_2 < 0) {
            interval_1 = decay_time;
        }
    }

    return decay_time;
}


static double equation_1(double* radioactivity, double* time, int N, double decay_time) {
    double sum = 0;
    for (int i = 0; i < N; i++) {
        double exp_term = exp(-time[i] / decay_time);
        sum += time[i] * exp_term * (radioactivity[i] - exp_term);
    }
    return sum;
}
