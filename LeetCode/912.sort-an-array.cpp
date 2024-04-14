/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> mergeSort(vector<int> a)
    {
        if (a.size() < 2)
        {
            return a;
        }
        int half = a.size() / 2;
        int halfsecond = a.size() - half;
        cout << half;
        vector<int> arrayOne(half, 0);
        vector<int> arrayTwo(halfsecond, 0);
        int j = 0;
        for (int i = 0; i < a.size(); i++)
        {

            if (i < half)
            {
                arrayOne[i] = a[i];
            }
            else
            {
                arrayTwo[j] = a[i];
                j++;
            }
        }

        arrayOne = mergeSort(arrayOne);
        arrayTwo = mergeSort(arrayTwo);
        return merge(arrayOne, arrayTwo);
    }
    vector<int> merge(vector<int> a, vector<int> b)
    {
        vector<int> c;
        while (!a.empty() && !b.empty())
        {
            if (a[0] <= b[0])
            {
                c.push_back(a[0]);
                a.erase(a.begin());
            }
            else
            {
                c.push_back(b[0]);
                b.erase(b.begin());
            }
        }

        // Append remaining elements of a and b
        while (!a.empty())
        {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
        while (!b.empty())
        {
            c.push_back(b[0]);
            b.erase(b.begin());
        }

        return c;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        return mergeSort(nums);
    }
};
// @lc code=end
