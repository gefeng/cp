#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for(int l = 0, r = N - 1; l <= r; ) {
        if(l == r) {
            ans += A[l] <= X ? 1 : 0;
            l++;
        } else {
            if(A[l] + A[r] <= X) {
                ans++;
                l++;
                r--;
            } else {
                if(A[l] > X) {
                    break;
                }
                if(A[r] > X) {
                    r--;
                } else {
                    ans++;
                    r--;
                }
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
