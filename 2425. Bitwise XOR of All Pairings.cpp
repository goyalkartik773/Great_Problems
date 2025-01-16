#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ans = 0;
        unordered_map<long long, long long> mp;
        for (int i = 0; i < n; i++) {
            // nums1 ke element nums2 ki length times pair hoge
            mp[nums1[i]] += m;
        }
        for (int i = 0; i < m; i++) {
            // nums1 ke element nums2 ki length times pair hoge
            mp[nums2[i]] += n;
        }
        // jis bhi element ki frequency even hai wo cancel out ho jayega
        for (auto ele : mp) {
            int freq = ele.second;
            if (freq % 2 != 0) {
                ans = (ans ^ ele.first);
            }
        }
        return ans;
    }
};
int main(){

}