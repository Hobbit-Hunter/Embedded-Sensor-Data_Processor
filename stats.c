//
// Created by Owner on 08/06/2026.
//

#include "stats.h"
#include <stdio.h>
#include <math.h>
#include "adc.h"
ADCsample *samples;
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
    double sum;
    for(int i=0;i < count;i++){
        sum += (values[i]-average)*(values[i]-average);
    }
    sd = sqrt(sum/(count-1));
    return sd;
}
double overvoltage(double *values, int count){
    double ov;
    for(int i=0;i < count;i++){
        if(((values[i]/4095.0)*3.3)>3){
            printf("error: overvoltage at row %d", i);
        }
    }
}
double undervoltage(double *values, int count){
    double uv;
    for(int i=0;i<count;i++){
        if(((values[i]/4095.0)*3.3)<0.3){
            printf("error: undervoltage at row %d", i);
        }
    }
}
double Status_flag(double *values, int count){
    double sf;
    for(int i=0;i < count; i++){
        if(samples[i].status_flags != 0x00){
            printf("error: status flag");
        }
    }
}