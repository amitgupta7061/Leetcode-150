#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double f(unordered_map<string, vector<pair< string, int>>> &graph, string &src, string &dst){
        double result = 0;
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair< string, int>>> graph;
        vector<double> result;
        for(int i = 0; i < equations.size(); i++){
            string u = equations[i][0], v = equations[i][1]; double w = values[i];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 1.0 / w});
        }
        for(auto it : queries){
            result.push_back(f(graph, it[0], it[1]));
        }
        return result;
    }
};

int main() {
    Solution sol;
    return 0;
}