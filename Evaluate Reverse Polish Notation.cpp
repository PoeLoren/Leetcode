class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        for(auto i = 0;i < tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int r = s.top();
                s.pop();
                int l = s.top();
                s.pop();
                if(tokens[i] == "+"){
                    s.push(l + r);
                }
                if(tokens[i] == "-"){
                    s.push(l - r);
                }
                if(tokens[i] == "*"){
                    s.push(r * l);
                }
                if(tokens[i] == "/"){
                    s.push(l / r);
                }
            }else{
                int num = atoi(tokens[i].c_str());
                s.push(num);
            }
        }
        return s.top();
    }
};