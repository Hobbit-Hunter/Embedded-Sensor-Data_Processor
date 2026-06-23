//
// Created by Owner on 08/06/2026.
//

#include "stats.h"
#include <stdio.h>
#include <math.h>
#include "adc.h"
double mean_voltage(double *values, int count) {
    double total = 0;
    for (int i=0; i < count; i++){
        total += values[i];
    }
    return total/count;
}
double minimum(double *values, int count);
double maximum(double *values, int count);
double standard_deviation(double *values, int count);