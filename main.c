#include <stdio.h>
#include <stdlib.h>
#include "adc.h"
#include "stats.h"
#include "io.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <sensor_log.bin>\n", argv[0]);
        return 1;
    }
    double values;
    int count;
    ADCheader header;
    ADCsample *samples=sensor_log(argv[1],&header);
    if (samples == NULL) {
        return 1;
    }
    sequence_gap(samples, header);
    free(samples);
    return 0;



}