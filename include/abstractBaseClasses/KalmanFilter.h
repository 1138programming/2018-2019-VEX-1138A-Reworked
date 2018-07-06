#include "main.h"

#ifndef KALMANFILTER_H
#define KALMANFILTER_H

class KalmanFilter {
  private:
    Encoder rightEncoder;
    Encoder leftEncoder;
    Gyro gyro;
  public:
    KalmanFilter(Encoder rightEncoder, Encoder leftEncoder, Gyro gyro);
};

#endif
