#include "rng.hpp"

#include <stdlib.h>
#include <time.h>

RNG::RNG() {
	srand(time(NULL));
	rng_state[0] = rand();
	rng_state[1] = rand();
	rng_state[2] = rand();
	rng_state[3] = rand();
	rng_state[4] = rand();
}

RNG::~RNG() { }

int RNG::Random(int min, int max) {
	return int(Rand()/(RandMax()+1.0)*(max-min+1))+min;
}

double RNG::Random(double min, double max) {
	return ((double)Rand()/(double)RandMax()*(max-min))+min;
}

/* 2^160 period */
int RNG::Rand() {
	unsigned int tmp;
	tmp = rng_state[0] ^ (rng_state[0] >> 7);
	rng_state[0] = rng_state[1];
	rng_state[1] = rng_state[2];
	rng_state[2] = rng_state[3];
	rng_state[3] = rng_state[4];
	rng_state[4] = (rng_state[4] ^ (rng_state[4] << 6)) ^ (tmp ^ (tmp << 13));
	return (rng_state[2] + rng_state[2] + 1) * rng_state[4];
}

int RNG::RandMax() const {
	return RAND_MAX;
}
