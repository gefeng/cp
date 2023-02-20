#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;
 
    vector<vector<bool>> E(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        E[U][V] = true;
        E[V][U] = true;
    }
 
    int all_masks = (1 << N);
    vector<bool> is_clique(all_masks, false);
    for(int i = 1; i < all_masks; i++) {
        if(__builtin_popcount(i) == 1) {
            is_clique[i] = true; 
            continue;
        }
 
        vector<int> v;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                v.push_back(j);
            }
        }
 
        bool ok = true;
        for(int x : v) {
            for(int y : v) {
                if(x != y && !E[x][y]) {
                    ok = false; 
                    break;
                }
            }  
            if(!ok) {
                break;
            }
        }
 
        if(ok) {
            is_clique[i] = true;
        }
    }
 
    vector<int> dp(all_masks, N);
    for(int i = 1; i < all_masks; i++) {
        if(is_clique[i]) {
            dp[i] = 1;
            continue;
        }
 
        for(int sm = i; sm; sm = (sm - 1) & i) {
            dp[i] = min(dp[i], dp[sm] + dp[i ^ sm]);
        }
    } 
 
    cout << dp[all_masks - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
