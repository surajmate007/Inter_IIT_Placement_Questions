// Given an array arr[] of size N, the task is to count the number of subarrays having an average exactly equal to k.

Naive Approach: The simplest approach to solve the problem is to traverse all the subarrays and calculate their average.
If their average is K, then increase the answer.

// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count subarray having average
// exactly equal to K
int countKAverageSubarrays(int arr[], int n, int k){

	// To Store the final answer
	int res = 0;

	// Calculate all subarrays
	for (int L = 0; L < n; L++) {
		int sum = 0;
		for (int R = L; R < n; R++) {
			// Calculate required average
			sum += arr[R];
			int len = (R - L + 1);

			// Check if average
			// is equal to k
			if (sum % len == 0) {
				int avg = sum / len;

				// Required average found
				if (avg == k)

					// Increment res
					res++;
			}
		}
	}
	return res;
}

// Driver code
int main()
{
	// Given Input
	int K = 6;
	int arr[] = { 12, 5, 3, 10, 4, 8, 10, 12, -6, -1 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << countKAverageSubarrays(arr, N, K);
}


Efficient Approach: An efficient solution is based on the observations below:

Let there be a subarray [L, R] whose average is equal to K, then
=> K = average[L, R] = sum[0, R] – sum[0, L-1] / (R – L + 1)
=> (R – L + 1) * K = sum[0, R] – sum[0, L – 1]
=> R * k – (L – 1)* K = sum[0, R] – sum[0, L – 1]
=> sum[0, R] – R * k = sum[0, L – 1]  – (L – 1)* K

If every element is decreased by K, then the average will also decrease by K. Therefore, the average can be reduced to zero, so the problem becomes
finding the number of subarrays having average equals zero. The average zero is possible only if:
sum[0, R] – sum[0, L-1] / (R – L + 1) = 0
=> sum[0, R] = sum[0, L-1]



// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to count subarray having average
// exactly equal to K
int countKAverageSubarrays(int arr[], int n, int k){
	int result = 0, curSum = 0;

	// Store the frequency of prefix
	// sum of the array arr[]
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		// Subtract k from each element,
		// then add it to curSum
		curSum += (arr[i] - k);

		// If curSum is 0 that means
		// sum[0...i] is 0 so increment
		// res
		if (curSum == 0)
			result++;

		// Check if curSum has occurred
		// before and if it has occurred
		// before, add it's frequency to
		// res
		if (mp.find(curSum) != mp.end())
			result += mp[curSum];

		// Increment the frequency
		// of curSum
		mp[curSum]++;
	}

	// Return result
	return result;
}

// Driver code
int main(){
	// Given Input
	int K = 6;
	int arr[] = { 12, 5, 3, 10, 4, 8, 10, 12, -6, -1 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << countKAverageSubarrays(arr, N, K);
}

