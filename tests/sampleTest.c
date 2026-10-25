#include "../include/sample.c"
#include "../include/export.c"

#include <math.h>

int main(){
	sample_t *sample = combineSamples(amplifySample(newSineSample(10.0, 440.0),0.5), amplifySample(newSineSample(5.0, 880.0), 0.2));
	exportWAV("test.wav", sample);
	return 0;
}
