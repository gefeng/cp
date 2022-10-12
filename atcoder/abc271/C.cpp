#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int lo = 0;
    int hi = 300000;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        unordered_set<int> have;
        for(int i = 0; i < N; i++) {
            if(A[i] <= mid) {
                have.insert(A[i]);
            }
        }

        int change = (N - have.size()) / 2;
        
        if(have.size() + change >= mid) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
