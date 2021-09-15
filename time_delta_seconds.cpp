/*
input:
2000000
2010/07/28 13:00:20
*/

#include <bits/stdc++.h>
using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector < string > split (string str1)
{
  vector < string >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (word);
    }
  return vv;
}

bool check_leap_year(int years)
{
    if (years % 4 == 0)
    {
        if (years % 100 == 0)
        {
            if (years % 400 != 0) return false;
        }
        return true;
    }
    return false;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    vector <int> vec_months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long minus_s;
    cin >> minus_s; cin.ignore();
    string line;
    getline(cin, line);
    string first = line.substr(0, 10);
    string second = line.substr(11);
    int years = stoi(first.substr(0, 4));
    int months = stoi(first.substr(5, 2));
    int days = stoi(first.substr(8));
    int hours = stoi(second.substr(0, 2));
    int minutes = stoi(second.substr(3, 2));
    int seconds = stoi(second.substr(6));

    for (int i = 0; i < minus_s; i++)
    {
        seconds--;
        if (seconds < 0)
        {
            seconds = 59;
            minutes--;
        }
        if (minutes < 0)
        {
            minutes = 59;
            hours--;
        }
        if (hours < 0)
        {
            hours = 23;
            days--;
        }
        if (days < 1)
        {
            months--;
            if (months == 0)
            {
                months = 12;
                years--;
            }
            days = vec_months[months];
            if (months == 2 && check_leap_year(years) == true)
            {
                days = 29;
            }
        }
    }
    cout << minus_s << " seconds before " << line << " is:" << endl;
    cout << years << "/" << setw(2) << setfill('0') << months << "/" << setw(2) << setfill('0') << days << " " << setw(2
    ) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << endl;
}
