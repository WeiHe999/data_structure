/*
permute to length-3 strings using only chars {'2', '3},
result:
222
223
232
233
322
323
332
333
*/

#include <bits/stdc++.h>
using namespace std;

void permute(vector<char> v1, string prefix, int tot_len)
{
    if (prefix.size()==tot_len)
    {
        cout << prefix << endl;
        return;
    }
    else
    {
        for (auto x: v1)
        {
            string new_prefix = prefix + x;
            permute(v1, new_prefix, tot_len);
        }
    }
}

int main() {
    vector<char> v1 = {'2', '3'};
    permute(v1, "", 3);
}
