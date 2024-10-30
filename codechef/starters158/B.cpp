#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int64_t, int> freq;

    int res = 0;
    for(int i = 0; i < N; i++) {
        int64_t now = A[i];
        freq[now] += 1;
        res += 1;
        while(true) {
            if(freq[now] > 1) {
                int t = freq[now] / 2;
                freq[now] -= t * 2;
                res -= t * 2;
                if(freq[now] == 0) {
                    freq.erase(now);
                }
                freq[now * 2] += t;
                now *= 2;
                res += t;
            } else {
                break;
            }
        }

        std::cout << res << " \n"[i == N - 1];
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
