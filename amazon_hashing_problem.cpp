#include <bits/stdc++.h>
using namespace std;

/* You are given an array of N integers; 
consider all the subarrays of the array ; 
for each subarray find the count of distinct number in the subarray ; 
finally output the total count  */

int main() {
    int n; cin >> n;
    vector<int> v(n,0);
    for(int i = 0 ; i < n ; i++) {
        cin >> v[i];
    }
    vector<int> left(n) , right(n);
    unordered_map<int,int> mp;
    for(int i = 0 ; i < n ; i++){
        int element = v[i];
        if(mp.count(element) > 0){
            left[i] = mp[element];
        }
        else{
            left[i] = -1;
        }
        mp[element] = i;
    }
    mp.clear();
    for(int i = n-1 ; i >= 0 ; i--){
        int element = v[i];
        if(mp.count(element) > 0){
            right[i] = mp[element];
        }
        else{
            right[i] = n;
        }
        mp[element] = i;
    }
    
    long long ans = 0;
    // calculate for single occurence
    for(int i = 0 ; i < n ; i++){
        int prev_index = left[i], next_index = right[i];
        int contribution = (i-prev_index)*(next_index-i);
        ans += contribution;
    }

    //calculate for >= 2 occurences
    for(int i = 0 ; i < n ; i++){
        if(left[i] != -1){
            int prev_index = left[i] , right_index = right[i];
            int contribution = (prev_index + 1) * (right_index - i);
            ans += contribution;
        }
    }
    cout << ans <<" ";
}