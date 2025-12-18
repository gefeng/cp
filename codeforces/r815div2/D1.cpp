#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 200;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::array<int, 2>> trie;
    std::vector<int> data;
    int id = 0;
    int ans = 0;
    
    trie.push_back({-1, -1});
    data[0] = 0;
    id++;
    
    for(int i = 0; i < N; i++) {
        int x = A[i] ^ i;
        int max_l = 1;

        int now = 0;
        for(int j = 30; j >= 0; j--) {
            int b = x & (1 << j) ? 1 : 0; 

            if(b == 1 && trie[now][0] != -1) {
                max_l = std::max(max_l, data[trie[now][0]] + 1);
            }
            if(trie[now][b] != -1) {
                now = trie[now][b];
            } else {
                break;
            }
        }

        ans = std::max(ans, max_l);

        now = 0;
        for(int j = 30; j >= 0; j--) {
            int b = x & (1 << j) ? 1 : 0;

            if(trie[now][b] == -1) {
                trie.push_back({-1, -1});
                data.push_back(0);
                trie[now][b] = id++;
            }
            now = trie[now][b];
            data[now] = std::max(data[now], max_l);
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
