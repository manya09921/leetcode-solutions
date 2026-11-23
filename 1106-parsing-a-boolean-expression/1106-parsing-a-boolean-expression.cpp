class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        for(char ch: expression){
            if (ch==',') continue;
            if (ch!=')') st.push(ch);
            else{
                bool foundtrue=false;
                bool foundfalse=false;
                while(st.top()!='(')
                {
                    if(st.top()=='t') foundtrue=true;
                    else foundfalse=true;
                    st.pop();
                }
                st.pop(); //for '('
                char operat=st.top();
                st.pop();
                if(operat=='!')
                {
                    if(foundfalse) st.push('t');
                    else st.push('f');
                }
                else if(operat=='&')
                {
                    if(foundfalse) st.push('f');
                    else st.push('t');
                }
                else // operator=="|"
                {
                    if(foundtrue) st.push('t');
                    else st.push('f');
                }
            }
        }
        return st.top()=='t';
    }
};