#include "Matrix.h"

//template class Matrix<int>;

template<typename T>
Matrix<T>::Matrix(vector<vector<T>> mat)
{
	int n = mat.size();
	if(n == 0)	return;
	int m = mat[0].size();
	if(m == 0)	return;

	nrows = n;
	ncols = m;

	data = new T*[n];
	for(int i = 0; i < n; ++i)
		data[i] = new T[m];

	unsigned int k = 0;
	for(int i = 0; i < nrows; ++i)
		for(int j = 0; j < ncols; ++j)
			data[i][j] = mat[i][j];
}

template<typename T>
Matrix<T>::Matrix(const Matrix& mat)
{
	int n = mat.getRowSize();
	int m = mat.getColSize();
	if(n == 0 || m == 0)	return;

	nrows = n;
	ncols = m;

	data = new T*[n];
	for(int i = 0; i < n; ++i)
		data[i] = new T[m];
	for(int i = 0; i < n; ++i)
		memcpy(data[i], mat.data[i], sizeof(T)*m);
}

template<typename T>
Matrix<T>::Matrix(const unsigned int n, const unsigned int m)
{
	if(n == 0 || m == 0)	return;

	nrows = n;
	ncols = m;

	data = new T*[n];
	for(int i = 0; i < n; ++i)
		data[i] = new T[m];
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
	int n = other.getRowSize();
	int m = other.getColSize();
	if(n == 0 || m == 0)	return *this;

	nrows = n;
	ncols = m;

	for(int i = 0; i < nrows; ++i)
		delete[] data[i];
	delete[] data;

	data = new T*[n];
	for(int i = 0; i < n; ++i)
		data[i] = new T[m];
	for(int i = 0; i < n; ++i)
		memcpy(data[i], other.data[i], sizeof(T)*m);

	return *this;
}

template<typename T>
T* Matrix<T>::operator[](unsigned int idx) const
{
	return data[idx];
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other)
{
	int n1 = this->nrows;
	int m1 = this->ncols;
	int n2 = other.nrows;
	int m2 = other.ncols;
	assert(m1 == n2);
	
	Matrix res(n1, m2);

	cout<<res.getRowSize()<<endl;

	int l = 0;
	for(int i = 0; i < n1; ++i)
	{
		for(int j = 0; j < m2; ++j)
		{
			for(int k = 0; k < m1; ++k)
				res.data[i][j] += this->data[i][k]*other[k][j];
		}
	}


	return res;
}

template<>
void Matrix<int>::print() const
{
	for(int i = 0; i < nrows; ++i)
	{
		printf("[");
		for(int j = 0; j < ncols; ++j)
		{
			if(j < (ncols-1))
				printf("%d, ", data[i][j]); 
			else
				printf("%d", data[i][j]);
		}
		printf("]\n");
	}
}

template<>
void Matrix<float>::print() const
{
	for(int i = 0; i < nrows; ++i)
	{
		printf("[");
		for(int j = 0; j < ncols; ++j)
		{
			if(j < (ncols-1))
				printf("%f, ", data[i][j]); 
			else
				printf("%f", data[i][j]);
		}
		printf("]\n");
	}
}

template<typename T>
Matrix<T>::~Matrix()
{
	for(int i = 0; i < nrows; ++i)
		delete[] data[i];
	delete[] data;
}
	
template<typename T>
unsigned int Matrix<T>::getRowSize() const
{
	return (unsigned int)nrows;
}
	
template<typename T>
unsigned int Matrix<T>::getColSize() const
{
	return (unsigned int)ncols;
}

template class Matrix<int>;
template class Matrix<float>;
