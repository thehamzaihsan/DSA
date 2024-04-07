/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int currentdepth = 0;
        int i = 0;
        while(i < s.length()){
            if(s[i] == '('){
                currentdepth ++;
            }
            else if(s[i] == ')'){
                currentdepth --;
            }
            if(currentdepth > maxdepth){
                maxdepth = currentdepth;
            }
            i++;
        }
        return maxdepth;
    }
};
// @lc code=end

