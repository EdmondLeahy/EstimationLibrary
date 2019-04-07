#ifndef LINEARKF_H
#define LINEARKF_H

#include "LinearSingleObs_LS.h"


class linearKalmanFilter : public linearSingleObs
{
public:
	VectorXd all_obs;
	void read_full_l(string filename);

	void perform_lin_kalman();

private:


};

#endif
