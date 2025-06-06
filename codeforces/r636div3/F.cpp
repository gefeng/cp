#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        int K;
        std::cin >> K;
        A[i].resize(K, 0);
        for(int j = 0; j < K; j++) {
            std::cin >> A[i][j];
        }
    }

    for(int i = 0; i < N - 1; i++) {
        if(A[i].size() == 2) {
            for(int x : A[i]) {
                std::vector<std::set<int>> a(N - 1);
                std::vector<int> order;
                std::vector<int> ans;
                for(int j = 0; j < N - 1; j++) {
                    a[j].insert(A[j].begin(), A[j].end());
                }
                a[i].erase(x);
                ans.push_back(x);
                
                for(int j = 0; j < N - 1; j++) {
                    if(a[j].find(x) != a[j].end()) {
                        a[j].erase(x);
                    }
                }
                
                while(true) {
                    bool end = true;
                    for(int j = 0; j < N - 1; j++) {
                        if(a[j].size() == 1) {
                            int x = *a[j].begin();
                            ans.push_back(x);
                            a[j].erase(x);
                            order.push_back(j);
                            for(int k = 0; k < N - 1; k++) {
                                if(a[k].find(x) != a[k].end()) {
                                    a[k].erase(x);
                                }
                            }
                            end = false;
                            break;
                        }
                    }
                    if(end) {
                        break;
                    }
                }

                if(ans.size() == N) {
                    bool good = true;
                    for(int j = 1; j < N; j++) {
                        int k = order[j - 1];
                        int len = A[k].size();
                        std::set<int> s(A[k].begin(), A[k].end());
                        for(int p = 0; p < len; p++) {
                            if(s.find(ans[j - p]) == s.end()) {
                                good = false;
                                break;
                            } 
                        }
                    }
                    if(!good) {
                        continue;
                    }
                    for(int j = 0; j < N; j++) {
                        std::cout << ans[j] << " \n"[j == N - 1];
                    }
                    return;
                }
            }
        }
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
