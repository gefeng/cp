#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool is_ok(pair<int, int>& x, pair<int, int>& y, pair<int, int>& z) {
    pair<int, int> v_1 = {x.first - y.first, x.second - y.second}; 
    pair<int, int> v_2 = {z.first - y.first, z.second - y.second};
    if(v_1.first * v_2.first + v_1.second * v_2.second != 0) {
        return false;
    }

    if(v_1.first * v_1.first + v_1.second * v_1.second != v_2.first * v_2.first + v_2.second * v_2.second) {
        return false;
    }
    return true;
}

void run_case() {
    array<string, 9> G;
    for(int i = 0; i < 9; i++) {
        cin >> G[i];
    }
    
    vector<pair<int, int>> v;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(G[i][j] == '#') {
                v.emplace_back(i, j);
            }
        }
    }

    int n = v.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(k == i || k == j) continue;
                for(int l = k + 1; l < n; l++) {
                    if(l == i || l == j) continue;
                    if(is_ok(v[k], v[i], v[l]) && is_ok(v[k], v[j], v[l])) {
                        ans += 1;
                    }
                }
            } 
        }
    } 

    cout << ans / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
