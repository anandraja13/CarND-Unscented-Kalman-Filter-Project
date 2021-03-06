#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  
  VectorXd rmse = VectorXd(4);
  rmse << 0, 0, 0, 0;
  
  if (estimations.size() != ground_truth.size() || estimations.size() == 0) {
    std::cout << "Invalid estimation or groundtruth data" << std::endl;
    return rmse;
  }
  
  for (int i = 0; i < estimations.size(); i++)
  {
    VectorXd residual = estimations[i] - ground_truth[i];
    
    residual = residual.array() * residual.array();
    
    rmse = rmse + residual;
  }
  
  rmse = rmse / estimations.size();
  
  rmse = rmse.array().sqrt();
  
  return rmse;
}