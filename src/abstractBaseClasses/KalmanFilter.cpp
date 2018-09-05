#include "main.h"

KalmanFilter::KalmanFilter(Encoder rightEncoder, Encoder leftEncoder, Gyro gyro) {
  this->rightEncoder = rightEncoder;
  this->leftEncoder = leftEncoder;
  this->gyro = gyro;
};
