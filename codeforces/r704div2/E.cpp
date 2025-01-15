#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    int max_diff = 0;
    int p = -1;
    for(int i = 1; i < N; i++) {
        int diff = 0;
        for(int j = 0; j < M; j++) {
            if(A[0][j] != A[i][j]) {
                diff += 1; 
            } 
        }
        
        if(diff > max_diff) {
            max_diff = diff;
            p = i;
        }
    }

    std::vector<int> ans(M, 0);
    if(max_diff > 4) {
        std::cout << "No" << '\n';
        return;
    }

    if(max_diff < 3) {
        ans = A[0];
    } else {
        std::vector<int> where;
        for(int i = 0; i < M; i++) {
            if(A[0][i] != A[p][i]) {
                where.push_back(i);
            }
        }

        bool found = false;
        int n = max_diff;
        if(max_diff == 3) {
            for(int pos : where) {
                std::vector<int> a(A[0]);
                a[pos] = A[p][pos];
                
                max_diff = 0;
                int k = -1;
                for(int i = 1; i < N; i++) {
                    if(i == p) {
                        continue;
                    }

                    int diff = 0;
                    for(int j = 0; j < M; j++) {
                        if(a[j] != A[i][j]) {
                            diff += 1;
                        }
                    }
                    if(max_diff < diff) {
                        max_diff = diff;
                        k = i;
                    }
                }

                if(max_diff > 3) {
                    continue;
                }

                if(max_diff < 3) {
                    ans = a;
                    found = true;
                    break;
                }

                for(int x : where) {
                    if(x == pos) {
                        continue;
                    }
                    if(a[x] != A[k][x]) {
                        int old_val = a[x];
                        a[x] = A[k][x];

                        max_diff = 0;
                        for(int i = 1; i < N; i++) {
                            if(i == p || i == k) {
                                continue;
                            } 
                            int diff = 0;
                            for(int j = 0; j < M; j++) {
                                if(a[j] != A[i][j]) {
                                    diff += 1;
                                }
                            }
                            max_diff = std::max(max_diff, diff);
                        }
                        
                        if(max_diff < 3) {
                            ans = a;
                            found = true;
                            break;
                        }
                        
                        a[x] = old_val;
                    }
                }
            }
        }

        if(!found) {
            for(int i = 0; i < (1 << n); i++) {
                if(__builtin_popcount(i) == 2) {
                    std::vector<int> pos;
                    for(int j = 0; j < n; j++) {
                        if(i & (1 << j)) {
                            pos.push_back(where[j]); 
                        }
                    }

                    int old_val_1 = A[0][pos[0]];
                    int old_val_2 = A[0][pos[1]];
                    A[0][pos[0]] = A[p][pos[0]];
                    A[0][pos[1]] = A[p][pos[1]];

                    max_diff = 0;
                    for(int j = 1; j < N; j++) {
                        int diff = 0;
                        for(int k = 0; k < M; k++) {
                            if(A[0][k] != A[j][k]) {
                                diff += 1;
                            }
                        }
                        max_diff = std::max(max_diff, diff);
                    }

                    if(max_diff < 3) {
                        ans = A[0];
                        found = true;
                        break;
                    }
                    A[0][pos[0]] = old_val_1;
                    A[0][pos[1]] = old_val_2;
                }
            }

            if(!found) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < M; i++) {
        std::cout << ans[i] << " \n"[i == M - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
