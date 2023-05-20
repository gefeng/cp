#include <vector>
#include <map>

int hashify(std::vector<int>& subtree, std::map<std::vector<int>, int>& isomorphic_subtree) {
    std::sort(subtree.begin(), subtree.end());

    if(!isomorphic_subtree[subtree]) {
        isomorphic_subtree[subtree] = isomorphic_subtree.size();
    }

    return isomorphic_subtree[subtree];
}

int hash(std::vector<std::vector<int>>& G, std::map<std::vector<int>, int>& isomorphic_subtree, int v, int p) {
    std::vector<int> children;
    for(int nei : G[v]) {
        if(nei != p) {
            children.push_back(hash(G, isomorphic_subtree, nei, v));
        }
    }

    return hashify(children, isomorphic_subtree);
}
