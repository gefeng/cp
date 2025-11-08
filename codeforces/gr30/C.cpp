#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <ranges>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<std::pair<int, int>> B(M);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i].first;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i].second;
    }

    std::ranges::sort(A); 
    std::ranges::sort(B);

    std::priority_queue<std::pair<int, int>> pq;
    std::priority_queue<int, std::vector<int>, std::greater<int>> swords;

    for(int x : A) {
        swords.push(x);
    }

    int ans = 0;
    int i = 0;
    while(!swords.empty()) {
        int s = swords.top();
        swords.pop();

        int power = s;
        while(power) {
            while(i < M && B[i].first <= power) {
                pq.emplace(B[i].second, B[i].first);
                i += 1;
            }
            if(!pq.empty()) {
                auto [c, h] = pq.top();
                pq.pop();
                ans += 1;
                if(c > power) {
                    swords.push(c);
                    break;
                } else {
                    power = c;
                }
            } else {
                break;
            }
        }
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
