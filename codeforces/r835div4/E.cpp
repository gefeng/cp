#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL count(vector<int>& v) {
    LL res = 0LL;
    int n = v.size();
    int cnt_0 = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(v[i] == 0) {
            cnt_0 += 1;
        } else {
            res += cnt_0;
        }
    }

    return res;
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = count(A);

    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            A[i] = 1;
            ans = max(ans, count(A));
            A[i] = 0;
            break;
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        if(A[i] == 1) {
            A[i] = 0;
            ans = max(ans, count(A));
            A[i] = 1;
            break;
        }
    }

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
