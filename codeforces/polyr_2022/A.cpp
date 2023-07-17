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

    string S;
    cin >> S;
    
    int cnt = S[0] == '1' ? 1 : 0;
    for(int i = 1; i < N; i++) {
        if(S[i] == '1') {
            if(cnt == 1) {
                cnt -= 1;
                cout << "-";
            } else {
                cnt += 1;
                cout << "+";
            }
        } else {
            cout << "+";
        }
    }
    cout << '\n';
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
