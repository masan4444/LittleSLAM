#ifndef _POSE_OPTIMIZER_SDM_H_
#define _POSE_OPTIMIZER_SDM_H_

#include "PoseOptimizer.h"

// Mitchel乗算を適用して最急降下法でコスト関数を最小化する
class PoseOptimizerSDM : public PoseOptimizer
{
public:
  PoseOptimizerSDM() {
  }

  ~PoseOptimizerSDM() {
  }

/////

  virtual double optimizePose(Pose2D &initPose, Pose2D &estPose);
};

#endif
