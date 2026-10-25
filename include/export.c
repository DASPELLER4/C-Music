#ifndef EXPORT_C
#define EXPORT_C

#include "export.h"
#include <stdlib.h>
#include <stdio.h>

int exportWAV(char *fileName, sample_t *sample){
	FILE *file = fopen(fileName, "w");
	if(file == NULL){
		printf("Unable to open file %s for writing.\n", fileName);
		return 1;
	}
	fwrite("RIFF", 1, 4, file);
	uint16_t channels = 2;
	uint32_t totalSamples = channels*(sample->length);
	uint16_t bitDepth = 16;
	uint32_t fileSize = totalSamples*bitDepth/8 + 44 - 8;
	fwrite(&fileSize, 4, 1, file);
	fwrite("WAVE", 1, 4, file);
	fwrite("fmt ", 1, 4, file);
	uint32_t chunkSize = 24 - 8;
	fwrite(&chunkSize, 4, 1, file);
	uint16_t type = 1;
	uint32_t rate = RATE;
	uint32_t bytePerSec = (rate * bitDepth * channels) / 8;
	uint16_t bytePerBloc = (channels * bitDepth) / 8;
	fwrite(&type, 2, 1, file);
	fwrite(&channels, 2, 1, file);
	fwrite(&rate, 4, 1, file);
	fwrite(&bytePerSec, 4, 1, file);
	fwrite(&bytePerBloc, 2, 1, file);
	fwrite(&bitDepth, 2, 1, file);
	fwrite("data", 1, 4, file);
	uint32_t dataSize = totalSamples*channels;
	fwrite(&dataSize, 4, 1, file);
	for(uint64_t i = 0; i < sample->length; i++){
		int16_t data = (int16_t)(32676.0 * sample->samples[i]);
		fwrite(&data, 2, 1, file);
		data = 0; // samples are mono
		fwrite(&data, 2, 1, file);
	}
	fclose(file);
	return 0;
}

#endif
