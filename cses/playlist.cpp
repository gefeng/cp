#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    set<int> seen; 
    for(int l = 0, r = 0; r < N; r++) {
        while(seen.find(A[r]) != seen.end()) {
            seen.erase(A[l++]);
        }

        seen.insert(A[r]);
        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
