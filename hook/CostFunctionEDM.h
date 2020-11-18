#ifndef _COST_FUNCTION_EDM_H_
#define _COST_FUNCTION_EDM_H_

#include "CostFunction.h"

class CostFunctionEDM : public CostFunction
{
public:
  CostFunctionEDM() {
  }

  ~CostFunctionEDM() {
  }

  virtual double calValue(double tx, double ty, double th);
  virtual double calValueMitchell(double tx, double ty, double th);
  virtual std::tuple<double, double, double> differential(double tx, double ty, double th);
  virtual std::tuple<double, double, double> differentialMitchell(double tx, double ty, double th);
};

#endif
