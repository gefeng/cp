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
    
    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for(int i = 1; i < (1 << N); i++) {
        array<int, 26> cnt{0};
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                string s = A[j];
                for(char c : s) {
                    cnt[c - 'a'] += 1;
                } 
            }
        }

        int tot = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == K) {
                tot += 1; 
            }
        }
        ans = max(ans, tot);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
