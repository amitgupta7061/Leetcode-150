#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void f(unordered_map<string, vector<pair<string, double>>> &graph, string src, string dst, 
        unordered_set<string> &visited, double product, double &ans){
        if(visited.count(src)) return;
        visited.insert(src);
        if(src == dst){
            ans = product; return;
        }
        for(auto it : graph[src]){
            if(!visited.count(it.first)){
                f(graph, it.first, dst, visited, product * it.second, ans);
            }
        }
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        vector<double> result;
        for(int i = 0; i < equations.size(); i++){
            string u = equations[i][0], v = equations[i][1]; double w = values[i];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 1.0 / w});
        }
        for(auto it : queries){
            string src = it[0], dst = it[1];
            if(!graph.count(src) || !graph.count(dst)) {
                result.push_back(-1.0000); continue;
            }
            double ans = -1.0, product = 1.0;
            unordered_set<string> visited;
            f(graph, src, dst, visited, product, ans);
            result.push_back(ans);
        }
        return result;
    }
};

int main() {
    Solution sol;
    return 0;
}