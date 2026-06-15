class Solution {
public:
    bool checkValidString(string s) {
        int i = 0;
        stack<int> st1;
        stack<int> st2;
        int n = s.size();

        while(i < n){
            if(s[i] == '*'){
                st2.push(i);
            }
            else if(s[i] == '('){
                st1.push(i);
            }
            else{
                if(st2.empty() && st1.empty()){
                    return false;
                }
                else if(!st1.empty()){
                    st1.pop();
                }
                else if(!st2.empty()){
                    st2.pop();
                }
            }
            i++;
        }

        while(!st1.empty() && !st2.empty() && st1.top() < st2.top()){
            st1.pop();
            st2.pop();
        }

        if(st1.empty()){
            return true;
        }
        return false;
    }
};