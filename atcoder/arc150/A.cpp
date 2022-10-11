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
    
    string S;
    cin >> S;
    
    vector<int> psum_0(N + 1, 0);
    vector<int> psum_1(N + 1, 0);
    
    for(int i = 1; i <= N; i++) {
        psum_0[i] = psum_0[i - 1] + (S[i - 1] == '0' ? 1 : 0);
        psum_1[i] = psum_1[i - 1] + (S[i - 1] == '1' ? 1 : 0);
    }

    int cnt = 0;
    for(int i = 0; i <= N - K; i++) {
        int cnt_0 = psum_0[i + K] - psum_0[i];
        if(cnt_0 == 0) {
            int cnt_l = psum_1[i];
            int cnt_r = psum_1[N] - psum_1[i + K];
            if(cnt_l == 0 && cnt_r == 0) {
                cnt++;
            }
        }
    }
    
    cout << (cnt == 1 ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
