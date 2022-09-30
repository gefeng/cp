#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL play(vector<LL>& v1, vector<LL>& v2) {
    LL ans = 0LL;
    int m = v1.size();
    int n = v2.size();
    int pre = 0;

    if(v1.empty()) {
        for(LL x : v2) {
            ans += x;
        }
        return ans;
    }

    ans += v1[0];
    for(int i = m - 1, j = n - 1; i > 0 || j >= 0; ) {
        if(i == 0) {
            ans += pre == 0 ? v2[j] * 2LL : v2[j];
            pre = 1;
            j--;
        } else if(j == -1) {
            ans += pre == 1 ? v1[i] * 2LL : v1[i];
            pre = 0;
            i--;
        } else {
            ans += pre == 0 ? v2[j--] * 2LL : v1[i--] * 2LL;
            pre = pre ^ 1;
        }
    }

    return ans;
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> fire;
    vector<LL> frost;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        if(A[i]) {
            frost.push_back(X);
        } else {
            fire.push_back(X);
        }
    }

    sort(fire.begin(), fire.end());
    sort(frost.begin(), frost.end());

    LL ans = max(play(fire, frost), play(frost, fire));

    cout << ans << '\n';
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
