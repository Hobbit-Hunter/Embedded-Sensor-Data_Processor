//
// Created by Owner on 08/06/2026.
//

#include "adc.h"
#include <stdio.h>
double voltage(double raw_value){
    double v = (raw_value/4095.0)*3.3;
    printf("%lf", voltage);
    return voltage;
}