
#include "relative.hpp"

#include <math.h>

Relative::Relative() : value(0) { }
Relative::Relative(int i) : value(i) { }
Relative::Relative(double d) : value(d) { }
Relative::Relative(const Relative & r) : value(r.Value()) { }

Relative Relative::operator-() const { return Relative(-Value()); }

Relative Relative::operator=(const Relative & r) { value = r.Value(); return *this; }
Relative Relative::operator+(const Relative & r) const { return Relative(Value() + r.Value()); }
Relative Relative::operator-(const Relative & r) const { return Relative(Value() - r.Value()); }
Relative Relative::operator+=(const Relative & r) { value += r.Value(); return *this; }
Relative Relative::operator-=(const Relative & r) { value -= r.Value(); return *this;}

bool Relative::operator<(const Relative & r) const { return (Value() < r.Value()); }
bool Relative::operator>(const Relative & r) const { return (Value() > r.Value()); }

Relative Relative::operator=(double d) { value = d; return *this; }
Relative Relative::operator+(double d) const { return Relative(value+d); }
Relative Relative::operator-(double d) const { return Relative(value-d); }
Relative Relative::operator*(double d) const { return Relative(value * d); }
Relative Relative::operator/(double d) const { return Relative(value / d); }
Relative Relative::operator+=(double d) { value += d; return *this; }
Relative Relative::operator-=(double d) { value -= d; return *this; }
Relative Relative::operator*=(double d) { value *= d; return *this; }
Relative Relative::operator/=(double d) { value /= d; return *this; }

double Relative::Value() const { return value; }
/* maps value: -INF,0,INF -> 0,0.5,1 */
double Relative::Flatten() const { return atan(value)/M_PI + 0.5; }
/* maps value: -INF,0,INF -> 0,1,INF */
double Relative::ScaleUp() const { return exp(value); }
double Relative::ScaleDown() const { return log(value); }

bool Relative::Choose() const {
  return (rng.Random(0.0,1.0) < Flatten());
}

std::ostream & operator<<(std::ostream & out, const Relative & r) {
	return out << r.Value();
}

std::istream & operator>>(std::istream & in, Relative & r) {
	double v;
	in >> v;
	r = Relative(v);
	return in;
}
