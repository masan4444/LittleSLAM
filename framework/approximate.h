#ifndef _APPROXIMATE_H_
#define _APPROXIMATE_H_

#include "MyUtil.h"

extern void mitchellMultiply();

class MitchellDouble
{
private:
  double number;

public:
  MitchellDouble(double number);
  inline operator double() const { return number; };
  const double operator*(const MitchellDouble& rhs) const;
  const double square() const;
  ~MitchellDouble();
};

#endif
