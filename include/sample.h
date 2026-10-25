#ifndef SAMPLE_H
#define SAMPLE_H

#include "consts.h"
#include <stdint.h>
#include <math.h>

typedef struct sampleStruct{
	float *samples;
	uint64_t length;
} sample_t;

sample_t *newEmptySampleTime(float);
sample_t *newEmptySampleSamples(uint64_t);
sample_t *newSineSample(float, float);
sample_t *amplifySample(sample_t*, float);
sample_t *normalizeSample(sample_t*);
sample_t *combineSamples(sample_t*, sample_t*);

#endif
