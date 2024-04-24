   #include <iostream>
   using namespace std;
   #include <stack>
   
   bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if(st.empty() ){
                if(s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == ')' || s[i] == ']' || s[i] == '}'){
                    st.push(s[i]);
                }
            }
            else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else if (!st.empty())
            {

                if (st.top() == '(' && s[i] == ')')
                {
                    st.pop();
                }
                else if (st.top() == '[' && s[i] == ']')
                {
                    st.pop();
                }
                else if (st.top() == '{' && s[i] == '}')
                {
                    st.pop();
                }
                else{
                    if(s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == ')' || s[i] == ']' || s[i] == '}'){
                        st.push(s[i]);
                    }
                }
            }
           
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }

    int main(){
        cout << isValid("{(a+b}");
    }