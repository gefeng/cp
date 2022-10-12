#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, S;
    cin >> N >> S;

    vector<int> A(N, 0);
    vector<int> B(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cin >> B[i];
    }

    vector<vector<bool>> dp_h(N + 1, vector<bool>(10001, false));
    vector<vector<bool>> dp_t(N + 1, vector<bool>(10001, false));
    dp_h[0][0] = true;
    dp_t[0][0] = true;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= 10000; j++) {
            if(j - A[i - 1] >= 0) {
                dp_h[i][j] = dp_h[i - 1][j - A[i - 1]] || dp_t[i - 1][j - A[i - 1]];
            }
            if(j - B[i - 1] >= 0) {
                dp_t[i][j] = dp_t[i - 1][j - B[i - 1]] || dp_h[i - 1][j - B[i - 1]];
            }
        }
    }

    bool ok = dp_h[N][S] || dp_t[N][S];
    cout << (ok ? "Yes" : "No") << '\n';

    if(!ok) {
        return;
    } 

    string seq = "";
    for(int i = N, j = S; i > 0; i--) {
        if(dp_h[i][j]) {
            seq.push_back('H');
            j -= A[i - 1];
        } else {
            seq.push_back('T');
            j -= B[i - 1];
        }
    }

    reverse(seq.begin(), seq.end());
    
    cout << seq << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
