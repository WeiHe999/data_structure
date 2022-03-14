// find all k-element combinations from a n-element vector
#include <bits/stdc++.h>
using namespace std;

void combinations(int ind, int k, vector <int> vec1, vector <int> &vec2)
{
    if (vec2.size() == k)
    {
        for (int a = 0; a < vec2.size() - 1; a++) cout << vec2[a] << ", ";
        cout << vec2.back() << endl;
        return;
    }
    for (int x = ind + 1; x < vec1.size(); x++)
    {
        vector <int> vec3 = vec2;
        vec3.emplace_back(vec1[x]);
        combinations(x, k, vec1, vec3);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> vec1 = {1, 2, 3, 4, 5}, vec2;
    int k = 3;
    combinations(-1, k, vec1, vec2);
}
