#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

constexpr int INF = 30;

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> G(H, std::vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> G[i][j];
        }
    }

    auto rotate = [&](std::vector<std::vector<int>>& g, int x, int y) {
        std::vector<std::vector<int>> tmp(H - 1, std::vector<int>(W - 1, 0));
        for(int i = 0; i < H - 1; i++) {
            for(int j = 0; j < W - 1; j++) {
                //std::cout << i << ' ' << j << ' ' << H - 1 - i + x << ' ' << W - 1 - j + y << '\n';
                tmp[i][j] = g[H - i + x - 2][W - j + y - 2];
            }
        }
        for(int i = 0; i < H - 1; i++) {
            for(int j = 0; j < W - 1; j++) {
                g[i + x][j + y] = tmp[i][j];
            }
        }
    };

    int d = 0;
    std::queue<std::vector<std::vector<int>>> q;
    std::map<std::vector<std::vector<int>>, int> m;
    q.push(G);
    m[G] = 0;
    
    while(!q.empty() && d < 10) {
        int size = q.size();
        while(size--) {
            std::vector<std::vector<int>> g = q.front();
            q.pop();
            
            for(int x = 0; x < 2; x++) {
                for(int y = 0; y < 2; y++) {
                    std::vector<std::vector<int>> ng(g);
                    rotate(ng, x, y);
                    if(m.find(ng) == m.end()) {
                        m[ng] = d + 1;
                        q.push(ng);
                    }
                }
            }
        }
        d += 1;
    }

    std::vector<std::vector<int>> t(H, std::vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            t[i][j] = i * W + j + 1;
        }
    }

    if(m.find(t) != m.end()) {
        std::cout << m[t] << '\n';
        return;
    }
     
    q = std::queue<std::vector<std::vector<int>>>();
    std::map<std::vector<std::vector<int>>, int> mr;
    q.push(t);
    mr[t] = 0;
    d = 0;
    while(!q.empty() && d < 10) {
        int size = q.size();
        while(size--) {
            std::vector<std::vector<int>> g = q.front();
            q.pop();
            
            for(int x = 0; x < 2; x++) {
                for(int y = 0; y < 2; y++) {
                    std::vector<std::vector<int>> ng(g);
                    rotate(ng, x, y);
                    if(mr.find(ng) == mr.end()) {
                        mr[ng] = d + 1;
                        q.push(ng);
                    }
                }
            }
        }
        d += 1;
    }

    int ans = INF;
    for(auto& [k, d] : m) {
        if(mr.find(k) != mr.end()) {
            ans = std::min(ans, d + mr[k]);
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
