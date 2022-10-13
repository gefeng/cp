#include <iostream>
#include <vector>
#include <algorithm>

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
    
    LL ans = 1LL;
    LL max = 0LL;
    for(int x : A) {
        if(x > max + 1) {
            break;
        }    

        max += x;
        ans = max + 1;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
