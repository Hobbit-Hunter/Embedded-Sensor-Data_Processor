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
int sequence_gap(const ADCsample *samples, int count) {
    int gaps = 0;
    for (const ADCsample *p = samples; p < samples + count; p++) {
        uint32_t current = p->sequence_number;
        uint32_t next = (p+1)->sequence_number;
        if (next != current + 1) {
            printf("error: sequence gap");
            gaps++;
        }
    }
    return gaps;
}
void analyze_channel(const ADCsample *samples, int count, int channel, ChannelReport *report) {
    report->channel = channel;
    report->overvoltage_count = 0;
    report->undervoltage_count = 0;
    report->fault_count = 0;

    double *channel_volts = malloc(count * sizeof(double));
    int n = 0;
    for (const ADCsample *p = samples; p< samples + count; p++) {
        if (p->channel_id != channel) continue;

        channel_volts[n] = p->voltage;
        n++;

        if (p->voltage > 3) report->overvoltage_count++;
        if (p->voltage < 0.3) report->undervoltage_count++;
        if (p->status_flags & 0x01) report->fault_count++;
    }



    report->sample_count = n;
    report->mean = mean_voltage(channel_volts, n);
    report->min = minimum(channel_volts, n);
    report->max = maximum(channel_volts, n);
    report->stddev = standard_deviation(channel_volts, n);

    free(channel_volts);
}