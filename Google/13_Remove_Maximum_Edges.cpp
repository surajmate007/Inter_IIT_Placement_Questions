// Link : https://leetcode.com/discuss/interview-question/2401866/Google-or-OA-or-Remove-maximum-edges
// Use the logic of Post order DFS in calculating subtreesum and the count components.
vector<vector<int>> graph;
vector<int> nums; // value of nodes
vector<int> subtreeSum; // sum of subtree rooted at current node
vector<int> componentsBelow; // components made in subtree of current node, for given factor
int targetSum, totalComponents;


// recursively calculating subtree sum rooted at each node
void calculateSubtreeSum(int current, int parent) {
    subtreeSum[current] = nums[current];
    for(int child : graph[current]) {
        if(child != parent) { // go only to children subtrees of current node
            calculateSubtreeSum(child, current);
            subtreeSum[current] += subtreeSum[child];
        }
    }
}


// count components that can be made in subtree of current node, 
// such that all have sum of values = targetSum
void countComponents(int current, int parent) {
    // division at current node
    if(subtreeSum[current] == targetSum) {
        componentsBelow[current] = 1;
        totalComponents++;
        return;
    }
    
    // count all divisions in subtrees
    for(int child : graph[current]) {
        if(child != parent) {
            countComponents(child, current);
            componentsBelow[current] += componentsBelow[child];
        }
    }
    
    // sum of nodes left in subtree after component divisions == targetSum means one more division
    if(subtreeSum[current] - (componentsBelow[current] * targetSum) == targetSum) {
        componentsBelow[current]++;
        totalComponents++;
    }
}


int main() {
    // input and driver code
    int n, totalSum = 0, u, v; 
    vector<int> factors;
    
    cin >> n;
    nums.resize(n+1);
    graph.resize(n+1, vector<int>());
    subtreeSum.resize(n+1);
    
    for(int i = 1; i <= n; ++i) {
        cin >> nums[i];
        totalSum += nums[i];
    }
    
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // calculating all factors of totalSum
    for(int factor = 1; factor <= sqrt(totalSum); ++factor) {
        if(totalSum % factor == 0) factors.push_back(factor);
        if(factor != (totalSum / factor)) factors.push_back(totalSum / factor);
    }
    sort(factors.begin(), factors.end());
    
    calculateSubtreeSum(1, 0); // pre computation of subtree sum
    
    // we start from smallest factor, and stop when we get any valid division
    // because smallest factor => most components, so it's optimal
    for(int factor : factors) {
        targetSum = factor;
        totalComponents = 0;
        componentsBelow.assign(n+1, 0);
        
        countComponents(1, 0); // pre computation of valid components for each subtree
        // if this division is valid
        if(totalComponents * factor == totalSum) {
            // we need to remove x-1 edges to break tree into x components
            cout << totalComponents - 1 << '\n';
            return 0;
        }
    }
    
    // if no division was valid, we don't remove any edge
    cout << "0\n";
    return 0;
}

