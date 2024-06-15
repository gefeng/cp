#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    if(K < N || K % 2 != N % 2) {
        std::cout << "No" << '\n';
        return;
    }

    int n = N * 2 + 1;
    int m = M * 2 + 1;
    std::vector<std::string> g(n, std::string(m, '+'));
    g[0][m - 2] = 'S';
    g[n - 1][m - 2] = 'G';

    for(int i = 1; i < n - 1; i += 2) {
        for(int j = 1; j < m - 1; j++) {
            if(j % 2 == 1) {
                g[i][j] = 'o';
            } else {
                g[i][j] = '?';
            }
        }
    }

    for(int i = 2; i < n - 1; i += 2) {
        for(int j = 1; j < m - 1; j++) {
            if(j % 2 == 1) {
                g[i][j] = '?';
            }
        }
    }

    for(int i = 2; i < n - 1; i += 2) {
        g[i][m - 2] = '.';
    } 

    K -= N;
    int r = 1;
    int c = m - 2;
    while(K) {
        if(r + 2 < n - 1) {
            g[r + 1][c] = '-';
            g[r][c - 1] = '.';
            g[r + 1][c - 2] = '.';
            g[r + 2][c - 1] = '.';
            c -= 2;
            if(c < 2) {
                r += 4;
                c = m - 2;
            }
            K -= 2;
        } else {
            r -= 2;
            c = 1;
            while(K) {
                g[r][c + 1] = '|'; 
                g[r + 1][c] = '.';
                g[r + 1][c + 2] = '.';
                g[r + 2][c + 1] = '.';
                K -= 2;
                c += 4;
            }
        }
    } 

    for(int i = 1; i < n - 1; i += 2) {
        for(int j = 1; j < m - 1; j++) {
            if(g[i][j] == '?') {
                g[i][j] = '|';
            }
        }
    }

    for(int i = 2; i < n - 1; i += 2) {
        for(int j = 1; j < m - 1; j++) {
            if(g[i][j] == '?') {
                g[i][j] = '-';
            }
        }
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << g[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
