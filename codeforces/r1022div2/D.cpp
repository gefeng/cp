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

    auto query = [](int i) {
        std::cout << "? " << i + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<int> prefix(K, 0);
    std::vector<int> suffix(K, 0);
    for(int i = 0; i < K; i++) {
        prefix[i] = query(i);
    }

    for(int i = N - K; i < N; i++) {
        suffix[i % K] = query(i);
    }

    if(prefix == suffix) {
        if(K * 2 == N) {
            std::cout << "! " << K << ' ' << K << std::endl;
        } else {
            std::cout << "! -1" << std::endl;
        }
        return;
    }

    std::vector<int> pos_1(K + 1, 0);
    std::vector<int> pos_2(K + 1, 0);
    for(int i = 0; i < K; i++) {
        pos_1[prefix[i]] = i;
        pos_2[suffix[i]] = i;
    }
    
    int offset = 0;
    for(int i = 0; i < K; i++) {
        if(prefix[i] != suffix[i]) {
            offset = i;
            break;
        }
    }

    int lo = 0;
    int hi = (N / K * K + offset < N) ? N / K : N / K - 1;
    int l = -1;
    int r = -1;
    int v_r = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int idx = mid * K + offset;

        int val = query(idx);

        if(val == suffix[idx % K]) {
            r = idx;
            v_r = val;
            hi = mid - 1;
        } else {
            l = idx;
            lo = mid + 1;
        }
    }

    int len = 0;
    int valid_l = l;
    int valid_r = r;
    for(int i = l + 1; i < r; i++) {
        if(N - 1 - i < K) {
            break;
        }
        int v = query(i);
        int x = prefix[i % K];
        if(x == v) {
            valid_l = i;
        } else {
            break;
        }
    }

    for(int i = r - 1; i > l; i--) {
        if(i < K) {
            break;
        }
        int v = query(i);
        int d = (r - i) % K;
        int x = suffix[(pos_2[v_r] - d + K) % K];
        if(x == v) {
            valid_r = i;
            if(valid_r == valid_l) {
                std::cout << "! " << -1 << std::endl;
                return;
            }
        } else {
            break;
        }
    }

    if(valid_l + 1 == valid_r) {
        len = valid_l + 1;
        std::cout << "! " << len << ' ' << N - len << std::endl;
    } else {
        std::cout << "! " << -1 << std::endl;
    }
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
