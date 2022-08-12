// simple brute force based approach:

class Solution{	
	public:
	
	vector<int> findMaxGuests(int start[], int end[], int n){
	   sort(start, start+n);
	   sort(end, end+n);
	   
	   int i=1; int j=0; int cnt = 1; int res = 1; int tme = start[0];
	   
	   while(i<n and j<n){
	       if(start[i] <= end[j]){
	           cnt++; i++;
	       }
	       else{
	           cnt--; j++;
	       }
	       if(res < cnt){
	           res = cnt;
	           tme = start[i-1];
	       }
	   }
	   
	   vector<int> ans;
	   ans.push_back(res);
	   ans.push_back(tme);
	   
	   return ans;
	}
};
