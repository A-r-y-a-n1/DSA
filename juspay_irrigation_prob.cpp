#include <bits/stdc++.h>
using namespace std;

bool check(int mid , vector<int>& capacity , vector<int>& time_delay , int g){
    int total = 0;
    for(int i = 0 ; i < capacity.size() ; i++){
        total += ceil((1.0*mid)/time_delay[i])*capacity[i];
    }
    return ((total) >= (g));
}

int main(){
    cout <<"enter details " << endl;
    int n,g; cin >> n >> g;
    vector<int> capacity(n), time_delay(n);
    for(int i = 0 ; i < n ; i++) cin >> capacity[i];
    for(int i = 0 ; i < n ; i++) cin >> time_delay[i];
    // minimum days to get total water equal to g or more than g
    // binary search on days
    int low = 1 , high = 1e9 , ans = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(check(mid,capacity,time_delay, g)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    cout <<"ans is " << ans <<" ";
}