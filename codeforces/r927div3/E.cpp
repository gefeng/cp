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
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int64_t> diff(N + 1, 0);
    for(int i = 0; i < N; i++) {
        diff[i] += S[i] - '0'; 
        diff[N] -= S[i] - '0';
    }

    std::vector<int64_t> cnt(N, 0);
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += diff[i];
        cnt[i] = sum;
    }
    
    std::string ans = "";
    int64_t carry = 0;
    for(int i = N - 1; i >= 0; i--) {
        cnt[i] += carry;
        ans.push_back((char)((cnt[i] % 10) + '0'));
        carry = cnt[i] / 10;
    }

    while(carry) {
        ans.push_back((char)((carry % 10) + '0'));
        carry /= 10;
    }

    while(ans.size() > 1) {
        if(ans.back() == '0') {
            ans.pop_back();
        } else {
            break;
        }
    }

    std::reverse(ans.begin(), ans.end());

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
