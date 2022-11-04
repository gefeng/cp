#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    string s = "";
    for(int i = 0; i < N; i++) {
        s.append("BAN");
    }

    vector<pair<int, int>> ans;
    int n = N / 2;
    int l = 0;
    int r = 3 * N - 1;
    while(n) {
        swap(s[l], s[r]); 
        ans.emplace_back(l, r);
        l += 3;
        r -= 3;
        n -= 1;
    }

    if(l < r) {
        swap(s[l], s[r]);
        ans.emplace_back(l, r);
    }

    cout << ans.size() << '\n';
    for(auto& p : ans) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
