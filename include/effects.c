#ifndef EFFECTS_C
#define EFFECTS_C

#include "effects.h"

// https://stackoverflow.com/questions/427477/fastest-way-to-clamp-a-real-fixed-floating-point-value
float effects_clamp(float d, float min, float max) {
	const float t = d < min ? min : d;
	return t > max ? max : t;
}

sample_t *limiter_sample(sample_t *sample, float limit){
	for(uint64_t i = 0; i < sample->length; i++){
		sample->samples[i] = effects_clamp(sample->samples[i], -limit, limit);
	}
	return sample;
}

#endif
