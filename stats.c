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
double minimum(double *values, int count) {
    double min;
    for (int i = 0; i < count; i++) {
        if (values[i + 1] < values[i]) {
            values[i + 1] = min;
        }
    }
    return min;
}
double maximum(double *values, int count){
    double max;
    for(int i = 0;i < count;i++) {
        if (values[i + 1]>values[i]){
            values[i + 1] = max;
        }
    }
    return max;
}
double standard_deviation(double *values, int count){
    double total = 0;
    for (int i=0; i < count; i++){
        total += values[i];
    }
    double average = total/count;
    double sd;
    for(int i=0;i < count;i++){
        double total += (values[i]-average)*(values[i]-average);
    }
    return total/count-1;
}