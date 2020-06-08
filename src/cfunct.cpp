#include "cfunct.h"

using namespace std;
using namespace Eigen;

/*
Eigen::MatrixXd _MatrixPlus_(Eigen::MatrixXd Data, Eigen::MatrixXd M0, Eigen::MatrixXd V0, int d)
{

  Eigen::MatrixXd M = MatrixXd::Random(d,d);  
  M = (M + Data)*50 + M0 + V0; 
  return M;
}
*/

List _MatrixPlus_(Eigen::MatrixXd Data, Eigen::MatrixXd M0, Eigen::MatrixXd V0, int d)
{

  Eigen::MatrixXd M = MatrixXd::Random(d,d);  
  M = (M + Data)*50 + M0 + V0; 
  List myList;
  myList.add("M",M);
  myList.add("M0",M0);
  myList.add("V0",V0);
  return myList;
}
 