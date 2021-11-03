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

/*
if the last 2 digits are 11, 12, or 13, use th
else if the last 1 digit is 1, 2, or 3, use st, nd, rd;
else use th
*/
string number_to_ordinal_v2(int number)
{
    if (number % 100 == 11 || number % 100 == 12 || number % 100 == 13) return to_string(number) + "th";
    else if (number % 10 == 1) return to_string(number) + "st";
    else if (number % 10 == 2) return to_string(number) + "nd";
    else if (number % 10 == 3) return to_string(number) + "rd";
    else return to_string(number) + "th";
}
