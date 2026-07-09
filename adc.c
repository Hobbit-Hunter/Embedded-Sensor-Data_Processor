//
// Created by Owner on 08/06/2026.
//

#include "adc.h"
#include <stdio.h>
double voltage(double raw_value){
    return (raw_value/4095.0)*3.3;
}
//double values[header.record_count]
void sequence_gap(ADCsample *samples, ADCheader header) {
    for (const ADCsample *p = samples; p < samples + count; p++) {
        double gap = samples[i+1].sequence_number-samples[i].sequence_number;
        if(gap>1){
            printf("error: sequence error at row %d", i);
        }
    }
}
int analyze_channel() {

}