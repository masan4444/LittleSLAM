#ifndef _COST_FUNCTION_EDM_H_
#define _COST_FUNCTION_EDM_H_

#include "CostFunctionMitchel.h"

class CostFunctionEDM : public CostFunctionMitchel
{
public:
  CostFunctionEDM() {
  }

  ~CostFunctionEDM() {
  }

  virtual double calValue(double tx, double ty, double th);
  virtual double calValueMitchel(double tx, double ty, double th, int type);
};

#endif
