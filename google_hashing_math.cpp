#include <bits/stdc++.h>
using namespace std;

int main(){
    // given are two arrays, count pairs where b[j]%a[i] == 0
    // derive it mathematically, how its complexity is in the range
    // numbers are in the range of 10^6
    // approach is take unique numbers of a and then start making table of them and find their occurences in array b
    // 10^6/2 + 10^6/3 + ....... harmonic series
    cout <<"taking input" << endl;
    int n1 , n2;
    cin >> n1 >> n2;
    vector<int> a(n1) , b(n2);
    for(int i = 0; i < n1; i++) cin >> a[i];
    for(int i = 0; i < n2; i++) cin >> b[i];

    long long ans = 0;
    unordered_map<int, int> mp1 , mp2;
    for(int i : a) mp1[i]++;
    for(int i : b) mp2[i]++;

    for(auto itr = mp1.begin() ; itr != mp1.end() ; itr++){
        int a = itr->first , count = 0;
        for(int j = a; j <= 1e6 ; j+=a){
            count += mp2[j];
        }
        ans += count*itr->second;
    }

    cout <<"ans is "<< ans <<" ";
}