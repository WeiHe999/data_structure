/*
input:
6 1000
1 2 3 4 5 6
input a sequence of 6, perform 1000 times of operations, each operation consists of two steps: 
1) reverse from element 1 to 4, 2) reverse from element 3 to 6
Find the final sequence
*/

#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, a;
    cin >> n >> k;
    vector <long long> vec1 = {0};
    unordered_map <long long, long long> m1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    unordered_set <long long> visited;
    vector <long long> ans(n + 1);
    reverse(vec1.begin() + 1, vec1.begin() + 5);
    reverse(vec1.begin() + 3, vec1.end());
    for (long long b = 1; b < vec1.size(); b++)
    {
        m1[vec1[b]] = b;
    }
    for (long long i = 1; i <= n; i++)
    {
        if (visited.count(i)) continue;
        vector <long long> vec3;
        for (long long cur = i; !visited.count(cur); cur = m1[cur])
        {
            vec3.emplace_back(cur);
            visited.insert(cur);
        }
        long long rem = k % vec3.size();
        for (long long j = 0; j < vec3.size(); j++)
        {
            ans[vec3[(j + rem) % vec3.size()]] = vec3[j];
        }
    }
    for (long long g = 1; g < ans.size(); g++)
    {
        cout << ans[g] << " ";
    }
    cout << endl;
}
