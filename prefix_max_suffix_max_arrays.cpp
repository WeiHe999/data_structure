/*

*/
given a vector { 5, 4, 5, 2, 3, 1, 5}
find the max value of the number of max values after excluding the elements from element 1 to element 3 [4, 5, 2]
output:
5 2 (max_value=5, occurs 2 times)

#include <bits/stdc++.h>
using namespace std;


template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

// Driver Code
int main()
{
	vector<int> v = { 5, 4, 5, 2, 3, 1, 5};

	// prefix max vector
	vector<int> pre_max(v.size() + 1, 0);
	for (int i=1; i<=v.size(); i++) {
	    pre_max[i] = max(pre_max[i-1], v[i-1]);
	}
	print(v);
	print(pre_max);
	
	// suffix max vector
	vector<int> suf_max(v.size() + 1, 0);
	for (int i=v.size()-1; i>=0; i--)
	{
	    suf_max[i] = max(suf_max[i+1], v[i]);
	}
	print(suf_max);
	
	// query: find the max value after excluding the exlements from index 2 to 4 inclusive
	int lower = 0, upper = 5; 
	cout << "pre-max = " << pre_max[lower] << endl;
	cout << "suf-max = " << suf_max[upper+1] << endl;
	int max_v = max(pre_max[lower], suf_max[upper+1]);
	cout << max_v << endl;

	return 0;
}

