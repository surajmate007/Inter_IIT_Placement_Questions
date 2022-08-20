int findNumber(int arr[], int n)
{
 
    // Sort the given array
    sort(arr, arr + n);
 
    // Maximum number in the array
    int max = arr[n - 1];
 
    // table[i] will store the minimum number of
    // elements from the array to form i
    int table[(2 * max) + 1];
 
    table[0] = 0;
 
    for (int i = 1; i < (2 * max) + 1; i++)
        table[i] = INT_MAX;
 
    int ans = -1;
 
    // Calculate the minimum number of elements
    // from the array required to form
    // the numbers from 1 to (2 * max)
    for (int i = 1; i < (2 * max) + 1; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] <= i) {
                int res = table[i - arr[j]];
                if (res != INT_MAX && res + 1 < table[i])
                    table[i] = res + 1;
            }
        }
 
        // If there exists a number greater than
        // the maximum element of the array that can be
        // formed using the numbers of array
        if (i > arr[n - 1] && table[i] == INT_MAX) {
            ans = i;
            break;
        }
    }
 
    return ans;
}
