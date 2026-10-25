#include "../include/sample.h"
#include "../include/export.c"

#include <math.h>

int main(){
	float samples[RATE];
	float frequency = 440.0;
	for(int i = 0; i < RATE; i++){
		samples[i] = 0.3*sin(((float)i*TIME_PER_SAMPLE)*2.0*PI*frequency);
	}
	sample_t sample = (sample_t){samples, RATE};
	exportWAV("test.wav", &sample);
	return 0;
}
