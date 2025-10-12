#include <bits/stdc++.h>
using namespace std;

int main() {
    // FIND THE SHORTEST SUBARRAY WITH EQUAL FREQUENCIES OF A,B,C
    // LOGIC IS TO USE A MAP FOR A==B AND ANOTHER FOR B==C... THEREFORE 
    // IF A-B AND B-C ARE SAME AT TWO INDICES THEN THE SUBARRAY BETWEEN THEM HAS EQUAL FREQUENCIES OF A,B,C
    // FOLLOWUP -> Which shortest substring will you remove such that the remaining string has f(a)==f(b)==f(c) 
    // LETS SAY WE HAVE TWO ARRAYS WITH VALUES OF A-B AND B-C
    // NOW WE HAVE 3 PARTS OF THE STRING
    // t(A-B) = P1(A-B) + P2(A-B) + P3(A-B)
    // t(B-C) = P1(B-C) + P2(B-C) + P3(B-C)
    // Now if we want to remove P2 such that the remaining string has equal frequencies of A,B,C
    // therefore P1(A-B) + P3(A-B) = 0 and P1(B-C) + P3(B-C) = 0
    // therefore t(A-B) - P2(A-B) = 0 and t(B-C) - P2(B-C) = 0

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
    }
    int tab = b-a, tbc = b-c;
    // we need to find the shortest subarray with difference of a and b && b and c same as tab and tbc
    a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        a += (s[i] == 'a');
        b += (s[i] == 'b');
        c += (s[i] == 'c');
        int ab = b - a, bc = b - c;
        if (mp.find({ab - tab, bc - tbc}) != mp.end()) {
            ans = min(ans, i - mp[{ab - tab, bc - tbc}]);
        }
        mp[{ab, bc}] = i;
    }
    if (ans == INT_MAX) ans = -1;
    cout << ans << endl;
}