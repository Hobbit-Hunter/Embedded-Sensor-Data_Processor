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
        return 1;
    }

    for (int ch = 0; ch < num_channels; ch++) {
        analyze_channel(samples, (int) header.record_count, ch, &channel_reports[ch]);
    }

    int gaps = sequence_gap(samples, (int) header.record_count);

    if (write_results("results.txt", &header, channel_reports, num_channels, gaps) != 0) {
        free(channel_reports);
        free(samples);
        return 1;
    }
    printf("%d sequence gaps\n", gaps);
    free(channel_reports);
    free(samples);
    return 0;
}