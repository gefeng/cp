#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <deque>
#include <map>

constexpr int MAX_T = 2000;
constexpr int64_t MOD = int64_t(16777216);

void run_case() {
    std::vector<int64_t> A;
    for(std::string S; std::getline(std::cin, S); ) {
        A.push_back(stoi(S));
    }

    auto gen = [](int64_t x) {
        x ^= (x * 64);
        x %= MOD;     
        x ^= x / 32;
        x %= MOD;
        x ^= x * 2048;
        x %= MOD;
        return x;
    }; 

    auto hash = [](std::deque<int64_t>& seq) {
        std::string s = "";
        for(int64_t x : seq) {
            s.append(std::to_string(x));
            s.push_back('-');
        }
        return s;
    };

    int64_t ans = 0;
    std::map<std::string, int64_t> m;
    for(int64_t x : A) {
        std::vector<int64_t> val;
        std::map<std::string, int64_t> lm;

        val.push_back(x);
        for(int i = 0; i < MAX_T; i++) {
            x = gen(x);
            val.push_back(x);
        }

        int size = val.size();
        std::deque<int64_t> seq;
        for(int i = 1; i < size; i++) {
            int d = val[i] % 10 - val[i - 1] % 10;
            seq.push_back(d);
            if(seq.size() > 4) {
                seq.pop_front();
            }

            if(seq.size() == 4) {
                std::string key = hash(seq);
                if(lm.find(key) == lm.end()) {
                    lm[key] += val[i] % 10;
                }
            }
        }

        for(auto& [key, cnt] : lm) {
            m[key] += cnt;
        }
    }

    for(auto& [_, x] : m) {
        ans = std::max(ans, x);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
