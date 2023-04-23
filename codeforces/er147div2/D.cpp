#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int INF = (int)2e9;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> L(N);
    std::vector<int> R(N);
    for(int i = 0; i < N; i++) {
        std::cin >> L[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> R[i];
    }

    std::map<int, int> m;

    int ans = INF;
    int sum = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        sum += R[i] - L[i] + 1; 
        cnt += 1;
        m[R[i] - L[i] + 1] += 1;
        
        while(!m.empty() && sum >= K) {
            ans = std::min(ans, R[i] - (sum - K) + 2 * cnt);

            auto it = m.begin();
            
            if(!m.empty() && sum - it->first >= K) {
                sum -= it->first;
                
                if(--it->second == 0) {
                    m.erase(it);
                }

                cnt -= 1;
            } else {
                break;
            }
        }

    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
