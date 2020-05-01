#include "cfunct.h"

Eigen::MatrixXd _MatrixPlus_(Eigen::MatrixXd Data, int d)
{

  Eigen::MatrixXd M = MatrixXd::Random(d,d);  
  M = (M + Data)*50; 
  return M;
}
 