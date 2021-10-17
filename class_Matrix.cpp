/*
Create a class called 'Matrix' containing constructor that initializes the number of rows and the number of columns of a new Matrix object. 
The Matrix class has the following information:
1 - number of rows of matrix
2 - number of columns of matrix
3 - elements of matrix (You can use 2D vector)
The Matrix class has functions for each of the following:
1 - get the number of rows
2 - get the number of columns
3 - set the elements of the matrix at a given position (i,j)
4 - adding two matrices.
You can assume that the dimensions are equal for the addition.
*/
#include <bits/stdc++.h>
using namespace std;

class Matrix
{
    private:
        vector <vector <int> > data;
        int rows, cols;
    public:
        Matrix()
        {
            data = {};
            rows = 0;
            cols = 0;
        }
        
        Matrix(vector <vector <int> > a)
        {
            data = a;
            rows = a.size();
            cols = a[0].size();
        }
        
        void print()
        {
            for (auto b : data)
            {
                for (auto c : b) cout << c << " ";
                cout << endl;
            }
        }
        
        void set_element(int i, int j, int a)
        {
            data[i][j] = a;
        }
        
        void add_matrice(Matrix a)
        {
            for (int b = 0; b < rows; b++)
            {
                for (int c = 0; c < cols; c++)
                {
                    data[b][c] += a.data[b][c];
                }
            }
        }
};

int main()
{
    vector <vector <int> > a = {{3, 4}};
    vector <vector <int> > b = {{1, 2}};
    Matrix matrix1 = Matrix(a);
    matrix1.print();
    cout << endl;
    Matrix matrix2 = Matrix(b);
    matrix2.print();
    cout << endl;
    matrix2.set_element(0, 0, 5);
    matrix2.print();
    cout << endl;
    matrix2.add_matrice(matrix1);
    matrix2.print();
    cout << endl;
    matrix2.add_matrice(matrix1);
    matrix2.print();
    cout << endl;
}
