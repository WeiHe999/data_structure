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

// 123 --> 123rd
string number_to_ordinal(int number) {
  string suffix = "th";
  if (number % 100 < 11 || number % 100 > 13) {
    switch (number % 10) {
      case 1:
        suffix = "st";
        break;
      case 2:
        suffix = "nd";
        break;
      case 3:
        suffix = "rd";
        break;
    }
  }
  return to_string(number) + suffix;
}

/*
if the last 2 digits are 11, 12, or 13, use th
else if the last 1 digit is 1, 2, or 3, use st, nd, rd;
else use th
*/
string number_to_ordinal_v2(int number) {
    string suffix;
    if (number%100==11 || number%100==12 || number%100==13) suffix = "th";
    else if (number%10==1) suffix = "st";
    else if (number%10==2) suffix = "nd";
    else if (number%10==3) suffix = "rd";
    else suffix = "th";
    return to_string(number) + suffix;
}
