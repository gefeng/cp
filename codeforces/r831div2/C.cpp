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
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<int> B;
    B.reserve(N);
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i++;
        }
        B.push_back(A[j]);
    } 

    if(B.size() == 1) {
        cout << 0 << '\n';
        return;
    }
    if(B.size() == 2) {
        cout << 2LL * (B[1] - B[0]) << '\n';
        return;
    }
    
    LL ans = 0LL;
    int n = B.size();
    for(int i = 0; i < n - 1; i++) {
        ans = max(ans, 1LL * B[n - 1] - B[i] + B[i + 1] - B[i]);
    }
 
    for(int i = n - 1; i > 0; i--) {
        ans = max(ans, 1LL * B[i] - B[0] + B[i] - B[i - 1]);
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
