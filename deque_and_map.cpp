/*
Mock CCC '22 Contest 1 J4 - Snowball Fight

N computer science students are having a snowball fight!

Each student has a list of targets, initially having one known target.

For every round in the fight, each student in the order  will throw a snowball to the first student in their target list, then remove the student from the front of their list. If their list is empty, they will do nothing.

There may be multiple occurrences of the same student in a student's list of targets. If the target student is on the list multiple times, only the first occurrence should be removed.

When all people have finished throwing or doing nothing for the round, students that had snowballs thrown at them this round will add whoever threw a snowball at them to the end of their list, in increasing order. For example, if students  and  threw a snowball to student , student  would add students  and  to the end of their list, in that order.

This will be repeated for  rounds, after which all the students will stop.

Determine the last student each student threw a snowball to.



Input Specification
The first line will contain  and , space-separated.

The second and last line will contain  space-separated integers between  and  inclusive, the known initial target of the -th student. No student will target themselves.

Output Specification
Output  space-separated integers between  and  inclusive, with the -th integer denoting the student that the -th student threw their last snowball to.

Sample Input
4 3
4 1 1 2
Sample Output
3 1 1 2
Explanation
In the first round, student  throws a snowball to student , students  and  throw a snowball to student , and student  throws a snowball to student .

The new target list looks like
1: {2, 3}
2: {4}
3: {}
4: {1}
In the second round, student  throws a snowball to student , student  throws a snowball to student , student  does nothing, and student  throws a snowball to student .

The new target list looks like
1: {3, 4}
2: {1}
3: {}
4: {2}
In the third round, student  throws a snowball to student , student  throws a snowball to student , student  does nothing, and student  throws a snowball to student .
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, t, a, current;
    cin >> n >> t;
    vector <int> vec_last;
    unordered_map <int, deque <pair<int, int> > > q1; //id: (id_to_throw, round_id)
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec_last.emplace_back(a);
        q1[x + 1].push_back({a, 0});
    }
    // for (auto b : q1)
    // {
    //     cout << b.first << ": ";
    //     for (auto c : b.second) 
    //     {
    //         cout << "(" << c.first << ", " << c.second << "), ";
    //     }
    //     cout << endl;
    // }
    // for (auto d : vec_last) cout << d << " ";
    // cout << endl;
    
    
    
    
    for (int y = 0; y < t; y++)
    {
        //cout << "***** round-" << y+1 << endl;
        for (int z = 1; z <= n; z++)
        {
            // cout << "z=" << z << ", m1 size=" << q1[z].size() << endl;
            // for (auto b : q1)
            // {
            //     cout << b.first << ": ";
            //     for (auto c : b.second) 
            //     {
            //         cout << "(" << c.first << ", " << c.second << "), ";
            //     }
            //     cout << endl;
            // }   
            if (q1[z].size() > 0)
            {
                if (q1[z].front().second < y+1)
                {
                    current = q1[z].front().first;
                    q1[z].pop_front();
                    q1[current].push_back({z, y+1});
                    vec_last[z - 1] = current;
                }
            }
        }
    }      
        
    for (int c = 0; c < vec_last.size(); c++)
    {
        if (c == 0) cout << vec_last[c];
        else cout << " " << vec_last[c];
    }
    cout << endl;
}
