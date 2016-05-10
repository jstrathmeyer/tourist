/* relative: relative numbers used to represent statistical attributes */

#ifndef RELATIVE_H
#define RELATIVE_H

#include <iostream>

#include "rng.hpp"

class Relative {
 public:
	Relative();
	Relative(int);
	Relative(double);
	Relative(Relative const & r);

	Relative operator-() const;

	Relative operator=(const Relative & r);
	Relative operator+(const Relative & r) const;
	Relative operator-(const Relative & r) const;
	Relative operator+=(const Relative & r);
	Relative operator-=(const Relative & r);

	bool operator<(const Relative & r) const;
	bool operator>(const Relative & r) const;

	Relative operator=(double d);
	Relative operator+(double d) const;
	Relative operator-(double d) const;
	Relative operator*(double d) const;
	Relative operator/(double d) const;
	Relative operator+=(double d);
	Relative operator-=(double d);
	Relative operator*=(double d);
	Relative operator/=(double d);

	/* values have a range with a min, zero, and max */
	/* the relative value; -INF,0,INF */
	double Value() const;
	/* maps the value to 0,0.5,1; flattens it between zero and one */
	double Flatten() const;
	/* maps the value to 0,1,INF exponentially increasing
	 * scales up so that constant increases to value with have a greater increase  */
	double ScaleUp() const;    
	/* maps the value to 0,1,INF logarythmically increasing
	 * scales down so that constant increase to value have a lesser affect */
	double ScaleDown() const;  

  /* rng operations */
  bool Choose() const;

 private:
	double value;
};

std::ostream & operator<<(std::ostream &, const Relative &);
std::istream & operator>>(std::istream &, Relative &);

#endif
