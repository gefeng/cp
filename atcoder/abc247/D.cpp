#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using LL = long long;

void run_case() {
    int Q;
    cin >> Q;

    queue<pair<LL, LL>> q;
    
    for(int i = 0; i < Q; i++) {
        int O;
        cin >> O;

        if(O == 1) {
            LL X;
            LL C;
            cin >> X >> C;
            
            q.emplace(X, C);
        } else {
            LL C;
            cin >> C;

            LL ans = 0LL;
            while(C) {
                LL d = min(C, q.front().second);
                
                ans += d * q.front().first;
                
                if(q.front().second - d == 0) {
                    q.pop();
                } else {
                    q.front().second -= d;
                }

                C -= d;
            }
            
            cout << ans << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
