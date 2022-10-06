#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    int tot = (int)pow(2, N);
    string cur(N, '0');

    unordered_set<string> seen;
    seen.insert(cur); 

    for(int i = 0; i < tot; i++) {
        cout << cur << '\n';
        for(int j = 0; j < N; j++) {
            cur[j] = cur[j] == '0' ? '1' : '0';
            if(seen.find(cur) == seen.end()) {
                seen.insert(cur);
                break;
            } 
            cur[j] = cur[j] == '0' ? '1' : '0';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
