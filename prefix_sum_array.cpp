/*
use prefix sum array to find the min number of consecutive elements to get sum >= s
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
    vector <int> vec1 = {1, 3, 5, 2, 6, 8, 3, 9}, psa = {0};
    int s = 24, low = 1, high = 2, ans = INT_MAX;
    for (int a = 0; a < vec1.size(); a++) psa.emplace_back(vec1[a] + psa.back());
    // two pointers
    while ((low < vec1.size() && high < vec1.size()) && low <= high)
    {
        if (psa[high] - psa[low - 1] >= s)
        {
            if (high - low + 1 < ans) ans = high - low + 1;
            low++;
        }
        else high++;
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
}
