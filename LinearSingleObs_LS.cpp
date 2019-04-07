#include "LinearSingleObs_LS.h"

void linearSingleObs::read_l(string filename)
{
	//Read in observation file
	ifstream infile(filename);
	string line;
	
	//Get first line, number of rows/cols
	double num_row, num_col;
	infile >> num_row;
	infile >> num_col;

	l = VectorXd::Zero(num_row);
	MatrixXd Cl_diag = MatrixXd::Zero(num_row, 1);

	for (int i = 0; i < num_row; i++)
	{
		infile >> l(i);
		infile >> Cl_diag(i, 0);

	}
	
	setCl(Cl_diag);


}

void linearSingleObs::computefx()
{
	fx = VectorXd::Zero(l.rows());
	for (int i = 0; i < l.rows(); i++)
	{
		fx(i) = x0(0);

	}
}

void linearSingleObs::computeA()
{
	A = MatrixXd::Zero(l.rows(), 1);
	for (int i = 0; i < l.rows(); i++)
	{
		A(i, 0) = 1;

	}
}
