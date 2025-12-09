#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1,2,3};
    int n = a.size(), k=2;
    vector<int> p(n+1,0);
    for(int i = 1; i <= n ; i++){
        p[i] += a[i-1] + p[i-1];
    }

    multiset<int> s;
    int count = 0;
    for(int i = 1 ; i <= n ; i++){
        s.insert(p[i-1] - k*i);
        int d = p[i] - k*i - k;
        cout<< "d -> "<< d <<" ";
        // how many are there lesser or equal to d
        int e = distance(s.begin(), s.upper_bound(d));
        count += e;
        cout <<"e -> " << e << endl << endl;
    }
    cout <<"count is "<< count << " ";
}