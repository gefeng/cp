#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> B(Q, {0, 0});
    for(int i = 0; i < Q; i++) {
        cin >> B[i].first >> B[i].second;
    }
    
    vector<LL> psum_1(N + 1, 0LL);
    vector<LL> psum_2(N + 1, 0LL);
    for(int i = 1; i <= N; i++) {
        psum_1[i] = psum_1[i - 1] + A[i - 1];
        psum_2[i] = psum_2[i - 1] ^ A[i - 1];
    }

    LL max_f = -1LL;
    int ans_l = -1;
    int ans_r = -1;
    for(int i = 0; i < N; i++) {
        LL local_max_f = (psum_1[N] - psum_1[i]) - (psum_2[N] ^ psum_2[i]);
        
        int lo = i;
        int hi = N - 1;
        int r = N - 1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            LL f = (psum_1[mid + 1] - psum_1[i]) - (psum_2[mid + 1] ^ psum_2[i]);
            if(f == local_max_f) {
                r = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if(local_max_f > max_f) {
            max_f = local_max_f;
            ans_l = i;
            ans_r = r;
        } else if(local_max_f == max_f && ans_r - ans_l > r - i) {
            ans_l = i;
            ans_r = r;
        } 
    } 
    
    cout << ans_l + 1 << ' ' << ans_r + 1 << '\n';
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
