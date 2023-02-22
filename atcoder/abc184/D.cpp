#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<vector<double>>> dp;
vector<vector<vector<bool>>> vis;

double dfs(int a, int b, int c) {
    if(a == 100 || b == 100 || c == 100) {
        return 0.0;
    }

    if(vis[a][b][c]) {
        return dp[a][b][c];
    }

    int sum = a + b + c;
    double p1 = (double)a / sum;
    double p2 = (double)b / sum;
    double p3 = (double)c / sum;
    
    double res = p1 * (dfs(a + 1, b, c) + 1) + p2 * (dfs(a, b + 1, c) + 1) + p3 * (dfs(a, b, c + 1) + 1);
    
    dp[a][b][c] = res;
    vis[a][b][c] = true;

    return res;
}

void run_case() {
    int A, B, C;
    cin >> A >> B >> C;

    dp = vector<vector<vector<double>>>(101, vector<vector<double>>(101, vector<double>(101, 0.0)));
    vis = vector<vector<vector<bool>>>(101, vector<vector<bool>>(101, vector<bool>(101, false)));

    cout << setprecision(20) << dfs(A, B, C) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
