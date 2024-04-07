/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if (tolower(s[i]) == tolower(st.top()) && st.top() != s[i])
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        string str = "";
        stack<char> st2;
        while (!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        while (!st2.empty())
        {
            str += st2.top();
            st2.pop();
        }
        return str;
    }
};
// @lc code=end
