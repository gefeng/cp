#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N;
    LL M, K;
    std::cin >> N >> M >> K;

    std::string S;
    std::cin >> S;

    //ooxxooox ooxxooox
    
    std::vector<LL> save(N + 1, 0LL); // longest contiguous 'o' by removing first i 'x'
    std::vector<int> pos_x;

    LL cnt_x = 0LL;
    LL tot_x = 0LL;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'x') {
            cnt_x += 1; 
            pos_x.push_back(i);
        }
        save[cnt_x] = i + 1;
    }

    tot_x = cnt_x * M;

    if(cnt_x == N) {
        std::cout << K << '\n';
        return;
    }

    LL cnt = 0LL;
    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        LL left = tot_x - cnt; 

        if(left < K) {
            break;
        } 

        if(K < cnt_x - cnt) {
            // remove k 'x' from this position 
            auto it = lower_bound(pos_x.begin(), pos_x.end(), i);
            it += K;
            
            int j = (it == pos_x.end() ? N : *it);

            ans = std::max(ans, 1LL * (j - i));
        } else {
            LL x = (K - cnt_x + cnt) / cnt_x;
            LL r = (K - cnt_x + cnt) % cnt_x;

            LL len = 1LL * (N - i) + x * N + (x == M - 1 ? 0 : save[r]);
            ans = std::max(ans, len);
        }

        if(S[i] == 'x') {
            cnt += 1LL;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
