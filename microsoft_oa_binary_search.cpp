#include <bits/stdc++.h>
using namespace std;

bool check(long long x, int n, vector<int>& req, vector<int>& stock, vector<int>& cost, int budget) {
    long long total_cost = 0;   
    for(int i = 0; i < n; i++) {
        long long a = req[i] * x; 
        long long b = stock[i];
        long long need = a - b;
        if(need > 0) {
            total_cost += need * cost[i];
        }
    }
    return total_cost <= budget; 
}


int main(){
    // Use Binary Search on number of units X (from 0 to 1e12).
    // For each X, calculate how much extra of each resource is needed.
    // Compute total cost of buying the extra needed items.
    // If cost ≤ budget, X is possible → try more; else try less.
    // Return max X for which total cost is within budget.
    cout <<"taking input" << endl;
    int n, budget; cin >> n >> budget;
    vector<int> req(n), stock(n), cost(n);
    for(int i = 0 ; i < n ; i++) cin >> req[i];
    for(int i = 0 ; i < n ; i++) cin >> stock[i];
    for(int i = 0 ; i < n ; i++) cin >> cost[i];

    long long low = 0, high = 1e12, ans = 0;
    while(low <= high){
        long long mid = low + (high - low) / 2;
        if(check(mid, n, req, stock, cost, budget)){
            ans = mid;
            low = mid + 1; 
        }
        else{
            high = mid - 1;
        }
    }
    cout <<"ans is "<< ans << endl;
}