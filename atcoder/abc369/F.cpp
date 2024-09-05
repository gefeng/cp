#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W, N;
    std::cin >> H >> W >> N;

    std::vector<std::pair<int, int>> coins(N);
    for(int i = 0; i < N; i++) {
        std::cin >> coins[i].first >> coins[i].second;
    }

    std::sort(coins.begin(), coins.end());

    std::vector<int> lis;
    std::vector<int> pre(N, -1);
    
    for(int i = 0; i < N; i++) {
        auto [r, c] = coins[i];
        
        if(lis.empty() || c >= coins[lis.back()].second) {
            if(lis.empty()) {
                pre[i] = -1;
            } else {
                pre[i] = lis.back();
            }
            lis.push_back(i);
        } else {
            int j = std::upper_bound(lis.begin(), lis.end(), c, [&](int x, int idx) {
                        return x < coins[idx].second;
                    }) - lis.begin();

            pre[i] = j ? lis[j - 1] : -1;
            lis[j] = i;
        }
    }

    int len = lis.size();
    std::string steps = "";

    int r = H;
    int c = W;
    int pre_r = -1;
    int pre_c = -1;
    int p = lis.back();
    while(r != 1 || c != 1) {
        if(p != -1) {
            pre_r = coins[p].first;
            pre_c = coins[p].second;
            p = pre[p];
        } else {
            pre_r = 1;
            pre_c = 1;
        }

        for(int i = pre_r; i < r; i++) {
            steps.push_back('D');
        }
        for(int i = pre_c; i < c; i++) {
            steps.push_back('R');
        }

        r = pre_r;
        c = pre_c;
    }

    std::reverse(steps.begin(), steps.end());

    std::cout << len << '\n' << steps << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
