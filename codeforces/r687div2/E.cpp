#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> pos;
    std::vector<int> neg;
    for(int i = 0; i < N; i++) {
        if(A[i] >= 0) {
            pos.push_back(A[i]);
        } else {
            neg.push_back(A[i]);
        }
    }

    std::sort(pos.begin(), pos.end(), std::greater<int>());
    std::sort(neg.begin(), neg.end(), std::greater<int>());

    int64_t bonus = std::accumulate(pos.begin(), pos.end(), int64_t(0));

    int size = neg.size();
    std::vector<std::vector<int>> groups(K + 1);
    for(int x : pos) {
        groups[0].push_back(x); 
    }

    int p = 0;
    while(p < size) {
        if(bonus >= 0) {
            groups[0].push_back(neg[p]);
            bonus += neg[p]; 
            p += 1;
        } else {
            break;
        }
    }
    
    int g = 1 % (K + 1);
    while(p < size) {
        groups[g].push_back(neg[p]);
        p += 1;
        g += 1;
        g %= (K + 1);
    }

    int64_t ans = 0;
    for(auto& group : groups) {
        int m = group.size();
        for(int i = 0; i < m - 1; i++) {
            ans += int64_t(group[i]) * (m - 1 - i);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
