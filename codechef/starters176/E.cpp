#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void dfs_1(std::vector<std::vector<int>>& G, std::vector<int>& A, int pt, int v, int p, 
        std::vector<int64_t>& dp_1, std::vector<int64_t>& dp_2) {
    for(int nei : G[v]) {
        if(nei != p) {
            dfs_1(G, A, pt, nei, v, dp_1, dp_2);
            dp_2[v] += dp_2[nei];
        }
    }

    bool divisible = true;
    for(int prime : primes) {
        if(prime < pt) {
            if(A[v] % prime != 0) {
                divisible = false;
            } 
        }
    }

    if(divisible) {
        for(int nei : G[v]) {
            if(nei != p) {
                dp_1[v] += dp_1[nei];
            }
        }

        if(A[v] % pt != 0) {
            dp_1[v] += 1;
            dp_1[v] += dp_2[v];
            dp_2[v] = 0;
        } else {
            dp_2[v] += 1;
        }
    } else {
        dp_2[v] = 0;
    }
}

void dfs_2(std::vector<std::vector<int>>& G, std::vector<int>& A, int pt, int v, int p, 
        std::vector<int64_t>& dp_1, std::vector<int64_t>& dp_2, std::vector<int64_t>& ds_1, std::vector<int64_t>& ds_2) {
    ds_1[v] = dp_1[v];
    ds_2[v] = dp_2[v];
    if(p != -1) {
        bool divisible = true;
        for(int prime : primes) {
            if(prime < pt) {
                if(A[v] % prime != 0) {
                    divisible = false;
                } 
            }
        }

        if(divisible) {
            for(int prime : primes) {
                if(prime < pt) {
                    if(A[p] % prime != 0) {
                        divisible = false;
                    } 
                }
            }

            if(divisible) {
                ds_1[v] += ds_1[p] - dp_1[v];
                if(A[p] % pt != 0) {
                    ds_1[v] -= dp_2[v]; 
                }
                if(A[v] % pt != 0) {
                    ds_1[v] += ds_2[p];
                }

                if(A[p] % pt == 0 && A[v] % pt == 0) {
                    ds_2[v] += ds_2[p] - dp_2[v];
                }
            }
        }
    }

    for(int nei : G[v]) {
        if(nei != p) {
            dfs_2(G, A, pt, nei, v, dp_1, dp_2, ds_1, ds_2);
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int64_t> ans(N, 0);
    for(int p : primes) {
        std::vector<int64_t> dp_1(N, 0);
        std::vector<int64_t> dp_2(N, 0);
        std::vector<int64_t> ds_1(N, 0);
        std::vector<int64_t> ds_2(N, 0);
        dfs_1(G, A, p, 0, -1, dp_1, dp_2);
        dfs_2(G, A, p, 0, -1, dp_1, dp_2, ds_1, ds_2);

        for(int i = 0; i < N; i++) {
            ans[i] += ds_1[i] * p; 
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
