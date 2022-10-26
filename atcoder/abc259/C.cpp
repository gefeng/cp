#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S, T;
    cin >> S >> T;

    int m = S.length();
    int n = T.length();

    if(m > n) {
        cout << "No" << '\n';
        return;
    }

    for(int i = 0, j = 0; i < m || j < n;) {
        if((i == m && j < n) || (i < m && j == n) || S[i] != T[j]) {
            cout << "No" << '\n';
            return;
        }

        int k_1 = i;
        int k_2 = j;
        while(i < m && S[i] == S[k_1]) {
            i++;
        }

        while(j < n && T[j] == T[k_2]) {
            j++;
        }

        if((i - k_1 > j - k_2) || (j - k_2 > 1 && i - k_1 == 1)) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
