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
    double min=values[0];
    for (int i = 1; i < count; i++) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}
double maximum(double *values, int count){
    double max=values[0];
    for(int i = 1;i < count;i++) {
        if (values[i]>max){
            max = values[i];
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
    double sum;
    for(int i=0;i < count;i++){
        sum += (values[i]-average)*(values[i]-average);
    }
    sd = sqrt(sum/(count-1));
    return sd;
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