/* rng: a pseudo random number generator */

#ifndef RNG_HPP
#define RNG_HPP

#include "singleton.T"

#define rng (*(Singleton<RNG>::Instance()))

class RNG {
 protected:
	RNG();
	~RNG();

 public:
	int Random(int min, int max);
	double Random(double min, double max);  

 private:
	int Rand();
	int RandMax() const;

  unsigned int rng_state[5];
};

#endif
