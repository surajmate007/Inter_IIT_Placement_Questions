// Easy to understand solution using stack:
// Approach: The given problem can be solved using Stack. The idea is to traverse the string and store those characters in the stack in lexicographically
// largest order so as to generate the resultant string. Follow the steps below to solve the given problem:

// Store the frequency of all the characters of the string S in an array, say count[].
// Initialize an array, say visited[], that stores whether any character is present in the stack or not.
// Traverse the given string S using the variable i and perform the following steps:
// Decrement the frequency of character S[i] in the array count[] by 1.
// Now, if the character is already present in the stack, then continue to the next iteration.
// Otherwise, check if the current character is greater than the top character in the stack and the frequency of the top character is greater than 0,
// then keep popping out the top element from the stack.
// After the above steps, add the current character and mark it as visited in the array visited[].
// After completing the above steps, generate the string using the characters in the stack and print the reverse of it to get the lexicographically
// largest subsequence.


// C++ program for the above approach
 
#include <bits/stdc++.h>

using namespace std;
 
// Function to find the lexicographically
// largest subsequence consisting of all
// distinct characters of S only once

string lexicoMaxSubsequence(string s, int n)
{

    stack<char> st;
 

    // Stores if any alphabet is present

    // in the current stack

    vector<int> visited(26, 0), cnt(26, 0);
 

    // Findthe number of occurrences of

    // the character s[i]

    for (int i = 0; i < n; i++) {

        cnt[s[i] - 'a']++;

    }

    for (int i = 0; i < n; i++) {
 

        // Decrease the character count

        // in remaining string

        cnt[s[i] - 'a']--;
 

        // If character is already present

        // in the stack

        if (visited[s[i] - 'a']) {

            continue;

        }
 

        // if current character is greater

        // than last character in stack

        // then pop the top character

        while (!st.empty() && st.top() < s[i]

               && cnt[st.top() - 'a'] != 0) {

            visited[st.top() - 'a'] = 0;

            st.pop();

        }
 

        // Push the current character

        st.push(s[i]);

        visited[s[i] - 'a'] = 1;

    }
 

    // Stores the resultant string

    string s1;
 

    // Generate the string

    while (!st.empty()) {

        s1 = st.top() + s1;

        st.pop();

    }
 

    // Return the resultant string

    return s1;
}
 
// Driver Code

int main()
{

    string S = "ababc";

    int N = S.length();

    cout << lexicoMaxSubsequence(S, N);
 

    return 0;
}
