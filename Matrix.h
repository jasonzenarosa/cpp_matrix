#ifndef MATRIX_H
#define MATRIX_H
using namespace std;
#include "Array.h"

template 
    <typename T>

class Matrix 
{
    int rows, cols;
    //int * * matrix;
    Array<Array<T> * > matrix;
    // Array<T> **matrix;

public:
    Matrix(int new_rows, int new_cols) : rows(new_rows), cols(new_cols), matrix(rows){
        for (int i = 0; i < rows; i++){
            matrix[i] = new Array<T>(cols);
        }
    }

    Matrix(const Matrix & a) : rows(a.rows), cols(a.cols), matrix(rows){
        for (int i = 0; i < rows; i++) {
            matrix[i] = new Array<T>(cols);
            for (int j = 0; j < cols; j++) {
                (*(matrix[i]))[j] = (*(a.matrix[i]))[j];
            }
        }
    }

    //Matrix & operator = (Matrix & a) = delete;

    Matrix & operator=(const Matrix & a) = delete;


    int num_rows() const{
        return rows;
    }

    int num_cols() const{
        return cols;
    }

    void fill(T val){
        for (int i=0; i < rows; ++i){
            for (int j = 0; j < cols; j++) {
                (*(matrix[i]))[j] = val;
            }
        }
    }

    Array<T> & operator [](int row) const{
        if (row < 0 || row >= rows){
            throw "Exception operator[] (" + std::to_string(row) + ") Out Of Range";
        }else{
            return *(matrix[row]);
        }
    }

    void print(ostream& out) const{ //!!!
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // out << matrix[i][j] << " ";
                // out << (*matrix[i])[j]  << " ";
                out << (*(matrix[i]))[j] << " ";
            }
            out << endl;
        }
    }

    friend ostream & operator << (ostream & out, const Matrix & m){
        for (int i = 0; i < m.num_rows(); i++) {
            out << m[i] << endl;
        }
        return out;
    }

    ~Matrix(){
        for (int i=0; i < rows; i++){
            delete matrix[i];
        }
    }
};

#endif // MATRIX_H
