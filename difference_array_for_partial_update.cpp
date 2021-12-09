/*
use second order difference array to solve partial update with arithmeic sequence
*/

#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

vector <string> split (string str1)
{
    vector <string> vv;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vv.emplace_back(word);
    return vv;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> vec1 = {2, 3, 1, 5, 6, 7, 4}, vec2(vec1.size(), 0), vec3 = {0}, vec4 = {0};
    vector <vector <int> > ops = {{2, 4, 3}};
    for (auto x : ops)
    {
        vec2[x[0] - 1] += x[2];
        vec2[x[1]] -= (x[1] - x[0] + 2) * x[2];
        vec2[x[1] + 1] += (x[1] - x[0] + 1) * x[2];
    }
    for (int a = 0; a < vec2.size() - 1; a++) vec3.emplace_back(vec3[a] + vec2[a + 1]);
    for (int a = 0; a < vec3.size() - 1; a++) vec4.emplace_back(vec4[a] + vec3[a + 1]);
    for (int a = 0; a < vec4.size(); a++) cout << vec4[a] + vec1[a] << " ";
}
