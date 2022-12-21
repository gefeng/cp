#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    cin >> S;

    int K;
    cin >> K;

    sort(S.begin(), S.end());

    do {
        if(K == 1) {
            break;
        }
        K -= 1;
    } while(next_permutation(S.begin(), S.end()));

    cout << S << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
