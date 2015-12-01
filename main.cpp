/*
 * main.cpp
 *
 *  Created on: Nov 23, 2015
 *      Author: josh
 */
#include "header.h"

int main()
{
	int getRows, getCols;
	int userChoice;
	matrixOperations MO;
	matrixOperations MO1;
	matrixOperations MO3;

	cout << "CREATE YOUR MATRICES\n";
	cout << "Enter rows of first matrix: ";
	cin >> getRows;

	cout << "Enter columns of first matrix: ";
	cin >> getCols;


	 MO.matrix = MO.defineMatrix(getRows, getCols);

	cout << "\nEnter rows of second matrix: ";
	cin >> getRows;

	cout << "Enter columns of second matrix: ";
	cin >> getCols;

	MO1.matrix = MO1.defineMatrix(getRows, getCols);

	// fill matrices with data
	MO.matrix = MO.fillMatrix(MO.matrix);
	MO1.matrix = MO.fillMatrix(MO1.matrix);

	// BEGIN MATRIX OPERATIONS BELOW

	displayMenu();
	cin >> userChoice;

	switch(userChoice){
	case 1:
		if(MO.matrix[0].size() == MO1.matrix[0].size() && MO.matrix.size() == MO1.matrix.size())
		{

			//MO3.matrix = MO + MO1;
			vector<vector<double> > mat3 = MO + MO1;
			//vector<vector<double> > mat3 = MO.operator+(MO1);

			//delete line below?
			MO3.matrix = mat3;

			cout << "\nSUM\n";
			cout << MO3;
		}
		else
		{
			cout << "\nInvalid matrix dimensions. Cannot add two matrices of different sizes.\n";
		}

		break;
	case 2:
		if(MO.matrix[0].size() == MO1.matrix[0].size() && MO.matrix.size() == MO1.matrix.size())
				{
					vector<vector<double> > mat3 = MO - MO1;

					MO3.matrix = mat3;

					cout << "\nDIFFERENCE\n";
					cout << MO3;
				}
				else
				{
					cout << "\nInvalid matrix dimensions. Cannot subtract two matrices of different sizes.\n";
				}
			break;
	case 3:
		if(MO.matrix[0].size() == MO1.matrix.size())
		{
			MO3.matrix = MO * MO1;

			cout << "\nPRODUCT\n";
			cout << MO3;
		}
		else
		{
			cout << "\nInvalid matrix multiplication. Columns of matrix one must equal rows of matrix two.\n";
		}
			break;
	default:
		break;
	}

	return 0;
}
