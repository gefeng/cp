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
    int A, B;
    LL K;
    cin >> A >> B >> K;
    
    int N = A + B;

    vector<vector<LL>> c(N + 1, vector<LL>(N + 1, 0LL));
    c[0][0] = 1LL;
    for(int i = 1; i <= N; i++) { 
        c[i][0] = 1LL;
        c[i][i] = 1LL;
        for(int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        } 
    } 
    
    string ans = "";
    for(int i = 0; i < N; i++) {
        if(A) {
            LL tot = c[A - 1 + B][A - 1];
            if(K <= tot) {
                ans.push_back('a');
                A -= 1;
                continue;
            } 
        }

        ans.push_back('b');
        K -= c[A - 1 + B][A - 1];
        B -= 1;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
