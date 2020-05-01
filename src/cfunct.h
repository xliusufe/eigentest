#ifndef EIGENTEST_H
#define EIGENTEST_H

#include <Eigen/Eigen>
#include <Eigen/Dense>
#include <iostream>
#include <list>

using namespace Eigen;

Eigen::MatrixXd Cov(Eigen::MatrixXd Data, int d);
//double Cov(MatrixXd Data);


#endif //EIGENTEST_H