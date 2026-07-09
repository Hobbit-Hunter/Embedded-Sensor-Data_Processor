//
// Created by Owner on 08/06/2026.
//
#include <stdint.h>
#ifndef UNTITLED3_STATS_H
#define UNTITLED3_STATS_H
double mean_voltage(double *values, int count);
double minimum(double *values, int count);
double maximum(double *values, int count);
double standard_deviation(double *values, int count);
int overvoltage(double values);
int undervoltage(double values);
int status_flags(uint8_t values);
double mean_of(const double *values, int count);
double min_of(const double *values, int count);
double max_of(const double *values, int count);
double stddev_of(const double *values, int count);
#endif //UNTITLED3_STATS_H