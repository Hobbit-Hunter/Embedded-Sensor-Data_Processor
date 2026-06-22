//
// Created by Owner on 08/06/2026.
//

#include "adc.h"
#include <stdio.h>
double voltage(double raw_value){
    return (raw_value/4095.0)*3.3;
}