#include <bits/stdc++.h>
using namespace std;

int main(){
    // Use two pointers(start and end) to simulate removing elements from the front, depending on the current type(normal or reversed).
    // Track turn alternation between P1 and P2 and maintain two separate sums.
    // On each turn, pick the current "first" element using either start or end pointer, based on whether the array is reversed.
    // If the picked element is even, toggle the reversal flag — reversing the array for the next turn.
    // Continue until all elements are picked, then compare the sums of P1 and P2 for the result.
    cout <<"taking input" << endl;
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }
    int start = 0, end = n - 1;
    int p1 = 0, p2 = 0, turn = 0;
    bool reversed = false;
    while(start <= end){
        int selected;
        if(turn % 2 == 0){
            if(reversed) {p1 += v[end]; selected = v[end]; end--; }
            else{ p1 += v[start]; selected = v[start]; start++; }
        }
        else {
            if(!reversed){ p2 += v[start]; selected = v[start]; start++; }
            else {p2 += v[end]; selected = v[end]; end--; }
        }
        turn++;
        if(selected % 2 == 0) {
            reversed = !reversed; 
        }
    }
    cout << "ans is " << p1-p2 << endl;
}