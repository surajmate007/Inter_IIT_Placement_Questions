// We start from the sides and see that left and right sides are ending by Rs
// R W W W R W R W W R
// |                 |
// left		        right

// Number of Ws in between = 6, so in order to move two Rs from the ends to the middle we need to do 6 swaps. We add 6 to the result variable and continue.
// Now we passing all Ws until we meet next pair of Rs
// R W W W R W R W W R
//         |   |
//       left right
      
// Number of Ws in between = 1, in order to move two Rs from the ends to the middle we need to do 1 swap. We add 1 to the result variable and finish
// with the result = 7. In order to calculate how many Ws we have between Rs we should count number of all Rs in the row before start of the main algorithm.
// Finally the code will looks like this:

int solution(const string & s) {
    int red_count = 0;
    // count number of Rs in the string
    for (char c : s) {
        if (c == 'R') ++red_count;
    }
    // Init indexes to the ends of the string and the result 
    int left = 0, right = s.size() - 1, result = 0;
    // moving from the ends to the middle
  
    while (left < right) {
        // if we meet pair of Rs on the ends
        if (s[left] == 'R' && s[right] == 'R') {
            // add to the result number of Ws between of these Rs
            red_count -= 2;
            result += right - left - 1 - red_count;
            // and shrink the processing window
            ++left;
            --right;
        } 
        // pass all Ws we meet
        else if (s[left] != 'R') {
            ++left;
        } 
        else {
            --right;
        }
    }
    return result;
}
