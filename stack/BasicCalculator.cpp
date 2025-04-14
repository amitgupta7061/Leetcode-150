#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int calculate(string s) {
            int sign = 1, number = 0, result = 0, n = s.length();
            stack<int> st;
            for(int i = 0; i < n; i++){
                if(isdigit(s[i])){
                    number = number * 10 + (s[i] - '0');
                } else if(s[i] == '+' or s[i] == '-'){
                    result += (number * sign); number = 0;
                    if(s[i] == '+') sign = 1;
                    else sign = -1;
                } else if(s[i] == '('){
                    st.push(result), st.push(sign);
                    result = 0, sign = 1, number = 0;
                } else if(s[i] == ')'){
                    result += number * sign;
                    number = 0;
                    int lstSign = st.top(); st.pop();
                    int lstResult = st.top(); st.pop();
    
                    result = (result * lstSign) + lstResult;
                }
            }
            result += number * sign;
            return result; 
        }
    };

int main() {

    return 0;
}