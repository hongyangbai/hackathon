#include "utils.h"

using namespace std;

template<typename T>
class Matrix
{
	T** data;
	uint32_t nrows;
	uint32_t ncols;
public:


	Matrix() {}
	Matrix(vector<vector<T>> mat);
	Matrix(const Matrix& mat);
	Matrix(const unsigned int n, const unsigned int m);
	~Matrix();
	Matrix& operator=(const Matrix& other);
	T* operator[](unsigned int idx) const;
	Matrix operator*(const Matrix& other);

	unsigned int getRowSize() const;
	unsigned int getColSize() const;

	void print() const;

};
