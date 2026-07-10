~ Embedded Sensor Data Processor

This is a command line program the parses a binary data file calculates statistics such as mean, min, max, detects faults and gaps in the file and outputs the results in a .txt file

GitHub repository: https://github.com/Hobbit-Hunter/Embedded-Sensor-Data_Processor

## Building and running in CLion
1. Open the project folder in clion
2. build the project by clicking the hammer symbol
3. Go to run, click the three dots and click modify configuration settings
4. in the same window go to "program arguments", enter the path to the binary log file
5. run the program by clicking the green play symbol
6. to view results navigate to results.txt in the project folder

## Building and running with gcc
gcc -std=c99 -Wall -Wextra - o processor main.c adc.c io.c stats.c -lm./processor adc_sensor_log.bin