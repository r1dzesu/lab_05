#include "simple.h"

void Matrix::allocSpace()
{
    p = new int*[size];
    for (int i = 0; i < size; ++i) {
        p[i] = new int[size];
    }
}

Matrix::Matrix(int size_): size(size_)
{
    allocSpace();
    for(int i =0; i < size; ++i)
    {
        for(int j =0; j < size; ++j)
        {
            p[i][j] = 0;
        }
    }
}

Matrix::Matrix(int** arr_, int size_): size(size_)
{
    allocSpace();
    for(int i=0; i < size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            p[i][j] = arr_[i][j];
        }
    }
}

Matrix::Matrix() : size(1)
{
    allocSpace();
    p[0][0] = 0;
}

Matrix::Matrix(const Matrix& m) : size(m.size)
{
    allocSpace();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            p[i][j] = m.p[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < size; ++i) {
        delete[] p[i];
    }
    delete[] p;
}

Matrix::Matrix(ifstream & is)
{
    int temp;
    if(!(is >> temp)) throw invalid_argument("Wrong character, check in.txt");

    this->size = temp;
    
    allocSpace();

    for(int i = 0; i < this->size; ++i)
    {
        for(int j = 0; j < this->size; ++j)
        {
            if(!(is>>temp)) throw invalid_argument("Wrong character or amount, check in.txt");
            p[i][j] = temp;
        } 
    }
} 

ostream& operator<<(ostream& os, const Matrix& m)
{
    for (int i = 0; i < m.size; ++i) {
        os << m.p[i][0];
        for (int j = 1; j < m.size; ++j) {
            os << " " << m.p[i][j];
        }
        os << std::endl;
    }
    return os;
}

int Matrix::get_size()
{
    return this->size;
}


vector<int> first(Matrix arr) // just simple algorighm that uses o(n^2)
{
    int N = arr.get_size();
    int even = 0;
    if(N%2 == 0) even = 1; 
    vector<int> sequence;
    for(int j=0; j<=N/6; ++j)
    {
        //sequence.push_back(arr[N-1-2*j][N/2-1-2*j]);
        for(int i = N/2-even-2*j; i >=j; --i)
        {
            sequence.push_back(arr(N-1-j,i));
        }
        for(int i = N-2-j; i>=N/2+2*j; --i)
        {
            sequence.push_back(arr(i,j));
        }
        for(int i = N/2 + 1 + 2*j; i < N-1-j; ++i)
        {
            sequence.push_back(arr(i,i-N/2-j));
        }
    }
    return sequence;
}

vector<int> second(Matrix arr)
{
    int N = arr.get_size();
    // int even = 0;
    // if(N%2 == 0) even = 1;
    vector<int> sequence;
    for(int j = 0; j < N/2 + N%2; ++j)
    {
       if(j%2 == 0) for(int i = N/2 + j; i < N; ++i)
       {
            sequence.push_back(arr(j,i));
       }
       else for(int i = N-1; i> N/2 - 1 + j; --i)
       {
            sequence.push_back(arr(j,i));
       }
    }
    return sequence;
}

vector<int> zmiyka(Matrix arr)
{
    int N = arr.get_size();
    vector<int> sequence;
    for(int j=0; j< N/2 + N%2; j++)
    {
        if(j%2 == 0) for(int i = N/2 + (N%2-1) - j; i >= 0; --i)
        {
            sequence.push_back(arr(N-1-j,i));
        }
        else for(int i = 0; i <= N/2 +(N%2-1) - j; ++i)
        {
            sequence.push_back(arr(N-1-j,i));
        }
    }
    return sequence;
}

vector<int> spiral(Matrix arr)
{
    int N = arr.get_size();
    int even = 0;
    if(N%2 == 0) even = 1; 
    vector<int> sequence;
    int counter = 0;
    for(int j=0; j<=N/6; ++j)
    {
        //sequence.push_back(arr[N-1-2*j][N/2-1-2*j]);
        for(int i = N/2+2*j; i <= N - 1 - j; ++i)
        {
            sequence.push_back(arr(i,N-1-j));
        }
        for(int i = N-2-j; i>=N/2+2*j; --i)
        {
            sequence.push_back(arr(N-1-j,i));
        }
        for(int i = N/2 + 1 + 2*j; i < N-1-j; ++i)
        {
            sequence.push_back(arr(N-1-(i-N/2)+j,i));
        }
    }
    return sequence;
}