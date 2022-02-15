// C++ program to print all
// possible strings of length k
#include <bits/stdc++.h>
using namespace std;
	

// The main recursive method
// to print all possible
// strings of length k


void printAllKLengthRec(char set[], string prefix, int n, int k, int& tot, string g_str)
{
	
	// Base case: k is 0,
	// print prefix
	if (k == 0)
	{
		cout << (prefix) << endl;
		if (prefix <= g_str) tot++;
		return;
	}

	// One by one add all characters
	// from set and recursively
	// call for k equals to k-1
	for (int i = 0; i < n; i++)
	{
		string newPrefix;
		
		// Next character of input added
		newPrefix = prefix + set[i];
		
		// k is decreased, because
		// we have added a new character
		printAllKLengthRec(set, newPrefix, n, k - 1, tot, g_str);
	}

}

void printAllKLength(char set[], int k,int n, int & tot, string g_str)
{
	printAllKLengthRec(set, "", n, k, tot, g_str);
}

// Driver Code
int main()
{
	
	cout << "First Test" << endl;
	char set1[] = {'2', '3'};
	int k = 5;
	int tot = 0;
        string g_str = "33222";
	printAllKLength(set1, k, 2, tot, g_str);
	cout << tot << endl;
	
}

