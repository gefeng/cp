#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    cin >> S;

    vector<vector<int>> v(26); 
    vector<int> seq;
    int min_cost = 0;
    int n = S.length();

    for(int i = 0; i < n; i++) {
        v[S[i] - 'a'].push_back(i);
    }

    int cur = S[0] - 'a';
    while(true) {
        for(int i : v[cur]) {
            seq.push_back(i);
        } 

        if(cur == S[n - 1] - 'a') {
            break;
        }

        int sign = S[n - 1] < S[0] ? -1 : 1;
        int nxt = cur + 1 * sign;
        while(v[nxt].empty()) {
            nxt += 1 * sign;
        }
        
        min_cost += abs(nxt - cur);
        cur = nxt;
    }

    int steps = seq.size();
    cout << min_cost << ' ' << steps << '\n';
    for(int i = 0; i < steps; i++) {
        cout << seq[i] + 1 << " \n"[i == steps - 1];
    }
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
