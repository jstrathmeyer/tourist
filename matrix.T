/* matrix: template to store rectangular arrays */

#ifndef MATRIX_T
#define MATRIX_T

#include <assert.h>

template<typename T> class Matrix {
 public:
	Matrix(unsigned nrows, unsigned ncols);
	~Matrix();

	T & operator() (unsigned i, unsigned j);

 private:
	unsigned nrows, ncols;
	T * data;
};

template<typename T> Matrix<T>::Matrix(unsigned nrows, unsigned ncols)
	: nrows(nrows), ncols(ncols), data(new T[nrows * ncols]) { }

template<typename T> Matrix<T>::~Matrix() {
	delete [] data;
}

template<typename T> T & Matrix<T>::operator() (unsigned i, unsigned j) {
	assert( i < nrows && j < ncols );
	return data[i*ncols+j];
}

#endif
