#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = int(1e6);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> ans;
    int p2 = 1;
    while(p2 < K) {
        ans.push_back(p2);
        p2 *= 2;
    } 
   
    if(p2 == K) {
        ans.push_back(K + 1);
        p2 *= 2;
        ans.push_back(K + p2);
        while(p2 <= MAX) {
            ans.push_back(p2);
            p2 *= 2;
        }
    } else {
        ans.pop_back();
        ans.push_back(K - p2 / 2);
        ans.push_back(K + 1);
        ans.push_back(K + p2); 
        while(p2 <= MAX) {
            ans.push_back(p2);
            p2 *= 2;
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
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
