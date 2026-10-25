#ifndef CONSTS_H
#define CONSTS_H

#include <stdint.h>

#ifndef SAMPLE_FORMAT
	#warning "Sample format unspecified, defaulting to 16 bit"
	#define SAMPLE_FORMAT s16i
#endif

#if SAMPLE_FORMAT==s16i
	#define sampleType int16_t
	#define BitsPerSample 16
	#define AudioFormat (*(int16_t *) (unsigned char*){1,0})
#else
	#error "Unsupported SAMPLE_FORMAT used. Currently supported: [s16i]"
#endif

#define BytesPerSample (BitsPerSample/2)

#endif
