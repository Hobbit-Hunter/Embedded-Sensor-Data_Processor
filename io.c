//
// Created by Owner on 08/06/2026.
//
#include "adc.h"
#include "io.h"
#include <stdio.h>
void sensor_log(void){
FILE *file = fopen("../adc_sensor_log.bin","rb");
ADCheader header;
fread(&header, sizeof(ADCheader), 1, file);
if(file==NULL){
    printf("error-file=NULL");
}else if(header.magic!=0xADC1BEEF){
    printf("error-magic number!=0xADC1BEEF");
}else{
    printf("magic number correct");
}
if(sizeof(ADCsample)!=16) {
    printf("error-sample!=16");
}
    if (sizeof(ADCheader) != 24) {
        printf("error-header!=24");
    }
    fclose(file);
}