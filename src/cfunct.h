#ifndef EIGENTEST_H
#define EIGENTEST_H

#include <Eigen/Eigen>
#include <Eigen/Dense>
#include <iostream>

using namespace std;
using namespace Eigen;

//MatrixXd _MatrixPlus_(MatrixXd &M, MatrixXd &Data, int d);
MatrixXd _MatrixPlus_(MatrixXd &M, MatrixXd &Data, MatrixXd &M0, MatrixXd &V0, int d);

#endif //EIGENTEST_H
