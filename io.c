//
// Created by Owner on 08/06/2026.
//
#include "adc.h"
#include "io.h"
#include "stats.h"
#include <stdlib.h>
#include <stdio.h>
ADCsample *sensor_log(const char *filename, ADCheader *header_out) {
    FILE *file = fopen(filename,"rb");
    ADCheader *header = header_out;
    if(file==NULL) {
        printf("error-file=NULL");
        return NULL;
    }
    if (fread(header, sizeof(ADCheader), 1, file) != 1){
        printf("error: header != 1");
        fclose(file);
        return NULL;
    }else if(header->magic!=0xADC1BEEF){
        printf("error-magic number!=0xADC1BEEF");
        fclose(file);
        return NULL;
    }else{
        printf("magic number correct\n");
    }
    if(sizeof(RawADCRecord)!=16) {
        printf("error-sample!=16");
        fclose(file);
        return NULL;
    }
    if(sizeof(ADCheader) != 24) {
        printf("error-header!=24");
        fclose(file);
        return NULL;
    }
    ADCsample *samples = malloc(header->record_count * sizeof(ADCsample));
    if (samples == NULL) {
        printf("error: malloc failed");
        fclose(file);
        return NULL;
    }
    int i=0;
    RawADCRecord sample;
    while(i < header->record_count && fread(&sample, sizeof(RawADCRecord), 1, file) == 1) {
        samples[i].timestamp = sample.timestamp;
        samples[i].channel_id = sample.channel_id;
        samples[i].raw_value = sample.raw_value;
        samples[i].voltage = voltage(sample.raw_value);
        samples[i].temperature = sample.temperature;
        samples[i].status_flags = sample.status_flags;
        samples[i].sequence_number = sample.sequence_number;
        i++;
    }
    fclose(file);
    return samples;
}

int write_results(const char *filename, const ADCheader *header,
    const ChannelReport *channel_reports, int channel_count, int sequence_gaps) {
    FILE *out = fopen(filename, "w");
    if (out == NULL) {
        printf("error: couldn't open, filename");
        return -1;
    }
    fprintf(out, "Processor results\n");
    for (int i = 0;i < channel_count; i++) {
        const ChannelReport *r = &channel_reports[i];
        fprintf(out, "Channel %d\n", r->channel);
        fprintf(out, "Samples: %d\n", r->sample_count);
        fprintf(out, "Mean voltage: %.3f V\n", r->mean);
        fprintf(out, "Minimum voltage: %.3f V\n", r->min);
        fprintf(out, "Maximum voltage: %.3f V\n", r->max);
        fprintf(out, "Standard deviation: %.3f V\n", r->stddev);
        fprintf(out, "Overvoltage faults: %d\n", r->overvoltage_count);
        fprintf(out, "Undervoltage faults: %d\n", r->undervoltage_count);
        fprintf(out, "Sensor faults: %d\n", r->fault_count);
    }
    fprintf(out, "Gaps detected: %d\n", sequence_gaps);
    fclose(out);
    return 0;
}