/* C++ program to count number of sub-arrays
with even sum using an efficient algorithm
Time Complexity - O(N)
Space Complexity - O(1)*/
#include <bits/stdc++.h>
using namespace std;

long long countEvenSum(int a[], int n)
{
	// Result may be large enough not to
	// fit in int;
	long long res = 0;

	// To keep track of subarrays with even sum
	// starting from index i;
	int s = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] % 2 == 1)
		{
			/* s is the count of subarrays starting from
			* index i+1 whose sum was even*/
			/*
			If a[i] is odd then all subarrays starting from
			index i+1 which was odd becomes even when a[i]
			gets added to it.
			*/
			// s is the number of even-sum subarrays starting from i+1, 
			//n - i - 1 - s is the number of add-sum subarrays starting from i+1, 
			cout << "previous s=" << s << endl;
			s = n - i - 1 - s;
		}
		else
		{
			/*
			If a[i] is even then all subarrays starting from
			index i+1 which was even remains even and one
			extra a[i] even subarray gets added to it.
			*/
			cout << "previous s=" << s << endl;
			s = s + 1;
		}
		res = res + s;
		cout << "\nat i=" << i << ", s=" << s << ", res=" << res << endl;
	}
	return res;
}

long long count_even_sum(vector<int> v1)
{
    long long tot=0, s=0;//s: the number of even-sum subarrays ended at index i
    for (long long i=0; i<v1.size(); i++)
    {
        if(v1[i]%2==0)
        {
            s = s + 1; // s+1 is the number even-sum subarrays ended at i
        }
        else
        {
            s = i-s; // i-s is the number of odd-sum subarrays ended at i
        }
        tot += s;
    }
    return tot;
}

// Driver Code
int main()
{

	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "The Number of Subarrays with even"
			" sum is "
		<< countEvenSum(arr, n) << endl;;
		
	vector<int> v1 = {1, 2, 3, 4, 5, 6};
	cout << count_even_sum(v1) << endl;
	return 0;
}

// This code is contributed by Aditya Anand

