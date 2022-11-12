#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    map<int, vector<int>> m;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;

        m[X].push_back(i);
    }

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        int L, R, X;
        cin >> L >> R >> X;
        L--;
        R--;

        if(m.find(X) == m.end()) {
            cout << 0 << '\n';
        } else {
            vector<int>& v = m[X];
            
            auto r = upper_bound(v.begin(), v.end(), R);
            auto l = lower_bound(v.begin(), v.end(), L);

            cout << r - l << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
