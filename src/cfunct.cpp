#include "cfunct.h"

using namespace Eigen;
MatrixXd _MatrixPlus_(MatrixXd &M, MatrixXd &Data, MatrixXd &M0, MatrixXd &V0, int d)
{ 
  M = (M + Data)*50 + M0 + V0; 
  return M;
}
 