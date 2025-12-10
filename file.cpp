#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

int main(){
    vector<int> a = {1,2,3};
    int n = a.size(), k=2;
    vector<int> p(n+1,0);
    for(int i = 1; i <= n ; i++){
        p[i] += a[i-1] + p[i-1];
    }

    ordered_set s;
    unordered_map<int, int> mp;
    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        int lhs = p[i-1] - k*i;
        mp[lhs]++;
        int freq = mp[lhs]; 
        s.insert({lhs,freq});
        int d = p[i] - k*i - k;
        cout<< "d -> "<< d <<" ";
        // how many are there lesser or equal to d
        int e = s.order_of_key({d+1,0});
        count += e;
        cout <<"e -> " << e << endl << endl;
    }
    cout <<"count is "<< count << " ";
}