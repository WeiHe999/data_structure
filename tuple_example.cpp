#include <bits/stdc++.h>

using namespace std;


int main() {
    vector< tuple<string, int, double> > students;
    students.push_back({"John", 12, 23.5});
    students.push_back({"Mike", 24, 89.3});
    students.push_back({"Jeff", 19, 92.1});
    //print
    // for(auto x: students)
    // {
    //     cout << "name=" << get<0>(x) << ", age=" << get<1>(x) << ", score=" << get<2>(x) << endl;
    // }
    // sort based on score
    sort(students.begin(), students.end(), [](tuple<string, int, double> a, tuple<string, int, double> b){
        return get<2>(a) < get<2>(b);});
    for(auto x: students)
    {
        cout << "name=" << get<0>(x) << ", age=" << get<1>(x) << ", score=" << get<2>(x) << endl;
    }
}
