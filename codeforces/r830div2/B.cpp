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

    int d = 0;
    for(int i = 1; i < N; i++) {
        int x = (S[i - 1] - '0' + d) % 2;
        int y = (S[i] - '0' + d) % 2;

        if(x == 1 && y == 0) {
            d++;
        }
    }

    cout << d << '\n';
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
