#ifndef EFFECTS_H
#define EFFECTS_H

sample_t *limiter_sample(sample_t *, float);

#define limiter(data, value) _Generic((data),\
	sample_t * : limiter_sample\
)(data,value)

#define amplify(data, value) _Generic((data),\
	sample_t * : amplifySample\
)(data,value)

#define normalize(data) _Generic((data),\
	sample_t * : normalizeSample\
)(data)

#endif
