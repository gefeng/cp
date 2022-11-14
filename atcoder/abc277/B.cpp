#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    set<string> seen;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;

        seen.insert(S);
    }

    if(seen.size() != N) {
        cout << "No" << '\n';
        return;
    }

    string t_1 = "HDCS";
    string t_2 = "A23456789TJQK";
    for(string s : seen) {
        if(t_1.find(s[0]) == string::npos || t_2.find(s[1]) == string::npos) {
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
