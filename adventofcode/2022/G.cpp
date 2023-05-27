#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

using LL = long long;

constexpr LL MAX = (LL)1e5;
const std::string ROOT = "/";

LL dfs(std::map<std::string, std::set<std::pair<std::string, int>>>& dir, std::map<std::string, LL>& file, std::string cur, int type, std::map<std::string, LL>& dir_size) {
    if(type == 1) {
        return file[cur];
    } 

    LL res = 0LL;
    for(std::pair<std::string, int> sub : dir[cur]) {
        res += dfs(dir, file, sub.first, sub.second, dir_size); 
    }

    dir_size[cur] = res;

    return res;
}

void run_case() {
    std::vector<std::string> A;
    std::string S;
    while(std::getline(std::cin, S)) {
        A.push_back(S);
    }

    auto get_full = [](const std::vector<std::string>& path) {
        std::string s = "";
        for(auto& t : path) {
            std::string delimer = s.empty() ? "" : "/";
            s.append(t);
            s.append(delimer);
        }

        return s;
    };

    std::map<std::string, LL> file;
    std::map<std::string, std::set<std::pair<std::string, int>>> dir;
    std::map<std::string, LL> dir_size;
    std::string cur = ROOT;
    std::vector<std::string> path;
    path.push_back(ROOT);

    for(std::string& s : A) {
        int n = s.size();
        if(s[0] == '$') {
            if(s[2] == 'c') {
                if(s[5] == '/') {
                    cur = ROOT;
                    path = std::vector<std::string>();
                    path.push_back(ROOT);
                } else if(s[5] == '.') {
                    if(path.size() > 1) {
                        path.pop_back();
                        cur = path.back();
                    } 
                } else {
                    cur = s.substr(5, n - 5); 
                    path.push_back(cur);
                }
            }
        } else {
            if(s[0] == 'd') {
                std::string full = get_full(path);
                std::string name = full + s.substr(4, n - 4) + "/";
                dir[full].emplace(name, 0);
            } else {
                LL size = 0LL;
                int i = 0;
                for(; i < n && s[i] >= '0' && s[i] <= '9'; i++) {
                    size = size * 10LL + s[i] - '0';
                }

                std::string full = get_full(path);
                std::string name = full + s.substr(i + 1, n - i - 1);
                file[name] = size;
                dir[full].emplace(name, 1);
            }
        }
    }

    dfs(dir, file, ROOT, 0, dir_size);
    
    LL have = (LL)7e7;
    LL need = (LL)3e7;
    LL used = dir_size[ROOT];
    LL ans = have;

    for(auto [k, v] : dir_size) {
        if(have - (used - v) >= need) {
            ans = std::min(ans, v); 
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
