#include <iostream>
using namespace std;

#include "Matrix.h"

template 
    <typename FN>

void fill_with_fn(Array<int> & a, FN fn){
    for (int i=0; i < a.length(); ++i)
        a[i] = fn(i);
}

template 
    <typename FN>

void fill_with_fn(Matrix<int> & m, FN fn){
    for (int i = 0; i < m.num_rows(); i++) {
        for (int j = 0; j < m.num_cols(); j++) {
            m[i][j] = fn(i, j);
        }
    }
}

void test_int_array(){
    Array<int> a{10};
    auto fn = [](int i){return i+1;};
    a.fill(int());
    //cout << a << endl;
    fill_with_fn(a, fn);
    cout << a << endl;
    cout << endl;
}

void test_int_matrix(){
    Matrix<int> m(4, 4);
    Matrix<int> m_copy(m);
    auto fn = [](int i, int j) {return (i+1) * (j+1);};
    fill_with_fn(m, fn);
    cout << m << endl;
    cout << endl;
}

// void test_double_array(){
//     Array<double> a{10};
//     auto fn = [](int i){return double(i)/2;};
//     a.fill(double());
//     cout << a << endl;
//     fill_with_fn(a, fn);
//     cout << a << endl;
//     cout << endl;
// }

// void test_double_matrix(){
//     Matrix<double> m(3, 3);
//     auto fn = [](int i, int j) { return double(i) + double(j)/2; };
//     fill_with_fn(m, fn);
//     std::cout << m << std::endl;
// }

// void test_char_array(){
//     Array<char> a{5};
//     auto fn = [](int i){return char('a' + i);};
//     a.fill(char());
//     cout << a << endl;
//     fill_with_fn(a, fn);
//     cout << a << endl;
//     cout << endl;
// }

// void test_char_matrix(){
//     Matrix<char> m(3, 3);
//     auto fn = [](int i, int j) { return char('a' + i + j)};
//}

// void test_double_array(){}

// void test_double_matrix(){}

// void test_char_array(){}

// void test_char_matrix(){}

//void test_exceptions(){}

//void test_extras(){}

#define N 1

int main()
{
    for (int i=1; i <= N; ++i){
        test_int_array();
        test_int_matrix();
        //test all others
    }
}