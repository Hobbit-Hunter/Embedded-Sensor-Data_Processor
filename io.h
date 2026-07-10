//
// Created by Owner on 08/06/2026.
//

#ifndef UNTITLED3_IO_H
#define UNTITLED3_IO_H
ADCsample *sensor_log(const char *filename, ADCheader *header_out);
int write_results(const char *filename, const ADCheader *header,
    const ChannelReport *channel_reports, int channel_count, int sequence_gaps);
#endif //UNTITLED3_IO_H