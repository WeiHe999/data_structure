#include <bits/stdc++.h>
using namespace std;


void combinations(vector<int> prefix, int current_ind, int current_len, int tot_len, vector<int> data)
{
    if (current_len==tot_len) 
    {
        for (auto x: prefix) cout << x << ", ";
        cout << endl;
    }
    if (current_len>tot_len) return;
    // add next forward element
    for(int i=current_ind+1; i<data.size(); i++)
    {
        vector<int> new_prefix = prefix;
        new_prefix.push_back(data[i]);
        combinations(new_prefix, i, current_len+1, tot_len, data);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector<int> v1 = {1,2, 3, 4, 5};
    int k = 3;
    for (int i=0; i<v1.size(); i++)
    {
        // for the first element
        vector<int> prefix = {v1[i]};
        combinations(prefix, i, 1, k, v1);
    }
    
}
