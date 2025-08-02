#include <bits/stdc++.h>
using namespace std;

int main(){
    // Compute prefix sums and find the first index where the sum is not divisible by x.
    // Reuse prefix sums to check maximum subarray length where sum is not divisible by x.
    // Update and print the max such length as the answer.
    cout <<"taking input" << endl;
    int n , x; cin >> n >> x;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    int ans = 0;
    unordered_map<int, int> mp;
    vector<long long> prefix_sum(n);
    int smallest_subarray_index = -1;
    for(int i = 0 ; i < n ; i++){
        prefix_sum[i] += v[i];
       if(i >= 1) prefix_sum[i] += prefix_sum[i-1];
       if(prefix_sum[i] % x != 0){
            smallest_subarray_index = i;
            break;
       }
    }
    fill(prefix_sum.begin(), prefix_sum.end(), 0);
    for(int i = 0 ; i < n ; i++){
        prefix_sum[i] += v[i];
        if(i >= 1) prefix_sum[i] += prefix_sum[i-1];
        if((prefix_sum[i] % x) != 0){
            ans = max(ans , i+1);
        }
        else{
            if(smallest_subarray_index != -1)
            ans = max(ans , i-smallest_subarray_index);
        }
    }
    cout <<"ans is "<< ans <<" ";
}
