#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    int tot = 0;
    for(int i = 0; i < N; i++) {
        tot += S[i] - '0';
    }
    
    int ans = tot;
    for(int i = 0; i < K; i++) {
        std::string t = "";
        int cnt = 0;
        for(int j = i; j < N; j += K) {
            t.push_back(S[j]);
            cnt += S[j] - '0';
        }

        int size = t.size();
        std::vector<int> best_on(size, 0);
        std::vector<int> best_off(size, 0);
        int cnt_one = 0;
        for(int j = size - 1; j >= 0; j--) {
            if(j == size - 1) {
                best_on[j] = t[j] == '1' ? 0 : 1;
                best_off[j] = t[j] == '0' ? 0 : 1;
            } else {
                best_on[j] = std::min(cnt_one, best_on[j + 1]) + (t[j] == '1' ? 0 : 1);
                best_off[j] = cnt_one + t[j] - '0';
            }
            cnt_one += t[j] - '0';
        }

        cnt_one = 0;
        int prefix = 0;
        for(int j = 0; j < size; j++) {
            if(j == 0) {
                prefix = t[j] == '1' ? 0 : 1;
            } else {
                prefix = std::min(cnt_one, prefix) + (t[j] == '1' ? 0 : 1);
            }
            ans = std::min(ans, tot - cnt + prefix + (j + 1 < size ? std::min(best_on[j + 1], best_off[j + 1]) : 0));
            ans = std::min(ans, tot - cnt + cnt_one + t[j] - '0' + (j + 1 < size ? std::min(best_on[j + 1], best_off[j + 1]) : 0));
            cnt_one += t[j] - '0';
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
