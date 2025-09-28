#include <bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr, int k, int n, int u){
    int ans = 0;
    int i = 0, j = 0;
    unordered_map<int, int> mp;
    while(j < n){
        mp[arr[j]]++;
        while(mp.size() >= k && i <= j){
            int l = j - i + 1;
            if(l < u) {
                int end = i + u - 1;
                ans += max(0,n - end);
            }
            else ans += (n - j);
            mp[arr[i]]--;
            if(mp[arr[i]] == 0) mp.erase(arr[i]);    
            i++;
        }
        j++;
    }
    return ans;
}


int main(){
    // we are given an array and a number k
    // we need to find the number of subarrays with exact k distinct elements with length in the range [l, r]
    int t; cin >> t;
    while(t--){
        int n, k, l, r; 
        cin >> n >> k >> l >> r;
        vector<int> arr(n);
        cout << "Enter the array elements: ";
        for(int i = 0; i < n; i++) cin >> arr[i];   
        // fun will give number of subarrays with >= k distinct elements and length >= u
        // so we will call fun for k and k+1 and subtract the results -> exact k dinstinct elements
        int ansk = fun(arr, k, n, l) - fun(arr, k, n, r + 1);
        int ansk1 = fun(arr, k + 1, n, l) - fun(arr, k + 1, n, r + 1);
        int ans = ansk - ansk1;
        cout << ans << endl;
    }
}