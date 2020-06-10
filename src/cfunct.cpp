#include "cfunct.h"

using namespace Eigen;

MatrixXd _MatrixPlus_(MatrixXd &M, MatrixXd &Data, int d)
{ 
  M = (M + Data)*50; 
  return M;
}
 