//
// Created by Owner on 08/06/2026.
//

#include "stats.h"
#include <stdio.h>
#include <math.h>
#include "adc.h"
double mean_voltage(const double *values, int count) {
    if (count <0) return 0;
    double total = 0;
    for (const double *p = values; p < values + count; p++){
        total += *p;
    }
    return total/count;
}
double minimum(const double *values, int count) {
    if (count <= 0) return 0;
    double result = *values;
    for (const double *p = values; p < values + count; p++) {
        if (*p < result) result = *p;
        }
    return result;
}
double maximum(const double *values, int count){
    if (count <= 0) return 0;
    double result = *values;
    for (const double *p = values; p < values + count; p++) {
        if (*p > result) result = *p;
    }
    return result;
}
double standard_deviation(const double *values, int count) {
    if (count <= 1) return 0;
    double average = mean_voltage(values, count);
    double sum = 0;
    for (const double *p = values; p < values + count; p++){
        double diff = *p - average;
        sum += diff * diff;
    }
    return sqrt(sum/(count-1));
}

int overvoltage(double value){
    if(value>3){
        return 1;
    }else{
        return 0;
    }
}
int undervoltage(double value){
   if (value<0.3) {
       return 1;
   }else{
       return 0;
   }
}
int status_flags(uint8_t value){
        if(value != 0x00){
            return 1;
        }else{
            return 0;
    }
}