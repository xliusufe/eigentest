#ifndef EIGENTEST_H
#define EIGENTEST_H

#include <Eigen/Eigen>
#include <Eigen/Dense>
#include <iostream>
#include "List.h"

using namespace std;
using namespace Eigen;

//Eigen::MatrixXd _MatrixPlus_(Eigen::MatrixXd Data, int d);
//Eigen::MatrixXd _MatrixPlus_(Eigen::MatrixXd Data, Eigen::MatrixXd M0, Eigen::MatrixXd V0, int d);
List _MatrixPlus_(Eigen::MatrixXd Data, Eigen::MatrixXd M0, Eigen::MatrixXd V0, int d);

#endif //EIGENTEST_H
