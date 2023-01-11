#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<int, int> m;
    int ans = 0;
    for(int l = 0, r = 0; r < N; r++) {
        m[A[r]] += 1; 

        if(r - l + 1 > K) {
            if(--m[A[l]] == 0) {
                m.erase(A[l]);
            } 
            l += 1;
        }

        if(r - l + 1 == K) {
            ans = max(ans, (int)m.size());
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
