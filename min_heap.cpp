#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;
int main()
{
    vector<pair <int, int> > v1 {{12, 18}, {15, 90}, {21, 18}, {40, 9}, {5, 100}};
    make_heap(v1.begin(), v1.end(), [](pair <int, int> a, pair <int, int> b) {return a > b;});
    for (auto a : v1)
    {
        cout << "(" << a.first << ", " << a.second << ") ";
    }
    cout << endl;
    pop_heap(v1.begin(), v1.end(), [](pair <int, int> a, pair <int, int> b) {return a > b;});
    cout << v1.back().first << ", " << v1.back().second << endl;
    v1.pop_back();
    v1.push_back({3, 89});
    make_heap(v1.begin(), v1.end(), [](pair <int, int> a, pair <int, int> b) {return a > b;});
    for (auto a : v1)
    {
        cout << "(" << a.first << ", " << a.second << ") ";
    }
    cout << endl;
}
