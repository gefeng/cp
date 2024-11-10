#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector<int64_t> cnt(N, 0);
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        int c = S[i] - '0';
        int64_t l = i + 1;
        sum += l * c;
        cnt[i] += sum;
    }

    int64_t carry = 0;
    for(int i = N - 1; i >= 0; i--) {
        cnt[i] += carry;
        carry = cnt[i] / 10;
        cnt[i] %= 10;
    }

    std::string ans = carry == 0 ? "" : std::to_string(carry);
    for(int i = 0; i < N; i++) {
        ans.push_back(char(cnt[i] + '0'));
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
