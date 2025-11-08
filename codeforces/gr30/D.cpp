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

    std::string S, T;
    std::cin >> S >> T;

    if(S == T) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<std::string> ans;

    bool matched = false;
    std::string now(S);
    while(ans.size() < K) {
        std::string nxt(N, '.'); 
       
        std::vector<int> shift(N, 0);
        std::vector<std::vector<int>> pos(26);
        for(int i = 0; i < N; i++) {
            pos[now[i] - 'a'].push_back(i);
        }
        
        int left = N;
        for(int i = N - 1; i >= 0; i--) {
            if(now[i] != T[i]) {
                left = std::min(i, left);
                char c = T[i] - 'a';
                auto it = std::upper_bound(pos[c].begin(), pos[c].end(), left);
                if(it != pos[c].begin()) {
                    left = *std::prev(it);
                    shift[left + 1] = 1;
                }
            } else {
                if(left < i) {
                    char c = T[i] - 'a';
                    auto it = std::upper_bound(pos[c].begin(), pos[c].end(), left);
                    if(it != pos[c].begin()) {
                        left = *std::prev(it);
                        shift[left + 1] = 1;
                    }
                } else {
                    left = i;
                }
            }
        }

        for(int i = 0; i < N; i++) {
            if(shift[i]) {
                nxt[i] = now[i - 1]; 
            } else {
                nxt[i] = now[i];
            }
        }
        now = std::move(nxt);
        ans.push_back(now);
        if(now == T) {
            matched = true;
            break;
        }
    }

    int size = ans.size();
    if(!matched || size > K) {
        std::cout << -1 << '\n';
        return;
    }

    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << '\n';
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
