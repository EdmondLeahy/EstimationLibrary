#include "NonLinear_LS.h"

void nonlinearLS::read_l(string filename)
{
	//Read in observation file
	ifstream infile(filename);
	string line;

	//Get first line, number of rows/cols
	int num_row, num_col, ind;
	double temp_cl;
	infile >> num_row;
	infile >> num_col;

	//assume last column is precision for observations in row.
	num_col = num_col - 1;

	l = VectorXd::Zero(num_row*num_col);
	MatrixXd Cl_diag = MatrixXd::Zero(num_row*num_col, 1);

	for (int i = 0; i < num_row; i++)
	{
		for (int j = 0; j < num_col + 1; j++) {
			ind = i * num_col + j;
			if (j == num_col) {
				infile >> temp_cl;
			}
			else {

				infile >> l(ind);
			}
		}

		//Apply variance to every obs
		for (int c = 0; c < num_col; c++) {
			Cl_diag(i*num_col + c) = temp_cl;
		}
	}

	setCl(Cl_diag);


}
