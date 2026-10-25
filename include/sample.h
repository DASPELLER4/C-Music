#ifndef SAMPLE_H
#define SAMPLE_H

#include "consts.h"
#include <stdint.h>

typedef struct sampleStruct{
	float *samples;
	uint64_t length;
} sample_t;

#endif
