#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int p = 0;
    while(p < N && S[p] == '0') {
        p++;    
    }
    
    string a = S.substr(p, N - p);
    int m = a.length();
    
    string ans = a;
    for(int t = 1; t <= min(10, m - 1); t++) {
        string b = a.substr(0, m - t);
        string c = a.substr(0, t);

        for(int i = 0; i < m - t; i++) {
            if(a[i + t] != b[i]) {
                c.push_back('1');
            } else {
                c.push_back(b[i]);
            }
        }

        if(c > ans) {
            ans = c;
        }
    }

    cout << (ans.empty() ? "0" : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
