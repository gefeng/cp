#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int W;
    cin >> W;

    vector<int> ans;
    ans.reserve(300);
    
    for(int i = 1; i < 1000000; i *= 100) {
        for(int j = 1; j < 100; j++) {
            ans.push_back(i * j);
        }
    }

    int n = ans.size();
    cout << n  << '\n';
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
