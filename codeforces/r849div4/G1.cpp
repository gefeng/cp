#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, C;
    cin >> N >> C;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] += i + 1;
    }

    sort(A.begin(), A.end());
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(C < A[i]) {
            break;
        } else {
            C -= A[i];
            ans += 1;
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
