//
// Created by Owner on 08/06/2026.
//

#include "adc.h"
#include "stats.h"
#include <stdlib.h>
#include <stdio.h>
double voltage(double raw_value){
    return (raw_value/4095.0)*3.3;
}
//double values[header.record_count]
void sequence_gap(ADCsample *samples, ADCheader header) {
    for (const ADCsample *p = samples; p < samples + count; p++) {
        double gap = samples[p+1].sequence_number-samples[p].sequence_number;
        if(gap>1){
            printf("error: sequence error at row %d", p);
        }
    }
}
void analyze_channel(const ADCsample *samples, int count, int channel, ChannelReport *report) {
    report->channel = channel;

    double *channel_volts = malloc(count * sizeof(double));
    if (channel_volts == NULL) {
        report->sample_count = 0;
        report->mean = report->min = report-> max = report->stddev = 0;
        return;
    }

    int n = 0;
    for (const ADCsample *p = samples; p < samples + count; p++) {
        if (p->channel_id != channel) {
            continue;
        }
        channel_volts[n] = p->voltage;
        n++;
    }
    report->sample_count = n;
    report->mean = mean_of(channel_volts, n);
    report->min = min_of(channel_volts, n);
    report->max = max_of(channel_volts, n);
    report->stddev = stddev_of(channel_volts, n);

    free(channel_volts);
}