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
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> ans(N, -1);
    vector<int> next(N + 1, -1);
    map<int, int> piles;

    for(int i = 0; i < N; i++) {
        auto it = piles.upper_bound(A[i]);
        if(it == piles.end()) {
            piles[A[i]] = 1;
        } else {
            piles[A[i]] = it->second + 1;
            next[A[i]] = it->first;
            piles.erase(it);
        }

        if(piles[A[i]] == K) {
            int cur = A[i];
            while(cur > 0) {
                ans[cur - 1] = i + 1;
                cur = next[cur];
            }
            piles.erase(A[i]);
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
