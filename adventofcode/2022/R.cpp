#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

std::array<int, 6> DX = {0, 1, 0, -1, 0, 0};
std::array<int, 6> DY = {1, 0, -1, 0, 0, 0};
std::array<int, 6> DZ = {0, 0, 0, 0, 1, -1};
constexpr int MAX = 25;

void run_case() {
    std::vector<std::vector<int>> A;
    std::vector<std::vector<std::vector<bool>>> have(MAX + 1, std::vector<std::vector<bool>>(MAX + 1, std::vector<bool>(MAX + 1, false)));
    std::vector<std::vector<std::vector<bool>>> outside(MAX + 1, std::vector<std::vector<bool>>(MAX + 1, std::vector<bool>(MAX + 1, false)));
    std::string S;

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';
    };

    while(std::getline(std::cin, S)) {
        int sz = S.size();
        std::vector<int> pos;
        for(int i = 0; i < sz; ) {
            if(is_digit(S[i])) {
                int x = 0;
                while(i < sz && is_digit(S[i])) {
                    x = x * 10 + S[i] - '0';
                    i += 1;
                }
                pos.push_back(x);
            } else {
                i += 1;
            }
        }

        A.push_back(pos);
        have[pos[0]][pos[1]][pos[2]] = true;
    }
    
    std::queue<std::array<int, 3>> q;
    q.push({0, 0, 0});
    outside[0][0][0] = 1;
    
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            std::array<int, 3> cur = q.front();
            q.pop();

            int x = cur[0];
            int y = cur[1];
            int z = cur[2];

            for(int i = 0; i < 6; i++) {
                int nx = x + DX[i];
                int ny = y + DY[i];
                int nz = z + DZ[i];

                if(nx >= 0 && ny >= 0 && nz >= 0 && nx <= MAX && ny <= MAX && nz <= MAX && 
                        !outside[nx][ny][nz] && !have[nx][ny][nz]) {
                    outside[nx][ny][nz] = true;
                    q.push({nx, ny, nz});
                }
            }
        }
    }

    int ans = 0;
    for(auto& p : A) { 
        ans += 6;

        for(int i = 0; i < 6; i++) {
            int nx = p[0] + DX[i];
            int ny = p[1] + DY[i];
            int nz = p[2] + DZ[i];

            if(nx >= 0 && ny >= 0 && nz >= 0 && (have[nx][ny][nz] || !outside[nx][ny][nz])) {
                ans -= 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
