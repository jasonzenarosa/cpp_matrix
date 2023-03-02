#include <iomanip>
using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

template
    <typename T> 

class Array
{
    int len;
    T * buf;

public:
    Array(int new_len) : len(new_len), buf(new T[len]){
        fill(T());
    }

    int length() const{
        return len;
    }

    T & operator [](int index) const{
        if (index < 0 || index >= len){
            throw "Exception operator[] (" + std::to_string(index) + ") Out Of Range";
        }else{
        return buf[index]; 
        }
    }

    Array(const Array & a) : len(a.len), buf(new T[len]){
        for (int i = 0; i < a.length(); i++){
            buf[i] = a.buf[i];
        }
    }

    Array<T>& operator=(const Array<T>& other) = delete;

    void fill(T val){
        for (int i=0; i < len; ++i)
            buf[i] = val; 
    }

    void print(ostream & out) const{
        for (int i=0; i < len; ++i)
            out << setw(8)
                << setprecision(2)
                << fixed
                << right
                << buf[i];
    }

    friend ostream & operator << (ostream & out, const Array & a) {
        a.print(out);
        return out;
    }

    friend ostream & operator <<(ostream & out, Array * a){
        a->print(out);
        return out;
    } 

    ~Array(){
        delete [] buf;
    }
};

#endif // ARRAY_H