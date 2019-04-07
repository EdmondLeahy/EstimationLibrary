#include "LinearKalmanFIlter.h"

void linearKalmanFilter::read_full_l(string filename)
{
	read_l(filename);
	all_obs = l; //set all observations to l
	l = VectorXd::Zero(l.rows()); //remove observations from the l matrix

}

void linearKalmanFilter::perform_lin_kalman()
{
	// For each line in all_obs, we treat it as an epoch
	
	//Initial things
	double x_m = x0(0);
	double phi = 0;
	double Q = 0;
	double P = 0;
	double epochs = all_obs.rows();

	for (int epoch = 0; epoch < epochs; epoch++) {
			

		//Predict

		//Observations
		l(0) = all_obs(epoch);


		// Perform LS

		//Create Gain

		//Estimate.





	}


}
