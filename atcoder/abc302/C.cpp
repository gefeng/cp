#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    auto is_ok = [&]() {
        for(int i = 0; i < N - 1; i++) {
            std::string s = A[i];
            std::string t = A[i + 1];

            std::array<int, 26> cnt = {};
            for(int j = 0; j < M; j++) {
                cnt[s[j] - 'a'] += 1;
                cnt[t[j] - 'a'] -= 1;
            }

            int cnt1 = 0;
            int cnt2 = 0;
            for(int j = 0; j < 26; j++) {
                if(cnt[j] > 1 || cnt[j] < -1) {
                    return false;
                }
                if(cnt[j] == 1) {
                    cnt1++;
                }
                if(cnt[j] == -1) {
                    cnt2++;
                }
            }

            if(cnt1 != 1 || cnt2 != 1) {
                return false;
            }
        }

        return true;
    };

    do {
        if(is_ok()) {
            std::cout << "Yes" << '\n';
            return;
        } 
    } while(std::next_permutation(A.begin(), A.end()));

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
