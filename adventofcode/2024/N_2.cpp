#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int H = 103;
constexpr int W = 101;
constexpr int T = 10000;

int next_int(std::string& s, int& p) {
    int n = s.size();
    int x = 0;
    int sign = 1;
    while(p < n && !isdigit(s[p])) {
        p += 1;
    }

    if(p && s[p - 1] == '-') {
        sign = -1; 
    }

    while(p < n && isdigit(s[p])) {
        x = x * 10 + s[p++] - '0';
    }

    return x * sign;
}

int get_quadrant(int x, int y) {
    int h = H / 2;
    int w = W / 2;
    if(x < w && y < h) {
        return 0;
    }
    if(x > w && y < h) {
        return 1;
    }
    if(x < w && y > h) {
        return 2;
    }
    return 3;
}

void run_case() {
    std::vector<std::array<int, 4>> A;
    std::vector<std::string> G(H, std::string(W, '.'));

    for(std::string S; std::getline(std::cin, S); ) {
        int p = 0;
        int px = next_int(S, p);
        int py = next_int(S, p);
        int vx = next_int(S, p);
        int vy = next_int(S, p);
        A.push_back({px, py, vx, vy});
        G[px][py] = '*';
    }

    int n = A.size();
    for(int t = 0; t < T; t++) {
        std::vector<std::string> g(H, std::string(W, '.'));
        for(int i = 0; i < n; i++) {
            int& x = A[i][0];
            int& y = A[i][1];
            int vx = A[i][2];
            int vy = A[i][3];

            x += vx;
            y += vy;
            x = (x + W) % W;
            y = (y + H) % H;

            g[x][y] = '*';
        }

        bool print = false;
        for(int i = 0; i < H; i++) {
            int cnt = 0;
            for(int j = 0; j < W; j++) { 
                if(g[i][j] == '*') {
                    cnt += 1;
                }
            }
            if(cnt >= W - 70) {
                print = true;
            }
        }
        
        if(print) {
            std::cout << t + 1 << '\n';
            for(int i = 0; i < H; i++) {
                std::cout << g[i] << '\n';
            }
            std::cout << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
