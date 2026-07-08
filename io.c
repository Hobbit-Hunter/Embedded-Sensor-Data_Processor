//
// Created by Owner on 08/06/2026.
//
#include "adc.h"
#include "io.h"
#include "stats.h"
#include <stdlib.h>
#include <stdio.h>
void sensor_log(void){
FILE *file = fopen("../adc_sensor_log.bin","rb");
ADCheader header;
    if(file==NULL) {
        printf("error-file=NULL");
    }
    if (fread(&header, sizeof(ADCheader), 1, file) != 1){
        printf("error: header != 1");
        fclose(file);
    }else if(header.magic!=0xADC1BEEF){
        printf("error-magic number!=0xADC1BEEF");
        fclose(file);
    }else{
        printf("magic number correct\n");
    }
fread(&header, sizeof(ADCheader), 1, file);
if(sizeof(RawADCRecord)!=16) {
    printf("error-sample!=16");
}
    if(sizeof(ADCheader) != 24) {
        printf("error-header!=24");
    }
    double volts[4000];
    ADCsample sample = malloc(header.record_count * sizeof(ADCsample));
    int i=0;
    int overvolt[4000]={0};
    int undervolt[4000]={0};
    int status_flag[4000]={0};
    printf("raw values\tvoltage\tover/undervolt:\n");
    while(fread(&sample, sizeof(RawADCRecord), 1, file) == 1) {
        volts[i] = voltage(sample.raw_value);
        status_flag[i]=status_flags(sample.status_flags);
        overvolt[i] = overvoltage(volts[i]);
        undervolt[i] = undervoltage(volts[i]);
        printf("%u\t\t", sample.raw_value);
        printf("%.2f\t", volts[i]);
        if(overvolt[i]){
            printf("overvoltage");
        }else if(undervolt[i]) {
            printf("undervoltage");
        }
        printf("\t");
        if(status_flag[i]){
            printf("fault");
        }
        printf("\t");
        printf("\n");
        i++;
    }

    printf("mean: %.2f\t", mean_voltage(volts, i));
    printf("minimum: %.2f\t", minimum(volts, i));
    printf("maximum: %.2f\t", maximum(volts, i));
    printf("standard deviation: %.2f\t", standard_deviation(volts, i));
    fclose(file);
}