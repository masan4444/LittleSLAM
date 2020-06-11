﻿#include "CostFunctionEDM.h"
#include "approximate.h"

using namespace std;

typedef MitchelDouble mdouble;

#define double1 double
#define double2 double
#define double3 mdouble
#define double4 mdouble

// 点間距離によるICPのコスト関数
double CostFunctionEDM::calValue(double tx, double ty, double th) {
  double a = DEG2RAD(th);
  double error=0;
  int pn=0;
  int nn=0;
  // printf("curLps: %lu, refLps: %lu\n", curLps.size(), refLps.size());
  // printf("curLps[0]: %lf, refLps[0]: %lf\n", curLps[0]->x, refLps[0]->x);
  for (size_t i=0; i<curLps.size(); i++) {
    const LPoint2D *clp = curLps[i];             // 現在スキャンの点
    const LPoint2D *rlp = refLps[i];             // clpに対応する参照スキャンの点

    double cx = clp->x;
    double cy = clp->y;
    // printf("cx[%zu]: %lf, cy[%zu]: %lf\n", i, cx, i, cy);
    // printf("x[%zu]: %lf, y[%zu]: %lf\n", i, rlp->x, i, rlp->y);

    double x = double1(cos(a))*double1(cx)
             - double1(sin(a))*double1(cy) + tx;       // clpを参照スキャンの座標系に変換
    double y = double1(sin(a))*double1(cx)
             + double1(cos(a))*double1(cy) + ty;       // clpを参照スキャンの座標系に変換
    double edis = double2(x - rlp->x)*double2(x - rlp->x)
                + double2(y - rlp->y)*double2(y - rlp->y);// 点間距離

    if (edis <= evlimit*evlimit)
      ++pn;                                      // 誤差が小さい点の数

    error += edis;                               // 各点の誤差を累積

    ++nn;
  }

  error = (nn>0)? error/nn : HUGE_VAL;           // 平均をとる。有効点数が0なら、値はHUGE_VAL
  pnrate = 1.0*pn/nn;                            // 誤差が小さい点の比率

//  printf("CostFunctionEDM: error=%g, pnrate=%g, evlimit=%g\n", error, pnrate, evlimit);     // 確認用

  error *= 100;                                  // 評価値が小さくなりすぎないよう100かける。

  return(error);
}


// Mitchel乗算を適用した点間距離によるICPのコスト関数
double CostFunctionEDM::calValueMitchel(double tx, double ty, double th) {
  return CostFunctionEDM::calValue(tx, ty, th);
}


std::tuple<double, double, double> CostFunctionEDM::differential(double tx, double ty, double th) {
  double a = DEG2RAD(th);
  // double error=0;
  // int pn=0;
  int nn=0;

  double xDiff = 0;
  double yDiff = 0;
  double thetaDiff = 0;
  for (size_t i=0; i<curLps.size(); i++) {
    const LPoint2D *clp = curLps[i];             // 現在スキャンの点
    const LPoint2D *rlp = refLps[i];             // clpに対応する参照スキャンの点

    double cx = clp->x;
    double cy = clp->y;
    double x =  double3(cos(a)) * double3(cx);
    double x_ = double3(sin(a)) * double3(cy);
    double y =  double3(sin(a)) * double3(cx);
    double y_ = double3(cos(a)) * double3(cy);

    xDiff += x - x_ + tx - rlp->x;
    yDiff += y + y_ + ty - rlp->y;
    thetaDiff += double4(x)*double4(ty - rlp->y) - double4(y_)*double4(tx - rlp->x)
               - double4(y)*double4(tx - rlp->x) - double4(x_)*double4(ty - rlp->y);

    // if (diff <= evlimit*evlimit)
    //   ++pn;                                      // 誤差が小さい点の数

    // error += diff;                               // 各点の誤差を累積

    ++nn;
  }

  // error = (nn>0)? error/nn : HUGE_VAL;           // 平均をとる。有効点数が0なら、値はHUGE_VAL
  // pnrate = 1.0*pn/nn;
  double coe = 100.0 / nn;
  return { coe * xDiff, coe * yDiff, coe * thetaDiff };
}
