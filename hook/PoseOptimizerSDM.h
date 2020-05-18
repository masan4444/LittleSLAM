#ifndef _POSE_OPTIMIZER_SDM_H_
#define _POSE_OPTIMIZER_SDM_H_

#include "PoseOptimizer.h"
#include <ctime>

// Mitchel乗算を適用して最急降下法でコスト関数を最小化する
class PoseOptimizerSDM : public PoseOptimizer
{
public:
  std::string filename = outputFilePath;
  std::ofstream writingFile;
  PoseOptimizerSDM() {
    std::string _type = approximateType == 0 ? "A" : (approximateType == 1 ? "AM" : "M");
    filename.append(_type + std::to_string(time(nullptr)) + ".csv");
    writingFile.open(filename, std::ios::out);
    writingFile << "n,ev,evold,evold-ev" << std::endl;
  }

  ~PoseOptimizerSDM() {
  }

/////

  virtual double optimizePose(Pose2D &initPose, Pose2D &estPose);
};

#endif
