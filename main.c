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
    ADCheader header;
    ADCsample *samples = sensor_log(argv[1], &header);
    if (samples == NULL) {
        return 1;
    }
    int num_channels = (int) header.channel_count;
    ChannelReport *channel_reports = malloc(num_channels * sizeof(ChannelReport));
    if (channel_reports == NULL) {
        printf("error; malloc failed");
        free(samples);
        return 0;
    }
    double values;
    int count;
    if (samples == NULL) {
        return 1;
    }
    sequence_gap(samples, header.record_count);
    free(samples);
    return 0;



}