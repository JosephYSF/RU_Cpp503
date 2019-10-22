// Name: Sifan Yuan
// Time: 09/20/2019
// Course: 16:332:503, Programming Finance

//Homework 3_Vector
/*
For this assignment you have to perform Matrix operations (Addition,
Subtraction, Multiplication, Determinant, Transpose and Inverse). For
each of the above mentioned operation you have to make a function in
addition to two other functions for ‘Inputting’ and ‘Displaying’
the Matrices in Row-Order Format. (In total there will be 8 functions :
- 6 for the operations and 2 functions for inputting and displaying the
data.)
*/

#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <vector>


using namespace std;
const int p = 0;
typedef struct
{
	int row, col;
	vector<vector <float> >  matrix;
} Matrix;	//Define a structure named Matrix


Matrix InputMatrix()
{
	Matrix m;
	int row, col;
	float temp;
	while (p == 0) {
		cout << "Input your row number:" << endl;
		cin >> row;
		if (row > 0 && row <= 10)break;
		else cout << "Please give a int number from 1 to 10!\n" << endl;
	}
	while (p == 0) {
		cout << "Input your column number:" << endl;
		cin >> col;
		if (col > 0 && col <= 10)break;
		else cout << "Please give a int number from 1 to 10!\n" << endl;
	}
	vector<vector <float> > enterMatrix;
	enterMatrix.resize(row);
	for (int i = 0; i < row; i++) enterMatrix[i].resize(col); //Resize the 2D-vector
	cout << "\nInput your matrix:" << endl;
	for (int i = 0; i < row; i++) { 
		for (int j = 0; j < col; j++)
		{
			cin >> enterMatrix[i][j];
		}
	}
	m.col = col;
	m.row = row;
	m.matrix = enterMatrix;
	return m;
}

Matrix CreateMatrix(int row, int col) {
	Matrix m;
	vector<vector <float> > matrix;
	vector<float>temp;
	matrix.resize(row);
	for (int i = 0; i < row; i++) matrix[i].resize(col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			matrix[i][j]=0;
		}
	}
	m.col = col;
	m.row = row;
	m.matrix = matrix;
	return m;
}        //Create a Matrix with 0 

Matrix PrintMatrix(Matrix m)
{
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			cout << m.matrix[i][j] << "  ";
		}
		cout << endl;
	}
	return m;
}		// Output a Matrix

Matrix AddMatrix(Matrix m1, Matrix m2) {
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m1.col; j++)
		{
			m1.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
		}
	}
	return m1;
}		//Addition

Matrix SubMatrix(Matrix m1, Matrix m2) {
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m1.col; j++)
		{
			m1.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
		}
	}
	return m1;
}		//Subtraction

Matrix MultiMatrix(Matrix m1, Matrix m2) {
	Matrix m = CreateMatrix(m1.row, m2.col);
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m2.col; j++)
		{
			float result = 0;
			for (int k = 0; k < m1.col; k++) {
				result += m1.matrix[i][k] * m2.matrix[k][j];
			}
			m.matrix[i][j] = result;
		}
	}
	return m;
}		//Multipliction

Matrix numMul(Matrix m, float num)
{
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			m.matrix[i][j] = m.matrix[i][j] * num;
		}
	}
	return m;
}       //Mutiply matrix with a float num

