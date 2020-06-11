#ifndef _POSE_OPTIMIZER_SDM_H_
#define _POSE_OPTIMIZER_SDM_H_

#include "PoseOptimizer.h"
#include "MyUtil.h"
#include <ctime>

extern std::ofstream writingFile;
extern std::string outputFilename;


// Mitchel乗算を適用して最急降下法でコスト関数を最小化する
class PoseOptimizerSDM : public PoseOptimizer
{
public:
  // std::string filename = outputFilePath;
  std::ofstream writingFile;
  PoseOptimizerSDM() {
    writingFile.open(outputFilename, std::ios::app);
  }

  ~PoseOptimizerSDM() {
  }

/////

  virtual double optimizePose(Pose2D &initPose, Pose2D &estPose);
};

#endif
