#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX_T = 32;
constexpr int MAX_ROB = 12;
constexpr int MAX_RES = 60;
constexpr int N = MAX_ROB * MAX_ROB * MAX_ROB;
constexpr int M = MAX_RES * MAX_RES * MAX_RES;

int hashify(std::vector<int>& a, int b) {
    int h = 0;
    int s = 1;
    for(int x : a) {
        h += x * s; 
        s *= b;
    }
    return h;
}

int dfs(std::vector<std::vector<int>>& a, std::vector<int>& rob, std::vector<int>& res, int t, 
        std::vector<std::vector<std::vector<int>>>& dp) {
    if(t == MAX_T) {
        return 0;
    }

    int h1 = hashify(rob, MAX_ROB);
    int h2 = hashify(res, MAX_RES);

    if(dp[t][h1][h2] != -1) {
        return dp[t][h1][h2];
    }

    std::vector<int> nrob(3, 0);
    std::vector<int> nres(3, 0);
    for(int i = 0; i < 3; i++) {
        nrob[i] = rob[i];
        nres[i] = std::min(MAX_RES - 1, res[i] + rob[i]);
    }

    int max_g = dfs(a, nrob, nres, t + 1, dp);

    for(int i = 0; i < 2; i++) {
        if(res[0] >= a[i][0] && nrob[i] + 1 < MAX_ROB) {
            nrob[i] += 1;
            nres[0] -= a[i][0];
            
            max_g = std::max(max_g, dfs(a, nrob, nres, t + 1, dp));

            nrob[i] -= 1;
            nres[0] += a[i][0];
        }
    }

    if(res[0] >= a[2][0] && res[1] >= a[2][1] && nrob[2] + 1 < MAX_ROB) {
        nrob[2] += 1;
        nres[0] -= a[2][0];
        nres[1] -= a[2][1];
        max_g = std::max(max_g, dfs(a, nrob, nres, t + 1, dp)); 
        nrob[2] -= 1;
        nres[0] += a[2][0];
        nres[1] += a[2][1];
    }

    if(res[0] >= a[3][0] && res[2] >= a[3][2]) {
        int geode = MAX_T - t - 1; 
        nres[0] -= a[3][0];
        nres[2] -= a[3][2];
        max_g = std::max(max_g, dfs(a, nrob, nres, t + 1, dp) + geode); 
        nres[0] += a[3][0];
        nres[2] += a[3][2];
    }

    return dp[t][h1][h2] = max_g;
}

int solve(std::vector<std::vector<int>>& a, std::vector<int> rob, std::vector<int> res) {
    for(int i = 0; i < MAX_T; i++) {
        std::vector<int> nrob(rob);
        std::vector<int> nres(res);
        

        for(int j = 0; j < 4; j++) {
            nres[j] += rob[j];
        }
        
        if(res[2] >= a[3][2] && res[0] >= a[3][0]) {
            nrob[3] += 1; 
            int c1 = a[3][2];
            int c2 = a[3][0];
            nres[2] -= c1;
            nres[0] -= c2;
            //res[2] -= c1;
            //res[0] -= c2;
        } else if(res[2] >= a[3][2]) {
        } else if(res[1] >= a[2][1] && res[0] >= a[2][0]) {
            nrob[2] += 1; 
            int c1 = a[2][1];
            int c2 = a[2][0];
            nres[1] -= c1;
            nres[0] -= c2;
            //res[1] -= c1;
            //res[0] -= c2;
        } else if(res[1] >= a[2][1]) {
        } else if(res[0] >= a[1][0]) {
            nrob[1] += 1;
            nres[0] -= a[1][0];
        }

        std::swap(rob, nrob);
        std::swap(res, nres);

        std::cout << i + 1 << ' ';
        for(int j = 0; j < 4; j++) {
            std::cout << res[j] << " \n"[j == 3];
        }
    }

    return res.back();
}

void run_case() {
    std::vector<std::vector<int>> A;

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';
    };

    std::string S;
    while(getline(std::cin, S)) {
        std::vector<int> v;
        int sz = S.size();

        for(int i = 0; i < sz; ) {
            if(is_digit(S[i])) {
                int x = 0;
                while(i < sz && is_digit(S[i])) {
                    x = x * 10 + S[i] - '0';
                    i += 1;
                }
                v.push_back(x);
            } else {
                i += 1;
            }
        }

        A.emplace_back(v.begin() + 1, v.end());
    }

    int sum = 0;
    //int n = A.size();
    int n = 3;
    for(int i = 0; i < n; i++) {
        std::vector<std::vector<int>> a(4, std::vector<int>(3, 0));    
        
        for(int j = 0; j < 2; j++) {
            a[j][0] = A[i][j]; 
        }

        a[2][0] = A[i][2];
        a[2][1] = A[i][3];

        a[3][0] = A[i][4];
        a[3][2] = A[i][5];
        
        std::vector<int> robots(3, 0);
        std::vector<int> resource(3, 0);
        robots[0] += 1;

        //std::cout << N << ' ' << M << '\n';
        std::vector<std::vector<std::vector<int>>> dp(MAX_T, std::vector<std::vector<int>>(N, std::vector<int>(M, -1)));

        int res = dfs(a, robots, resource, 0, dp);
        std::cout << res << '\n';
        //sum += (i + 1) * res;

        
        /*int x = solve(a, robots, resource);
        std::cout << x << '\n';
        sum += (i + 1) * x;*/
        
    }

    std::cout << sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
