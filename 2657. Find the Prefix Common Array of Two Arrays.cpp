#include <iostream>
#include <vector>
using namespace std;
// brute force approach
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &arr1, vector<int> &arr2)
    {
        // brute force approach T.C --> O(N^3)
        // int k = 0;
        // int n = arr1.size();
        // vector<int> arr3;
        // while (k < n) {
        //     int count = 0;
        //     for (int i = 0; i <= k; i++) {
        //         for (int j = 0; j <= k; j++) {
        //             if (arr1[i] == arr2[j])
        //                 count++;
        //         }
        //     }
        //     arr3.push_back(count);
        //     k++;
        // }
        // return arr3;

        // approach 2 t.c -- O(N^2)
        int n = arr1.size();
        int max_ele = INT_MIN;
        vector<int> ans;

        // Step 1: Find the maximum element in arr1 and arr2
        for (int i = 0; i < n; i++)
        {
            max_ele = max(max_ele, arr1[i]);
            max_ele = max(max_ele, arr2[i]);
        }

        // Step 2: Initialize flag arrays (size should be max_ele + 1 to include
        // max_ele itself)
        vector<bool> flag1(
            max_ele + 1, false); // Use vector<bool> to store true/false values
        vector<bool> flag2(max_ele + 1, false);

        // Step 3: Traverse the arrays and count common elements
        for (int i = 0; i < n; i++)
        {
            flag1[arr1[i]] = true;
            flag2[arr2[i]] = true;

            int count = 0;
            // Count common elements in the range [0, i]
            for (int j = 0; j <= max_ele; j++)
            {
                if (flag1[j] && flag2[j])
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
int main()
{
}