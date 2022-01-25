/*
DMPG '18 G1 - Musical Chairs

There are  chairs in a circle. Exactly  of these chairs are empty and there are  students numbered from  to  standing at some of these chairs. 
Every second, each student moves forward by one chair. In particular, if they are currently standing by chair , then they will move to chair  after. 
If a student reaches an empty chair, including at the very beginning, they will sit down for the remaining time. 
Who will be the last standing student?
It is guaranteed that every student begins at a different chair.

Test case input:
7 2
2 1
6 5 4
Test case output:
3
*/



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    vector <pair <int, int> > vec1;
    cin >> n >> k;
    int a;
    //put k students and k+1 empty seats into a vector
    for (int i = 1; i <= k; i++) {
        cin >> a;
        vec1.push_back({a, 0});
    }
    for (int i = 1; i <= k + 1; i++) {
        cin >> a;
        vec1.push_back({a, i});
    }
    // sort the vector like {(2, 0), (4, 3), (4, 0), (5, 2), (6, 1)}
    sort(vec1.begin(), vec1.end(), [](pair <int, int> a, pair <int, int> b) {if (a.first == b.first) {return a > b;} else {return b > a;}});
    stack <pair <int, int> > s1;
    for (pair <int, int> b : vec1) {
        if (!s1.empty())
        {
            if (s1.top().second == 0 || b.second != 0) 
            {
                s1.push(b);
            }
            else 
            {
                s1.pop();
            }
        }
        else 
        {
            s1.push(b);
        }
    }
    
    int c = 0;
    while (!s1.empty() && s1.top().second != 0)
    {
        c = s1.top().second;
        s1.pop();
    }
    cout << c << endl;
}
