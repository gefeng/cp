#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>

using namespace std;

ifstream in;
ofstream out;

void gen(int tot, string& prefix, string& suffix, int len, string& cur, vector<string>& ans) {
    if(ans.size() == tot) {
        return;
    }

    if(cur.length() == len) {
        ans.push_back(prefix + cur + suffix);
        return;
    }
    
    cur.push_back('.');
    gen(tot, prefix, suffix, len, cur, ans);
    cur.pop_back();

    cur.push_back('-');
    gen(tot, prefix, suffix, len, cur, ans);
    cur.pop_back();
}

void run_case(int T) {
    int N;
    in >> N;
    
    string S;
    in >> S;

    int tot = N + 5;
    vector<string> ans;
    ans.reserve(tot);

    string prefix = "";
    string suffix = "";
    string cur = "";

    int len = S.length();

    out << "Case #" << T << ":\n";
    if(len > 6) {
        gen(tot, prefix, suffix, len, cur, ans);
    } else {
        prefix = S;
        suffix = S;
        for(int i = 0; i < len; i++) {
            suffix[i] = suffix[i] == '.' ? '-' : '.';
        }
        gen(tot, prefix, suffix, 7, cur, ans);
    }

    int cnt = N - 1;
    for(string s : ans) {
        if(s == S) {
            continue;
        }
        out << s << '\n'; 
        if(--cnt == 0) {
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    in.open("input.txt");
    out.open("output.txt");

    int T;
    in >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }

    in.close();
    out.close();
}
