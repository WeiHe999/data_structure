/*
sample input:
4 3
1 a
2 e i
1 j
1 m

output:
a
ae
aej
aem
ai
aij
aim
aj
ajm
am
*/

#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

void generate_words(string prefix, int current_len, int max_len, int current_level, int max_level, unordered_map<int, vector<char> > map1)
{
    if(current_len > 0 && current_len <= max_len)
    {
        cout << prefix << endl;
    }
   if (current_len > max_len)
    {
        return;
    }

    for (int k=current_level+1; k<=max_level; k++)
    {
        for (auto x: map1[k])
        {
            string new_prefix = prefix + x;
            generate_words(new_prefix, current_len+1, max_len, k, max_level, map1);
        }
    }
    
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, max_len, num_c, ind=0;
    char c;
    unordered_map<int, vector<char> > map1;
    cin >> n >> max_len;
    for (int i=0; i<n; i++)
    {
        ind ++;
        cin>>num_c;
        for(int j=0; j<num_c; j++)
        {
            cin >> c;
            map1[ind].push_back(c);
        }
    }
    
    //chaeck inputs
    // cout << "number of rules:" << n << ", max len of words=" << max_len << endl;
    // for (auto x: map1)
    // {
    //     cout << x.first << ": ";
    //     print(x.second);
    // }
    for (auto x: map1[1])
    {
        string pre;
        pre.push_back(x);
        //cout << pre << endl;
        generate_words(pre, 1, max_len, 1, n, map1);
    }
    
}
