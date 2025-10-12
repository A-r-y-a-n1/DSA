#include <bits/stdc++.h>
using namespace std;

int main() {
    // FIND THE SHORTEST SUBARRAY WITH EQUAL FREQUENCIES OF A,B,C
    // LOGIC IS TO USE A MAP FOR A==B AND ANOTHER FOR B==C... THEREFORE 
    // IF A-B AND B-C ARE SAME AT TWO INDICES THEN THE SUBARRAY BETWEEN THEM HAS EQUAL FREQUENCIES OF A,B,C
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    map<pair<int, int>, int> mp;
    mp[{0, 0}] = -1;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        a += (s[i] == 'a');
        b += (s[i] == 'b');
        c += (s[i] == 'c');
        // Check for subarray where a, b, c frequencies are equal
        pair<int, int> key = {a - b, b - c};
        if (mp.find(key) != mp.end()) {
            int idx = mp[key];
            ans = min(ans, i - idx);
        }
        mp[key] = i;
    }
    if (ans == INT_MAX)
        cout << -1 << endl; 
    else
        cout << ans << endl;
    return 0;
}