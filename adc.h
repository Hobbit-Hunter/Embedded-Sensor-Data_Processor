//
// Created by Owner on 08/06/2026.
//

#ifndef UNTITLED3_ADC_H
#define UNTITLED3_ADC_H
#include <stdint.h>
typedef struct __attribute__((packed)){
    uint32_t magic;
    uint16_t version;
    uint16_t channel_count;
    uint32_t record_count;
    uint32_t sample_rate;
    uint8_t reserved[8];
}ADCheader;
typedef struct __attribute__((packed)){
    float timestamp;
    uint8_t channel_id;
    uint16_t raw_value;
    int16_t temperature;
    uint8_t status_flags;
    uint32_t sequence_number;
    uint8_t reserved[2];
}RawADCRecord;

typedef struct {
    float timestamp;
    uint8_t channel_id;
    uint16_t raw_value;
    double voltage;
    int16_t temperature;
    uint8_t status_flags;
    uint32_t sequence_number;
}ADCsample;

typedef struct {
    int channel;
    int sample_count;
    double mean;
    double min;
    double max;
    double stddev;
    int overvoltage_count;
    int undervoltage_count;
    int fault_count;
} ChannelReport;

void analyze_channel(const ADCsample *samples, int count, int channel, ChannelReport *report);

double voltage(double raw_value);
int sequence_gap(const ADCsample *samples, int count);

#endif //UNTITLED3_ADC_H