#ifndef BYTESYNC_H
#define BYTESYNC_H

#include "../config.h"

int ByteSyncOnSyncword(unsigned char *bitStreamIn, DECIMAL_TYPE *bitStreamInTime, unsigned long nSamples,  char *syncWord, unsigned int syncWordLength, FILE *minorFrameFile);
#endif