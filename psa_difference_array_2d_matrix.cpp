/*
2-D Permutations
N*M 2D array with elements from 1 to N*M, in each row, A[i,j] > A[i,(j-1)], in each col, A[i,j] > A[i-1,j] 
q queries, for each query q_i, find the number of cells that q_i can be placed int
input:
5 5 1
18
5*5 matrix, find the number of cells that 18 can be placed in

output:
11
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, q, a;
    cin >> n >> m >> q;
    vector <vector <int> > grid(n, vector <int>(m));
    //da: difference array, psa: partial sum array
    vector <int> da(n * m + 1), psa = {0};
    for (int x = 1; x <= grid.size(); x++)
    {
        for (int y = 1; y <= grid[0].size(); y++)
        {
            da[x * y - 1]++;
            da[(n * m) - ((n - x + 1) * (m - y + 1) - 1)]--;
        }
    }
    for (int z = 0; z < da.size() - 1; z++)
    {
        psa.emplace_back(psa[z] + da[z]);
    }
    // q queries
    for (int b = 0; b < q; b++)
    {
        cin >> a;
        cout << psa[a] << endl;
    }
}

