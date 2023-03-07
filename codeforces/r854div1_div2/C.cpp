#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

string solve(string S) {
    int sz = S.size();
    if(sz == 1) {
        return S;
    }
    if(sz == 2) {
        swap(S[0], S[1]);
        return S;
    }
    if(S[0] == S[sz - 1]) {
        return S;
    }

    int i = 0;
    while(i < sz && S[i] == S[0]) {
        i += 1;
    }

    string t = solve(S.substr(i, sz - i));

    string res = "";
    if(i % 2 == 0) {
        res = S.substr(0, i / 2) + t + S.substr(0, i / 2); 
    } else {
        int szt = t.size();
        string cand1 = S.substr(0, i / 2) + 
            t.substr(0, (szt + 1) / 2) + S.substr(0, 1) + t.substr((szt + 1) / 2, szt / 2) + 
            S.substr(0, i / 2);
        string cand2 = S.substr(0, i / 2) + S.substr(i, sz - i) + S.substr(0, 1) +
            S.substr(0, i / 2);
        
        res = min(cand1, cand2);
    }
    return res;
}

void run_case() {
    string S;
    cin >> S;
    
    sort(S.begin(), S.end());

    cout << solve(S) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
