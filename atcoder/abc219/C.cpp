#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string X;
    cin >> X;

    int N;
    cin >> N;

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    array<int, 26> at;
    for(int i = 0; i < 26; i++) {
        at[X[i] - 'a'] = i;
    }

    auto cmp = [&](const string& a, const string& b) {
        int m = a.length();
        int n = b.length();
        for(int i = 0; i < m && i < n; i++) {
            if(a[i] != b[i]) {
                return at[a[i] - 'a'] < at[b[i] - 'a'];
            }
        }
        return m < n;
    };

    sort(A.begin(), A.end(), cmp);

    for(string s : A) {
        cout << s << '\n';
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
