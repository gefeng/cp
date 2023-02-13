#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    int tot = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] == 2) {
            tot += 1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == 2) {
            cnt += 1;
        } 
        if(cnt == tot - cnt) {
            cout << i + 1 << '\n';
            return;
        }
    } 

    cout << -1 << '\n';
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
