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

    std::vector<std::string> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
    }

    std::vector<int> divisors;
    for(int f = 1; f * f <= N; f++) {
        if(N % f == 0) {
            divisors.push_back(f);
            if(f != N / f) {
                divisors.push_back(N / f);
            }
        }
    }

    std::vector<std::vector<int>> has(N, std::vector<int>(26, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            has[i][A[j][i] - 'a'] = 1;
        }
    }

    std::ranges::sort(divisors);

    auto is_valid = [&](int len, std::string& pattern) {
        for(int i = 0; i < len; i++) {
            bool found = false;
            for(int c = 0; c < 26; c++) {
                bool ok = true;
                for(int j = i; j < N; j += len) {
                    if(!has[j][c]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    pattern.push_back(static_cast<char>(c + 'a'));
                    found = true;
                    break;
                }
            }
            if(!found) {
                return false;
            }
        }
        return true;
    };

    std::string ans = "";
    std::string t = "";
    for(int len : divisors) {
        std::string pattern = "";
        if(is_valid(len, pattern)) {
            t = std::move(pattern);
            break;
        }
    }
    
    assert(!t.empty());
    
    for(int i = 0; i < N / t.size(); i++) {
        ans += t;
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
