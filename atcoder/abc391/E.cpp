#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::string S;
    std::cin >> S;
    
    std::string now = S;
    std::vector<int> cost(S.size(), 1);
    while(true) {
        if(now.size() == 1) {
            break;
        }

        std::vector<int> n_cost;

        int size = now.size();
        std::string nxt = "";
        for(int i = 0; i < size; i += 3) {
            int cnt = 0;
            std::array<int, 3> a = {};;
            for(int j = 0; j < 3; j++) {
                cnt += now[i + j] - '0';
                a[j] = cost[i + j];
            }
            nxt.push_back(cnt > 1 ? '1' : '0');

            int bit = cnt > 1 ? 1 : 0;
            std::sort(a.begin(), a.end());
            if(bit == 1) {
                if(cnt == 2) {
                    int min_cost = INF;
                    for(int j = 0; j < 3; j++) {
                        if(now[i + j] == '1') {
                            min_cost = std::min(min_cost, cost[i + j]);
                        } 
                    }
                    n_cost.push_back(min_cost);
                } else {
                    n_cost.push_back(a[0] + a[1]);
                }
            } else {
                if(cnt == 1) {
                    int min_cost = INF;
                    for(int j = 0; j < 3; j++) {
                        if(now[i + j] == '0') {
                            min_cost = std::min(min_cost, cost[i + j]);
                        }
                    }
                    n_cost.push_back(min_cost);
                } else {
                    n_cost.push_back(a[0] + a[1]);
                }
            }
        }

        std::swap(now, nxt);
        std::swap(cost, n_cost);
    }

    std::cout << cost[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
