#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    int cnt_l = 0;
    int cnt_r = 0;
    for(auto& p : A) {
        int l = p.first;
        int r = p.second;

        if(l == K && r == K) {
            cout << "YES" << '\n';
            return;
        }

        if(l == K) {
            cnt_l += 1;
        }
        if(r == K) {
            cnt_r += 1;
        }
    }

    if(cnt_l && cnt_r) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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
