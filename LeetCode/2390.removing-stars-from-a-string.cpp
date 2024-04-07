/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] != '*'){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        s = "";
        while(!st.empty()){
            s+= st.top();
            st.pop();
        }

        //reverse
        string str = s;
        int j = 0;
        for (int i = str.length() - 1 ; i >= 0 ; i--)
        {
            str[i] = s[j];
            j++;
        }
        
        return str;
    }
};
// @lc code=end


