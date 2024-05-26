#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::invalid_argument;

class Matrix
{
private:
    int size;
    int **p;

    void allocSpace();
public:
    Matrix();
    Matrix(int);
    Matrix(ifstream & is); // Constructor from given file (takes data from it)
    Matrix(int**, int);
    Matrix(const Matrix&);
    Matrix(Matrix&&) = delete;
    Matrix operator=(const Matrix&)=delete;
    Matrix operator=(Matrix&&)=delete;
    ~Matrix();

    int get_size();

    friend std::ostream& operator<<(std::ostream&, const Matrix&); // for check purpose

    inline int operator()(int x, int y) {return p[x][y];}  // operator that just takes (x,y) point in Matrix as you said
};

vector<int> zmiyka(Matrix);// function that returns first required sequence from given matrix

vector<int> spiral(Matrix); // function that returns second required sequence from given matrix




