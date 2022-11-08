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

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 1e9;
    for(int t = 0; t < 10; t++) {
        vector<int> cnt(10, 0);
        for(int i = 0; i < N; i++) {
            string s = A[i];
            for(int j = 0; j < 10; j++) {
                if(t == s[j] - '0') {
                    cnt[j] += 1;
                    break;
                }
            }
        }

        int cur_t = 0;
        while(true) {
            bool finish = true;
            for(int i = 0; i < 10; i++) {
                if(cnt[i] != 0) {
                    finish = false;
                    break;
                }
            }
            if(finish) {
                break;
            }

            if(cnt[cur_t % 10]) {
                cnt[cur_t % 10] -= 1; 
            }

            cur_t += 1;
        } 
        
        ans = min(ans, cur_t - 1);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
