/*
 * @lc app=leetcode id=1017 lang=cpp
 *
 * [1017] Convert to Base -2
 */

// @lc code=start
class Solution
{
public:
    string baseNeg2(int n)
    {
        int ns = n;
        stack<char> s;
        while (n > 0)
        {
            if(n%(-2) == 1){
                s.push('1');
            }
            else{
                s.push('0');
            }
            n = n / -2;
        }
        // if(ns < 4 && ns != 0){
        //     s.push('1');
        // }
        // if(ns == 0){
        //     s.push('0');
        // }
        string str = "";
        while(!s.empty()){
            str = str + s.top();
            s.pop();
        }
        return str;
    }
};
// @lc code=end
