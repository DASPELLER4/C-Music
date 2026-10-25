#include "../include/sample.c"
#include "../include/export.c"
#include "../include/effects.c"

#include <math.h>

int main(){
	sample_t *sample = normalize(limiter(combineSamples(amplify(newSineSample(10.0, 440.0),0.5), amplify(newSineSample(5.0, 880.0), 0.2)),0.1));
	exportWAV("test.wav", sample);
	return 0;
}
