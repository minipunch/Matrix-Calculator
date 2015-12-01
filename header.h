/*
 *
 * dimM = rows
 * dimN = cols
 *
 * */

#ifndef HEADER_H_
#define HEADER_H_

#pragma once
#include <vector>
#include <iostream>
using namespace std;

void displayMenu();

class matrixOperations {
public:
	matrixOperations() {}
	vector<vector<double> > defineMatrix(int dimM, int dimN);
	vector<vector<double> > fillMatrix(vector<vector<double> > matToGetInput);
	vector<vector<double> > multiply(vector<vector<double> > mat1, vector<vector<double> > mat2);
	vector<vector<double> > add(vector<vector<double> > mat1, vector<vector<double> > mat2);
	vector<vector<double> > subtract(vector<vector<double> > mat1, vector<vector<double> > mat2);
	vector<vector<double> > operator+(matrixOperations object);
	vector<vector<double> > operator-(matrixOperations object);
	vector<vector<double> > operator*(matrixOperations object);
	friend ostream &operator<<(ostream &output, const matrixOperations &obj);

	vector<vector<double> > matrix;
private:

};


#endif /* HEADER_H_ */
