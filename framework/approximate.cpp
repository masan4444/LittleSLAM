#include "approximate.h"

using namespace std;

double mitchelMultiply(double x, double y) {
  double xx, yy;
  double xxp, yyp;
  double er;
  if (x > 0) {
    xx = std::floor(std::log2(x));
    xxp = 1;
  } else if (x < 0) {
    xx = std::floor(std::log2(-x));
    xxp = -1;
  } else {
    xx = 1;
    xxp = 0;
  }
  if (y > 0) {
    yy = std::floor(std::log2(y));
    yyp = 1;
  } else if (y < 0) {
    yy = std::floor(std::log2(-y));
    yyp = -1;
  } else {
    yy = 1;
    yyp = 0;
  }

  if (x * xxp * std::pow(2.0, -xx) + y * yyp * std::pow(2.0, -yy) < 3) {  // carry 0
    er = yyp * std::pow(2.0, yy) * (x) + xxp * std::pow(2.0, xx) * y -
         xxp * yyp * std::pow(2.0, xx + yy);
  } else {  // carry 1
    er = yyp * std::pow(2.0, yy + 1) * (x) + xxp * std::pow(2.0, xx + 1) * y -
         xxp * yyp * std::pow(2.0, xx + yy + 2);
  }
  return er;
}

MitchelDouble::MitchelDouble(double number) { this->number = number; }

const double MitchelDouble::operator*(const MitchelDouble& rhs) const {
  return mitchelMultiply(number, rhs.number);
}
