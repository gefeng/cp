#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N, 0);
    LL sum = 0LL; 
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    if(N == 1) {
        cout << A[0] << '\n';
        return;
    }
    
    int m = 1 << (N / 2);
    set<LL> seen;
    for(int i = 0; i < m; i++) {
        LL x = 0LL;
        for(int j = 0; j < N / 2; j++) {
            if(i & (1 << j)) {
                x += A[j];
            }
        }
        seen.insert(x * 2LL); 
    }

    LL ans = sum;
    for(int i = 0; i < m; i++) {
        LL x = 0LL;
        for(int j = 1; j < N / 2; j++) {
            if(i & (1 << j)) {
                x += A[j + N / 2];
            }
        }

        x *= 2LL;

        auto it = seen.lower_bound(abs(sum - x));
        if(it != seen.end()) {
            LL y = *it;
            ans = min(ans, abs(sum - y - x)); 
            if(it != seen.begin()) {
                it--;
                y = *it;
                ans = min(ans, abs(sum - y - x));
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
