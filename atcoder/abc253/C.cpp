#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int Q;
    cin >> Q;

    map<int, int> m;
    for(int i = 0; i < Q; i++) {
        int O;
        cin >> O;

        if(O == 1) {
            int X;
            cin >> X;

            m[X] += 1;
        } else if(O == 2) {
            int X, C;
            cin >> X >> C;
            
            if(m.find(X) == m.end()) {
                continue;
            }

            int c = min(C, m[X]);
            if(m[X] == c) {
                m.erase(X); 
            } else {
                m[X] -= c;
            }
        } else {
            cout << m.rbegin()->first - m.begin()->first << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
