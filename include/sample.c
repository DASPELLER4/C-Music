#ifndef SAMPLE_C
#define SAMPLE_C

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "consts.h"
#include "sample.h"

sample_t *newEmptySampleTime(float duration){
	sample_t *result = malloc(sizeof(sample_t));
	uint64_t numberOfSamples = duration/TIME_PER_SAMPLE;
	float *sampleData = calloc(numberOfSamples, sizeof(float));
	result->length = numberOfSamples;
	result->samples = sampleData;
	return result;
}

sample_t *newEmptySampleSamples(uint64_t duration){
	sample_t *result = malloc(sizeof(sample_t));
	float *sampleData = calloc(duration, sizeof(float));
	result->length = duration;
	result->samples = sampleData;
	return result;
}

sample_t *newSineSample(float duration, float frequency){
	uint64_t numberOfSamples = duration/TIME_PER_SAMPLE;
	float *sampleData = malloc(sizeof(float)*numberOfSamples);
	sample_t *result = malloc(sizeof(sample_t));
	for(uint64_t i = 0; i < numberOfSamples; i++){
		sampleData[i] = sin(2.0*PI*frequency*i*TIME_PER_SAMPLE);
	}
	result->length = numberOfSamples;
	result->samples = sampleData;
	return result;
}

sample_t *amplifySample(sample_t *sample, float amplitude){
	for(uint64_t i = 0; i < sample->length; i++){
		sample->samples[i] *= amplitude;
	}
	return sample;
}

sample_t *combineSamples(sample_t* sample1, sample_t* sample2){
	bool isSample1Longer = (sample1->length > sample2->length);
	uint64_t longestSamples = isSample1Longer ? sample1->length : sample2->length;
	uint64_t shortestSamples = isSample1Longer ? sample2->length : sample1->length;
	sample_t *result = newEmptySampleSamples(longestSamples);
	for(uint64_t i = 0; i < shortestSamples; i++){
		result->samples[i] = sample1->samples[i] + sample2->samples[i];
	}
	if(isSample1Longer)
		for(uint64_t i = shortestSamples; i < longestSamples; i++)
			result->samples[i] = sample1->samples[i];
	else
		for(uint64_t i = shortestSamples; i < longestSamples; i++)
			result->samples[i] = sample2->samples[i];
	free(sample1->samples);
	free(sample2->samples);
	free(sample1);
	free(sample2);
	return result;
}

#endif
