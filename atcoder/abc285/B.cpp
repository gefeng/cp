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

    for(int i = 1; i < N; i++) {
        int l = 0;
        for(int k = 1; k + i <= N; k++) {
            if(S[k - 1] == S[k + i - 1]) {
                break;
            }
            l = k;
        }
        cout << l << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
