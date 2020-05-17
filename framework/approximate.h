#ifndef _APPROXIMATE_H_
#define _APPROXIMATE_H_

#include "MyUtil.h"

extern void mitchelMultiply();

class MitchelDouble
{
private:
  double number;

public:
  MitchelDouble(double number);
  inline operator double() const { return number; };
  const double operator*(const MitchelDouble& rhs) const;
  const double square() const;
  ~MitchelDouble();
};

#endif