float DeterMatrix(Matrix M) {
	Matrix m = CreateMatrix(M.row, M.col);
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			m.matrix[i][j] = M.matrix[i][j];
		}
	}
	float result = 1;
	float div;
	int j, i, k;
	int q = 0;
	float temp;
	for (i = 0; i < m.row; i++)
	{
		if (m.matrix[i][i] == 0)
		{
			for (j = i + 1; j < m.row; j++)
			{
				if (m.matrix[j][i] != 0)
				{
					for (k = i; k < m.col; k++) {
						temp = m.matrix[i][k];
						m.matrix[i][k] = m.matrix[j][k];
						m.matrix[j][k] = temp;
					}
					q = 1;
					break;
				}
			}
			if (j == m.row) return 0;
		}
		for (j = i + 1; j < m.row; j++)
		{
			div = m.matrix[j][i] / m.matrix[i][i];
			for (k = i; k < m.col; k++)
			{
				m.matrix[j][k] -= div * m.matrix[i][k];
			}
		}
	}
	for (i = 0; i < m.row; i++)
	{
		result *= m.matrix[i][i];
	}
	if (q == 1) result *= -1;
	return result;
}			//Determinate

Matrix TransMatrix(Matrix m) {
	Matrix result = CreateMatrix(m.col, m.row);
	for (int i = 0; i < result.row; i++)
	{
		for (int j = 0; j < result.col; j++)
		{
			result.matrix[i][j] = m.matrix[j][i];
		}
	}
	return result;
}			//Transpose

Matrix MMatrix(Matrix M, int row, int col)
{
	Matrix m = CreateMatrix(M.row, M.col);
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			m.matrix[i][j] = M.matrix[i][j];
		}
	}
	Matrix re = CreateMatrix(m.row - 1, m.col - 1);
	float temp;
	int i, j;
	if (row == m.row && col == m.col);
	else if (row == m.row && col != m.col)
	{
		for (i = 0; i < re.row; i++) {
			for (j = col; j < m.col - 1; j++)
			{
				m.matrix[i][j] = m.matrix[i][j + 1];
			}
		}
	}
	else if (row != m.row && col == m.col)
	{
		for (j = 0; j < re.col; j++) {
			for (i = row; i < m.row - 1; i++)
			{
				m.matrix[i][j] = m.matrix[i + 1][j];
			}
		}
	}
	else
	{
		for (i = 0; i < m.row; i++) {
			for (j = col; j < m.col - 1; j++)
			{
				m.matrix[i][j] = m.matrix[i][j + 1];
			}
		}
		for (j = 0; j < m.col; j++) {
			for (i = row; i < m.row - 1; i++)
			{
				m.matrix[i][j] = m.matrix[i + 1][j];
			}
		}
	}
	for (i = 0; i < re.row; i++)
	{
		for (j = 0; j < re.col; j++)
		{
			re.matrix[i][j] = m.matrix[i][j];
		}
	}
	return re;
}			//Find the Mij

Matrix InvMatrix(Matrix m) {
	Matrix return1 = CreateMatrix(m.row, m.col);
	Matrix temp;
	int i, j, l;
	int k = 1;
	for (i = 0; i < return1.row; i++)
	{
		l = k;
		for (j = 0; j < return1.col; j++)
		{
			return1.matrix[j][i] = k * DeterMatrix(MMatrix(m, i, j));
			k *= -1;
		}
		k = -1 * l;
	}
	return numMul(return1, 1.0 / DeterMatrix(m));
}			//Inverse

