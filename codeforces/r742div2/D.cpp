#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int S, N;
    std::cin >> S >> N;
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; 
    std::vector<int> ans;
    int base = 1;
    while(S) {
        int d = S % 10; 
        
        for(int i = 0; i < d; i++) {
            pq.push(base);
        }

        base *= 10;
        S /= 10;
    }

    while(ans.size() < N && pq.top() == 1) {
        pq.pop(); 
        ans.push_back(1);
    } 

    while(pq.size() + ans.size() < N) {
        int x = pq.top(); 
        pq.pop();
        
        int base = 10;
        while(x / base != 1) {
            base *= 10;
        }
        base /= 10;

        if(base == 1) {
            while(x && ans.size() < N) {
                ans.push_back(1);
                x -= 1;
            }
            if(x) {
                pq.push(x);
            }
        } else {
            while(x) {
                pq.push(base);
                x -= base;
            }
        }
    }

    while(ans.size() < N) {
        ans.push_back(pq.top());
        pq.pop();
    }

    while(!pq.empty()) {
        ans[N - 1] += pq.top();
        pq.pop();
    }
    
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
