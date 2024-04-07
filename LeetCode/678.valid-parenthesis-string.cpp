/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 */

// @lc code=start
class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else if (s[i] == '(' || s[i] == '*')
            {
                st.push(s[i]);
            }
            else if (!st.empty())
            {

                if (st.top() == '(' && s[i] == ')')
                {
                    st.pop();
                }
                else if (st.top() == '*' && s[i] == ')')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        while (!st.empty())
        {
            st.pop();
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                if (s[i] != '*')
                {
                    st.push(s[i]);
                }
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (!st.empty())
            {

                if (st.top() == '(' && s[i] == ')')
                {
                    st.pop();
                }
                else
                {
                    if (s[i] != '*')
                    {
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
};
// @lc code=end
