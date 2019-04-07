#ifndef SINGLEOBSLS_H
#define SINGLEOBSLS_H

#include "ENGOLS\GNSSLS\LeastSquares.h"

class linearSingleObs: public LeastSquares
{
public:
	void read_l(string filename);

private: 

	void computefx();
	void computeA();

};




#endif
