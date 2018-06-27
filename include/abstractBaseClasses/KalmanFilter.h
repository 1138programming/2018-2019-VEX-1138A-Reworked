#include "main.h"

#ifndef KALMANFILtER_H
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
