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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum_1(N + 1, 0);
    std::vector<int64_t> psum_2(N + 2, 0);
    for(int i = 0; i < N; i++) {
        psum_1[i + 1] = psum_1[i] + A[i];
    }
    
    for(int i = 0; i <= N; i++) {
        psum_2[i + 1] = psum_2[i] + psum_1[i];
    }

    std::vector<std::pair<int64_t, int64_t>> block(N);
    int64_t now = 0;
    for(int i = 0; i < N; i++) {
        block[i] = {now, now + N - i - 1};
        now += N - i;
    }

    // psum[st] + .. + psum[st + len - 1]
    auto get_sum_1 = [&](int st, int len) {
        return psum_2[st + len + 1] - psum_2[st + 1] - psum_1[st] * len;
    };
    
    auto get_sum_2 = [&](int st, int len) {
        return psum_2[N + 1] - psum_2[N - len + 1] - psum_1[st] * len;
    };
    
    std::vector<int64_t> psum_3(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum_3[i + 1] = psum_3[i] + get_sum_1(i, N - i);
    }
    
    auto get_sum_3 = [&](int st, int ed) {
        return psum_3[ed + 1] - psum_3[st]; 
    };

    auto get_sum_4 = [&](int i, int64_t l, int64_t r) {
        return get_sum_1(i, r - block[i].first + 1) - get_sum_1(i, l - block[i].first);
    };

    auto get_block = [&](int64_t i) {
        auto it = std::upper_bound(block.begin(), block.end(), i, [](int64_t v, const auto& x) {
                    return v < x.first;
                });
        it = std::prev(it);
        return it - block.begin();
    };

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int64_t L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        int l = get_block(L); 
        int r = get_block(R);
        int len_1 = block[l].second - L + 1;
        int len_2 = R - block[r].first + 1;

        int64_t res = 0;
        if(l == r) {
            res = get_sum_4(l, L, R);
        } else {
            res = get_sum_2(l, len_1) + get_sum_1(r, len_2);
            if(r - l > 1) {
                res += get_sum_3(l + 1, r - 1);
            }
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
