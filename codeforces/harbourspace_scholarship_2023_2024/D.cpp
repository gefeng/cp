#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    std::vector<std::vector<int>> diff1(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> diff2(N, std::vector<int>(N, 0));
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int sum = 0;
        for(int j = 0; j < N; j++) {
            if(i - 1 >= 0) {
                if(j + 1 < N) {
                    diff1[i][j] += diff1[i - 1][j + 1]; 
                }
                if(j == 0) {
                    diff1[i][j] += diff1[i - 1][j];
                }
            }

            if(i - 1 >= 0) {
                if(j - 1 >= 0) {
                    diff2[i][j] += diff2[i - 1][j - 1];
                } 
            }
        
            sum += diff1[i][j] + diff2[i][j];
            int cnt = G[i][j] - '0' + sum;
            if(cnt & 1) {
                ans += 1;
                sum += 1;
                diff1[i][j] += 1;
                if(j + 1 < N) {
                    diff2[i][j + 1] -= 1;
                }
            } 
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
