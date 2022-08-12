// You are given an integer number. You have to find out the closest smaller number than it which contains all the digits of the given number
// (unless your result has leading zeroes). If your result has leading zeros, they can be omitted. If no such number can be found, return -1.

// Case 1: 
// input: 6594
// output: 6549

// Case 2: 
// input: 11112
// output: -1

// Case 3: 
// input: 1100
// output: 1010

// Case 4: 
// input: 5003
// output: 3500

// Case 5: 
// input: 3005
// output: 530


int solve(int n){
    string s=to_string(n);
    vector<int>v,v1;
    for(auto i:s)
        v.push_back(i-'0');
    int index=-1;
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]){
            index=i;
        }
    }
    if(index==-1)
        return index;
    for(int i=index+1;i<v.size();i++){
        v1.push_back(v[i]);
    }
    sort(v1.begin(),v1.end());
    int pos=prev(lower_bound(v1.begin(),v1.end(),v[index]))-v1.begin();
    for(int i=index+1;i<v.size();i++){
        if(v[i]==v1[pos]){
            pos=i;
            break;
        }
    }
    swap(v[index],v[pos]);
    sort(v.begin()+index+1,v.end());
    reverse(v.begin()+index+1,v.end());
    s="";
    for(auto i:v)
        s+=to_string(i);
    return stoi(s);
}
