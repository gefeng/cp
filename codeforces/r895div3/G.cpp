#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = (int64_t)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] > 1) {
            cnt += 1;
        }
    }

    int l = -1;
    int r = -1;
    if(cnt == 0) {
        l = 0;
        r = 0;
    } else if(cnt >= 18) {
        for(int i = 0; i < N; i++) {
            if(A[i] > 1) {
                r = i;
                l = l == -1 ? i : l;
            }
        }
    } else {
        std::vector<int> pos;
        int64_t prod = 1;
        bool take_all = false;
        for(int i = 0; i < N; i++) {
            if(A[i] > 1) {
                pos.push_back(i);

                if(prod <= MAX / A[i]) {
                    prod *= A[i];
                } else {
                    take_all = true; 
                }
            }

        }

        if(take_all) {
            l = pos.front();
            r = pos.back();
        } else {
            std::vector<int64_t> psum(N + 1, 0);
            std::vector<int64_t> ppro(N + 1, 1);
            for(int i = 0; i < N; i++) {
                psum[i + 1] = psum[i] + A[i];
                ppro[i + 1] = ppro[i] * A[i];
            }

            int sz = pos.size();
            int64_t max_v = 0;
            for(int i = 0; i < sz; i++) {
                for(int j = i; j < sz; j++) {
                    int p1 = pos[i];
                    int p2 = pos[j];
                    int64_t sum = ppro[p2 + 1] / ppro[p1] + psum[p1] + psum[N] - psum[p2 + 1];
                    if(sum > max_v) {
                        max_v = sum;
                        l = p1;
                        r = p2;
                    }
                }
            }
        }
    }

    std::cout << l + 1 << ' ' << r + 1 << '\n';
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
