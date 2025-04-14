#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            if(it == "+" or it == "-" or it == "*" or it == "/"){
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                if(it == "+") st.push(first + second);
                else if(it == "-") st.push(second - first);
                else if(it == "*") st.push(first * second);
                else st.push(second / first);
            } else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};


int main() {

    return 0;
}