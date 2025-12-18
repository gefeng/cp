#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::array<int, 2>> trie;
    std::vector<std::array<int, 2>> data;
    int id = 0;
    int ans = 0;
    
    trie.push_back({-1, -1});
    data.push_back({0, 0});
    id++;
    
    for(int i = 0; i < N; i++) {
        int x = A[i] ^ i;
        int max_l = 1;

        int now = 0;
        for(int j = 30; j >= 0; j--) {
            int b1 = x & (1 << j) ? 1 : 0; 
            int b2 = i & (1 << j) ? 1 : 0;

            if(trie[now][b1 ^ 1] != -1) {
                max_l = std::max(max_l, data[trie[now][b1 ^ 1]][b2] + 1);
            }
            if(trie[now][b1] != -1) {
                now = trie[now][b1];
            } else {
                break;
            }
        }

        ans = std::max(ans, max_l);

        now = 0;
        for(int j = 30; j >= 0; j--) {
            int b1 = x & (1 << j) ? 1 : 0;
            int b2 = A[i] & (1 << j) ? 1 : 0;

            if(trie[now][b1] == -1) {
                trie.push_back({-1, -1});
                data.push_back({0, 0});
                trie[now][b1] = id++;
            }
            now = trie[now][b1];
            data[now][b2] = std::max(data[now][b2], max_l);
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
