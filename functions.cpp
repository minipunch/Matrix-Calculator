#include "header.h"

vector<vector<double> > matrixOperations::defineMatrix(int dimM, int dimN)
{
	vector<vector<double> > matrix;
	matrix.resize(dimM);
		for (int i = 0; i < dimM; i++)
			matrix[i].resize(dimN);

		return matrix;
}

vector<vector<double> > matrixOperations::multiply(vector<vector<double> > mat1, vector<vector<double> > mat2)
{

	int dimM = mat1.size();
	int dimN = mat2[0].size();

	vector<vector<double> > productMatrix = defineMatrix(dimM, dimN);

	for (int i = 0; i < dimM; i++)
		for (int j = 0; j < dimN; j++)
		{
			double sumElements = 0;
			for (int k = 0; k < mat1[0].size(); k++)
			{
				sumElements += mat1[i][k] * mat2[k][j];
			}
			productMatrix[i][j] = sumElements;
		}

	return productMatrix;
}

vector<vector<double> > matrixOperations::add(vector<vector<double> > mat1, vector<vector<double> > mat2) {

	int row = mat1.size();
	int col = mat1[0].size();

	vector<vector<double> > sumMatrix = defineMatrix(row, col);

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			sumMatrix[x][y] = mat1[x][y] + mat2[x][y];
		}
	}


	return sumMatrix;
}

vector<vector<double> > matrixOperations::subtract(vector<vector<double> > mat1, vector<vector<double> > mat2) {
	int row = mat1.size();
	int col = mat1[0].size();

	vector<vector<double> > diffMatrix = defineMatrix(row, col);

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			diffMatrix[x][y] = mat1[x][y] - mat2[x][y];
		}
	}


	return diffMatrix;
}

 vector<vector<double> > matrixOperations::fillMatrix(vector<vector<double> > matToGetInput)
{
	int row = matToGetInput.size();
	int col = matToGetInput[0].size();

	cout << "\nEnter input into the array:\n";

	for (int  c = 0 ; c < row ; c++ ){
			for (int d = 0 ; d < col ; d++ ) {
				cout << "<" << c + 1 << "," << d + 1 << ">" << ": ";
				cin >> matToGetInput[c][d];
			}
		}

	return matToGetInput;
}

 //matrixOperations matrixOperations::operator+(matrixOperations object)
vector<vector<double> > matrixOperations::operator+(matrixOperations object) {
	int row = this->matrix.size();
	int col = this->matrix[0].size();

	//matrixOperations objectToBePassedBack;
	vector<vector<double> > sumMatrix = defineMatrix(row, col);

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			//objectToBePassedBack.matrix[x][y] = this->matrix[x][y] + object.matrix[x][y];
			sumMatrix[x][y] = this->matrix[x][y] + object.matrix[x][y];
		}
	}
		//return objectToBePassedBack;
		return sumMatrix;
}

vector<vector<double> > matrixOperations::operator-(matrixOperations object) {
	int row = this->matrix.size();
	int col = this->matrix[0].size();

	vector<vector<double> > sumMatrix = defineMatrix(row, col);

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			sumMatrix[x][y] = this->matrix[x][y] - object.matrix[x][y];
		}
	}

	return sumMatrix;
}

vector<vector<double> > matrixOperations::operator*(matrixOperations object) {
	int dimM = this->matrix.size();
	int dimN = object.matrix[0].size();

	vector<vector<double> > productMatrix = defineMatrix(dimM, dimN);

	for (int i = 0; i < dimM; i++)
		for (int j = 0; j < dimN; j++)
		{
			double sumElements = 0;
			for (int k = 0; k < this->matrix[0].size(); k++)
			{
				sumElements += this->matrix[i][k] * object.matrix[k][j];
			}
			productMatrix[i][j] = sumElements;
		}

	return productMatrix;
}

ostream &operator<<(ostream &output, const matrixOperations &obj){
	for (int x = 0; x < obj.matrix.size(); x++)
				{
					for (int y = 0; y < obj.matrix[0].size(); y++)
					{
						output << "<" << x + 1 << "," << y + 1 << ">" << ": ";
						output << obj.matrix[x][y] << endl;
					}
				}
	return output;
}

void displayMenu() {
	cout << "MENU\n";
	cout << "1 - ADD\n";
	cout << "2 - SUBTRACT\n";
	cout << "3 - MULTIPLY\n";
	cout << "Enter command: ";
}
