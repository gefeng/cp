#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void dfs(int i, int d, int cur, vector<int>& all) {
    if(i == 9) {
        all.push_back(cur);
        return;
    }

    if(i == 2) {
        dfs(i + 1, d * 10, (cur % 10) * d + cur, all); 
    } else if(i == 3) {
        for(int j = 0; j < 10; j++) {
            dfs(i + 2, d * 100, j * d * 10 + j * d + cur, all);
        }
    } else if(i == 7) {
        for(int j = 1; j < 10; j++) {
            dfs(i + 2, d * 100, j * d * 10 + j * d + cur, all);
        }
    } else {
        for(int j = 0; j < 10; j++) {
            dfs(i + 1, d * 10, j * d + cur, all);
        }
    }
}

void run_case() {
    int N;
    cin >> N;

    vector<int> all;
    dfs(0, 1, 0, all);

    sort(all.begin(), all.end());
    
    cout << all[N - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
