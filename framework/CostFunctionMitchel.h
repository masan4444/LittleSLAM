#ifndef _COST_FUNCTION_MITCHEL_H_
#define _COST_FUNCTION_MITCHEL_H_

#include "CostFunction.h"

class CostFunctionMitchel : public CostFunction
{
public:
  CostFunctionMitchel() {
  }

  ~CostFunctionMitchel() {
  }

  virtual double calValueMitchel(double tx, double ty, double th, int type) = 0;

};

#endif
