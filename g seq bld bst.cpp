#include <iostream>
using namespace std;
#define INT_MAX 100

//function to get sum of array elements 
int sum(int freq[], int i, int j) 
{ 
	int s = 0; 
	for (int k = i; k <= j; k++) 
	s += freq[k]; 
	return s; 
} 

//recursive function to calculate cost of optimal binary search tree 
int optCost(int freq[], int i, int j) 
{ 
	if (j < i) 
		return 0; 
	if (j == i)
		return freq[i]; 
	
	// Get sum of frequencies 
	int fsum = sum(freq, i, j); 
	int min = INT_MAX; 
	
	// One by one consider all elements as root and recursively find cost of the BST 
	for (int r = i; r <= j; r++) 
	{ 
		int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j); 
		if (cost < min) 
			min = cost; 
	} 
	
	// Return minimum value 
	return min + fsum; 
} 

int optimalSearchTree(int keys[], int freq[], int n) 
{ 
	return optCost(freq, 0, n - 1); 
} 

int main() 
{ 
    int num;
    cout << "Enter the number of keys: ";
    cin >> num;
	int* keys = new int[num];
	int* freq = new int[num];
    cout << "Enter the keys in ascending order." << endl;
    for (int i = 0; i < num; i++)
    {
		int k, f;
		cout << "Key: ";
        cin >> k;
		keys[i] = k;
        cout << "Frequency: ";
        cin >> f;
		freq[i] = f;
    }

	cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, num);
	
	delete[] keys;
	delete[] freq;

	return 0; 
} 

