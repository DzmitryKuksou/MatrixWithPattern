#include<iostream>
using namespace std;
template<typename Type> 
class Matrix;
template<typename Type>
istream& operator>>(istream& s, Matrix<Type>& a);
template<typename Type>
ostream& operator<<(ostream& s, Matrix<Type>& a);
template<typename Type>
class Matrix
{
public:
	Matrix();
	Matrix(Type**, int);
	Matrix(int);
	Matrix(const Matrix&);
	~Matrix();
	void operator =(Matrix&);
	Matrix operator +(Matrix&)const;
	friend Matrix operator -(Matrix&, Matrix&);
	friend Matrix operator *(const Matrix<Type>&, const Matrix<Type>&);
	friend istream& operator>> (istream&, Matrix<Type>&);
	friend ostream& operator<< (ostream&, Matrix<Type>&);
	void EnterTheMatrix();
	void DisplayMatrix();
	bool IsSizesEqual(Matrix, Matrix)const;
private:
	void SetSize(int);
	void SetMatrix(Type**);
	void InitMatrix(int);
private:
	Type** matrix;
	int Size;
};
template<typename Type>
Matrix<Type>::Matrix()
{
	Size = 0;
	matrix = NULL;
}
template<typename Type>
Matrix<Type>::Matrix(int size)
{
	SetSize(size);
	InitMatrix(size);
}
template<typename Type>
Matrix<Type>::Matrix(Type** a, int size)
{
	SetSize(size);
	SetMatrix(a);
}
template<typename Type>
Matrix<Type>::Matrix(const Matrix<Type>& a)
{
	SetSize(a.Size);
	SetMatrix(a.matrix);
}
template<typename Type>
void Matrix<Type>::InitMatrix(int size)
{
	matrix = new Type*[Size];
	for (int i = 0; i < Size; i++)
	{
		matrix[i] = new Type[Size];
	}
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
		{
			matrix[i][j] = 0;
		}
}
template<typename Type>
void Matrix<Type>::SetMatrix(Type** a)
{
	for (int i = 0; i < Size; i++)
		for (int j = 0; j < Size; j++)
		{
			matrix[i][j] = a[i][j];
		}
}
template<typename Type>
void Matrix<Type>::SetSize(int size)
{
	Size = size;
	InitMatrix(size);
}
template<typename Type>
Matrix<Type>::~Matrix()
{
	delete[]matrix;
	Size = 0;
}
template<typename Type>
void Matrix<Type>::operator =(Matrix<Type>& a)
{
	SetSize(a.Size);
	SetMatrix(a.matrix);
}
template<typename Type>
Matrix<Type> Matrix<Type>::operator +(Matrix<Type>& a)const
{
	Matrix<a> c(a.Size);
	for (int i = 0; i < a.Size; i++)
	{
		for (int j = 0; j < a.Size; j++)
		{
			c.matrix[i][j] = matrix[i][j] + a.matrix[i][j];
		}
	}
	return c;
}
template<typename Type>
Matrix<Type> operator *(const Matrix<Type>& a, const Matrix<Type>& b)
{
	Matrix<Type> c(a.Size);
	for (int j1 = 0; j1 < a.Size; j1++)
	{
		for (int j2 = 0; j2 < a.Size; j2++)
		{
			for (int i5 = 0; i5 < a.Size; i5++)
			{
				c.matrix[j1][j2] += a.matrix[j1][i5] * b.matrix[i5][j2];
			}
		}
	}
	return c;

}
template<typename Type>
Matrix<Type> operator -(Matrix<Type>& a, Matrix<Type>& b)
{
	Matrix<Type> c(a.Size);
	for (int i = 0; i < a.Size; i++)
		for (int j = 0; j < a.Size; j++)
			c.matrix[i][j] = a.matrix[i][j] - b.matrix[i][j];
	return a;
}
template<typename Type>
void Matrix<Type>::DisplayMatrix()
{
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
template<typename Type>
void Matrix<Type>::EnterTheMatrix()
{
	cout << "Size:";
	cin >> Size;
	SetSize(Size);
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
template<typename Type>
bool Matrix<Type>::IsSizesEqual(Matrix<Type> a, Matrix<Type> b)const
{
	if (a.Size == b.Size)return 1;
	return 0;
}
template<typename Type>
istream& operator>>(istream& s, Matrix<Type> &d)
{
	cout << "EnterTheSize:";
	cin >> d.Size;
	d.SetSize(d.Size);
	for (int i = 0; i < d.Size; i++)
	{
		for (int j = 0; j < d.Size; j++)
		{
			s >> d.matrix[i][j];
		}
	}
	return s;
}
template<typename Type>
ostream& operator<<(ostream& s, Matrix<Type>& d)
{
	for (int i = 0; i < d.Size; i++)
	{
		for (int j = 0; j < d.Size; j++)
		{
			s << d.matrix[i][j] << " ";
		}
		s << endl;
	}

	return s;
}