//function main begins   
int main()
{
	int choice = 0;
	cout << "================Menu================\n" << endl;
	cout << "Choice 1: Addition" << endl;
	cout << "Choice 2: Subtraction" << endl;
	cout << "Choice 3: Mutiplication" << endl;
	cout << "Choice 4: Determinat" << endl;
	cout << "Choice 5: Transpose" << endl;
	cout << "Choice 6: Inverse" << endl;
	cout << "Choice 7: Cofactor" << endl;
	cout << "Choice 8: ****QUIT****\n" << endl;
	cout << "================END================" << endl;
	Matrix M1;
	Matrix M2;
	Matrix M;
	int n, m;
	while (p == 0) {
		cout << "\nPlease make your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nPlease create your first Matrix M1:" << endl;
			M1 = InputMatrix();
			cout << "\nPlease create your second Matrix M2:" << endl;
			M2 = InputMatrix();
			cout << "\nYour input:" << "\nMatrix M1 is" << endl;
			PrintMatrix(M1);
			cout << "\nMatrix M2 is" << endl;
			PrintMatrix(M2);
			if (M1.col != M2.col || M1.row != M2.row) cout << "The operation is not supported" << endl;
			else {
				cout << "\nThe answer is:" << endl;
				PrintMatrix(AddMatrix(M1, M2));
				cout << "\nEnter 8 to QUIT" << endl;
			}
			break;
		case 2:
			cout << "\nPlease create your first Matrix M1:" << endl;
			M1 = InputMatrix();
			cout << "\nPlease create your second Matrix M2:" << endl;
			M2 = InputMatrix();
			cout <<"\nYour input:"<< "\nMatrix M1 is" << endl;
			PrintMatrix(M1);
			cout << "\nMatrix M2 is" << endl;
			PrintMatrix(M2);
			if (M1.col != M2.col || M1.row != M2.row) cout << "The operation is not supported" << endl;
			else {
				cout << "\nThe answer is:" << endl;
				PrintMatrix(SubMatrix(M1, M2));
				cout << "\nEnter 8 to QUIT" << endl;
			}
			break;
		case 3:
			cout << "\nPlease create your first Matrix M1:" << endl;
			M1 = InputMatrix();
			cout << "\nPlease create your second Matrix M2:" << endl;
			M2 = InputMatrix();
			cout << "\nYour input:" << "\nMatrix M1 is" << endl;
			PrintMatrix(M1);
			cout << "\nMatrix M2 is" << endl;
			PrintMatrix(M2);
			if (M1.col != M2.row) cout << "\nThe operation is not supported" << endl;
			else {
				cout << "\nThe answer is:" << endl;
				PrintMatrix(MultiMatrix(M1, M2));
				cout << "\nEnter 8 to QUIT" << endl;
			}
			break;
		case 4:
			cout << "\nPlease create your Matrix M:" << endl;
			M = InputMatrix();
			cout << "\nYour input Matrix is" << endl;
			PrintMatrix(M);
			if (/*M.col ==3&& M.row == 3*/p == 0) {
				cout << "\nThe answer is:" << DeterMatrix(M) << endl;
				cout << "\nEnter 8 to QUIT" << endl;
			}
			else {
				cout << "\nThe operation is not supported" << endl;
			}
			break;
		case 5:
			cout << "\nPlease create your Matrix M:" << endl;
			M = InputMatrix();
			cout << "\nYour input Matrix is" << endl;
			PrintMatrix(M);
			cout << "\nThe answer is:" << endl;
			PrintMatrix(TransMatrix(M));
			cout << "\nEnter 8 to QUIT" << endl;
			break;
		case 6:
			cout << "\nPlease create your Matrix M:" << endl;
			M = InputMatrix();
			cout << "\nYour input Matrix is" << endl;
			PrintMatrix(M);
			if (M.col != M.row) cout << "The operation is not supported" << endl;
			else {
				cout << "\nThe answer is:" << endl;
				PrintMatrix(InvMatrix(M));
				cout << "\nEnter 8 to QUIT" << endl;
			}
			break;
		case 7:
			cout << "\nPlease create your Matrix M:" << endl;
			M = InputMatrix();
			cout << "\nYour input Matrix is" << endl;
			PrintMatrix(M);
			cout << "\nPlease input the row to delete:" << endl;
			cin >> n;
			cout << "\nPlease input the colum to delete:" << endl;
			cin >> m;
			cout << "\nThe new Matrix is:" << endl;
			PrintMatrix(MMatrix(M, n, m));
			cout << "\nCofactor is:" << DeterMatrix(MMatrix(M, n, m)) << endl;
			cout << "\nEnter 8 to QUIT" << endl;
			break;
		default:
			break;
		}
		if (choice == 8) break;
	}
	cout << "\nThank you for using!" << endl;
	return 0;
}	//end function main
