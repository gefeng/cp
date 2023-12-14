#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    std::vector<std::vector<int>> B(H, std::vector<int>(W));
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> B[i][j];
        }
    }

    std::queue<std::vector<std::vector<int>>> q;
    std::set<std::vector<std::vector<int>>> s;
    q.push(A); 
    s.insert(A); 

    int d = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            std::vector<std::vector<int>> cur = q.front();
            q.pop();

            if(cur == B) {
                std::cout << d << '\n';
                return;
            }            

            for(int i = 0; i < H - 1; i++) {
                std::vector<std::vector<int>> nxt(cur);
                std::swap(nxt[i], nxt[i + 1]);
                if(s.find(nxt) == s.end()) {
                    s.insert(nxt);
                    q.push(nxt);
                }
            }

            for(int i = 0; i < W - 1; i++) {
                std::vector<std::vector<int>> nxt(cur);
                for(int j = 0; j < H; j++) {
                    std::swap(nxt[j][i], nxt[j][i + 1]);
                }
                if(s.find(nxt) == s.end()) {
                    s.insert(nxt);
                    q.push(nxt);
                }
            }
        }

        d += 1;
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
