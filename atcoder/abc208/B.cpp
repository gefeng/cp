#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int MAX = (int)1e7;

void run_case() {
    int P;
    cin >> P;

    int x = 1;
    int f = 1;
    vector<int> fact;
    while(f <= MAX) {
        fact.push_back(f);
        x += 1;
        f *= x;
    }

    int ans = 0;
    for(int i = fact.size() - 1; i >= 0; i--) {
        int cnt = P / fact[i];
        ans += cnt;
        P -= fact[i] * cnt;
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
