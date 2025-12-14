#include<bits/stdc++.h>
using namespace std;

//Median in prefix subarrays

// You are given a permutation p of size n, where p[i] represents the rating of the i-th driver joining the system.
// For each prefix of this permutation (i.e., first i drivers), determine f(i) — the count of distinct ratings among the first i drivers that can act as a median of at least one subarray completely contained within that prefix.
// Formally, for each i (1 ≤ i ≤ n):
// f(i) = number of distinct elements x in p[1...i] such that x is the median of some subarray of p[1...i] and size of subarray>=2 
// You must output all f(1), f(2), ..., f(n).

// Median Trick :-> Let us say you are focusing on number ‘g’ 
// -> you are trying to check if this can be median of some set of numbers 
// -> all the numbers <g you replace them by -1 and all the numbers > g you replace them by +1 
// -> now the subarrays with sum==0 are the subarrays where ‘g’ is the median(make sure index of element g is also included in that subarray) 


int fun(vector<int>& a, int index){
    unordered_map<int,int> mp;
    int sum = 0;
    for(int i = 0 ; i < a.size() ; i++){
        sum += a[i];
        if((mp.find(sum) != mp.end()) && (mp[sum] < index) && (i - mp[sum] >= 1) && (sum == 0 || sum == 1)){
            return i;
        }
        mp[sum] = i;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++) cin >> v[i];

    vector<int> ans;
    for(int i = 0 ; i < n ; i++){
        int d = v[i];
        vector<int> a(n);
        for(int j = 0 ; j < n ; j++){
            if(d > v[j]) a[j] = -1;
            else if(d < v[j]) a[j] = 1;
            else a[j] = 0;
        }
        int min_index = fun(a,i);
        if(min_index == -1){
            ans.push_back(0);
        }
        else{
            ans.push_back(min_index);
        }
    }
    for(int i : ans) cout << i << " ";
    return 0;
}