#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        st.push(tokens[0]);
        int ans=0;
        int i=1;
        int x=0, y=0;
        while(i<tokens.size()){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                y = stoi(st.top());
                st.pop();

                x = stoi(st.top());
                st.pop();

                if(tokens[i] == "+"){
                    ans = x + y;
                    // cout<<x<<" "<<y<<" "<<ans<<endl;
                    st.push(to_string(ans));
                }
                else if(tokens[i] == "-"){
                    ans = x - y;
                    st.push(to_string(ans));
                }
                else if(tokens[i] == "*"){
                    ans = x * y;
                    st.push(to_string(ans));
                }
                else{
                    ans = x / y;
                    // cout<<x<<" "<<y<<" "<<ans<<endl;
                    st.push(to_string(ans));
                }
                i++;
            }
            else{
                st.push(tokens[i]);
                i++;
            }
        }
        ans = stoi(st.top());
        return ans;
    }
};