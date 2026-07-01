#include <stdio.h>
#include "adc.h"
#include "stats.h"
#include "io.h"

int main() {
    double values;
    int count;
    ADCsample *samples;
    ADCheader header;
    sensor_log();
    sequence_gap(samples, header);
    //test
    return 0;



}