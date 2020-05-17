/****************************************************************************
 * LittleSLAM: 2D-Laser SLAM for educational use
 * Copyright (C) 2017-2018 Masahiro Tomono
 * Copyright (C) 2018 Future Robotics Technology Center (fuRo),
 *                    Chiba Institute of Technology.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * @file PoseOptimizer.h
 * @author Masahiro Tomono
 ****************************************************************************/

#ifndef _POSE_OPTIMIZER_MITCHEL_H_
#define _POSE_OPTIMIZER_MITCHEL_H_

#include "PoseOptimizer.h"
#include "CostFunctionMitchel.h"

class PoseOptimizerMitchel : public PoseOptimizer
{
public:

protected:
  CostFunctionMitchel *cfunc;          // コスト関数

public:

/////

  void setCostFunction(CostFunctionMitchel *f) {
    cfunc = f;
  }

};

#endif
