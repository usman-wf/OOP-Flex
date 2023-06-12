#include<iostream>
#include<fstream>
using namespace std;

void DeallocateMemory(int** matrix, const int& rows)
{
	//Deallocate matrix space
	int** temp = matrix + rows;
	for (int** i = matrix; i < temp; i++)
	{
		delete[] i;	//Delete all integer arrays which are being pointed by int pointers
	}
	delete[] matrix;
	temp = 0;
	matrix = 0;
}

void InterchangeRows(int*& row1, int*& row2)
{
	int *temp = row1;
	row1 = row2;
	row2 = temp;
	temp = 0;
	
}

void InterchangeRows(int** matrix, const int& rows, const int& cols)
{
	int row1 = 1, row2 = 3;
	cout << "\n Row 1 : " << row1;
	cout << "\n Row 2 : " << row2;
	int* Row1 = *(matrix+row1-1);
	int* Row2 = *(matrix+row2-1);
	InterchangeRows(Row1, Row2);
	*(matrix+row1-1) = Row1;
	*(matrix + row2-1) = Row2;
	Row1 = 0, Row2 = 0;
}

int** TransposeMatrix(int** matrix, const int& rows, const int& cols)
{
	int** result = 0;
	result = new int* [cols];
	int** temp = result + cols;
	for (int** i = result; i < temp; i++)
	{
		*(i) = new int [rows];
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*(*(result + j) + i) = *(*(matrix + i) + j);

		}
	}
	temp = 0;
	return result;
}


bool IsSymmetric(int** matrix, const int& rows, const int& cols)
{
	bool check = false;
	int count = 0;
	int size = rows * cols;
	int** AfterTranspose = 0;
	AfterTranspose = TransposeMatrix(matrix, rows, cols);
	int** temp1 = matrix + cols;
	for (int ** i=matrix,**n=AfterTranspose; i < temp1; i++,n++)
	{
		int* temp2 = *i + rows;
		
		for (int* j = *i,*m=*n; j < temp2; j++,m++)
		{
			if (*j == *m)
			{
				count++;
			}
		}
	}
	if (count == size)
	{
		check = true;
	}
	temp1 = 0;
	delete[] AfterTranspose;
	AfterTranspose = 0;
	return check;
}

int** AddMatrix(int** matrixA, int** matrixB, const int& rows, const int& cols)
{
	int** result = 0;
	result = new int* [rows];
	int** temp = result + rows;
	for (int** i = result; i < temp; i++)
	{
		*(i) = new int[cols];
	}

	for (int** i = result, **A = matrixA, **B = matrixB; i < temp; i++, A++, B++)
	{
		int* temp2 = *(i)+cols;

		for (int* j = *(i), *C = *(A), *D = *(B); j < temp2; j++,C++,D++)

		{
			*(j) =  *(C) + *(D);
		}
	}
	temp = 0;
	return result;
}


void OutputMatrix(int** matrix, const int& rows, const int& cols)
{
	cout << endl;
	int** temp = matrix + rows;
	for (int **i = matrix; i < temp; i++)
	{
		int* temp2 = *(i)+cols;
		for (int* j = *(i); j < temp2; j++)
		{
			cout << *(j)<<"\t";
		}
		cout << endl;
	}
	temp = 0;
}

int** InputMatrix(fstream& data, int& rows, int& cols)
{	
	data >> rows;
	data >> cols;
	int** matrix = 0;
	matrix = new int*[rows];
	int** temp = matrix + rows;
	for (int **i = matrix; i < temp; i++)
	{
		*(i) = new int[cols];
	}
	
	for (int **i =matrix ; i < temp; i++)
	{
		int* temp2 = *(i)+cols;
		for (int* j = *(i); j < temp2; j++)
		{
			data >> *(j);
		}
	}
	temp = 0;
	return matrix;
}

int main()
{
	int** TransposeA=0;
	int** TransposeC = 0;
	int** matrixA = 0;
	int** matrixB = 0;
	int** matrixC = 0;
	int** Addmatrix = 0;

	int rows = 0, cols = 0; //rows,cols after addition
	int rowsA = 0, colsA = 0;//rows,cols of A
	int rowsB = 0, colsB = 0;//rows,cols of B
	int rowsC = 0, colsC = 0;//rows,cols of C
	int Trow = 0, Tcol = 0;//to manage transpose
	bool check;

	fstream data;
	data.open("InputFile.txt", ios::in); //opening file in read mode

	matrixA = InputMatrix(data, rowsA, colsA); //reading first matrix
	cout << "Matrix A : ";
	OutputMatrix(matrixA, rowsA, colsA);  //displaying first matrix

	matrixB = InputMatrix(data, rowsB, colsB);  //reading second matrix
	cout << "\nMatrix B : ";
	OutputMatrix(matrixB, rowsB, colsB);     //displaying second matrix

	matrixC = InputMatrix(data, rowsC, colsC);   //reading third matrix
	cout << "\nMatrix C : ";
	OutputMatrix(matrixC, rowsC, colsC);    //displaying third matrix

	cout << "\nA + B : ";
	if (rowsA == rowsB && colsA == colsB) //to check if addition is possible
	{
		rows = rowsA;
		cols = colsA;
		Addmatrix = AddMatrix(matrixA, matrixB, rows, cols);
		OutputMatrix(Addmatrix, rows, cols);
	}
	else
	{
		cout << "\n Addition not possible \n";
	}

	cout << "\nA + C : ";

	if (rowsA == rowsC && colsA == colsC)  //to check if addition is possible
	{
		rows = rowsA;
		cols = colsA;
		Addmatrix = AddMatrix(matrixA, matrixC, rows, cols);
		OutputMatrix(Addmatrix, rows, cols);
	}
	else
	{
		cout << "\n Addition not possible \n";
	}

	cout << "\nTranspose of A : ";
   TransposeA = TransposeMatrix(matrixA, rowsA,colsA); //transpose of A
   Trow = colsA;
   Tcol = rowsA;
   OutputMatrix(TransposeA, Trow, Tcol);
   
   cout << "\nTranspose of C : ";
  TransposeC = TransposeMatrix(matrixC, rowsC, colsC); //transpose of C
  Trow = colsC;
  Tcol = rowsC;
  OutputMatrix(TransposeC, Trow, Tcol);
  
  check = IsSymmetric(matrixA, rowsA, colsA);  //checking symmetry of matrix

  if (check == true)
  {
	  cout << "\n Matrix A is symmetric .\n";
  }
  else
  {
	  cout << "\n Matrix A is  NOT symmetric .\n";
  }

  check = false;

  check = IsSymmetric(matrixB, rowsB, colsB); //checking symmetry of matrix

  if (check == true)
  {
	  cout << "\n Matrix B is symmetric .\n";
  }
  else
  {
	  cout << "\n Matrix B is  NOT symmetric .\n";
  }
  check = false;

  InterchangeRows(matrixA, rowsA, colsA);
  cout << "\nAfter Interchanging Rows Matrix A=\n";
  OutputMatrix(matrixA, rowsA, colsA);

    DeallocateMemory(TransposeA, rowsA);
	DeallocateMemory(TransposeC, rowsC);
    DeallocateMemory(matrixA, rowsA);
    DeallocateMemory(matrixB, rowsB);
	DeallocateMemory(matrixC, rowsC);
	DeallocateMemory(Addmatrix, rows);
	
	matrixA = 0;
	matrixB = 0;
	matrixC = 0;
    Addmatrix = 0;
	TransposeA = 0;
	TransposeC = 0;
	data.close();

	return 0;
}
