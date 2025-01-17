#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xora = 0;
        int n = derived.size();
// orignal array mai har element ki xor occurance twice hogi to make each element of derived array
        for (int i = 0; i < n; i++) {
            xora = (xora ^ derived[i]);
        }
        if (xora == 0)
            return true;
        return false;
    }
};
int main()
{
}