#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(vector<int> graph[], vector<int> &visited, vector<int> &ancestor, int node){
        visited[node] = 1; ancestor[node] = 1;
        for(auto neigh : graph[node]){
            if(!visited[neigh]){
                if(f(graph, visited, ancestor, neigh)) return true;
            } else{
                if(ancestor[neigh]) return true;
            }
        }
        ancestor[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> visited(numCourses, 0), ancestor(numCourses, 0);
        for(auto it : prerequisites){
            graph[it[0]].push_back(it[1]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(visited[i] and f(graph, visited, ancestor, i)) return false;
        }
        return true;
    }
};

int main() {

    return 0;
}