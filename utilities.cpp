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
