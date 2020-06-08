#include "cfunct.h"

Eigen::MatrixXd _MatrixPlus_(Eigen::MatrixXd Data, Eigen::MatrixXd M0, Eigen::MatrixXd V0, int d)
{

  Eigen::MatrixXd M = MatrixXd::Random(d,d);  
  M = (M + Data)*50 + M0 + V0; 
  return M;
}
 