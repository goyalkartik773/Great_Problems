#include <iostream>
using namespace std;
// brute force approach
class Solution
{
public:
    int count_set_bits(int num)
    {
        int count = 0;
        while (num != 0)
        {
            count++;
            num = num &
                  (num - 1); // har iss operation ke sath 1 bit kaam hoti jayegi
        }
        return count;
    }
    void add_bit(int &num, int bit)
    {
        int bitmask = 1 << bit;
        num = num | bitmask;
    }
    void remove_bit(int &num, int bit)
    {
        int bitmask = ~(1 << bit);
        num = num & bitmask;
    }
    bool is_set(int num, int bit)
    {
        // check karna hai bit position per one hai yaha nahi
        int bitmask = 1 << bit;
        return num & bitmask;
    }
    int minimizeXor(int num1, int num2)
    {
        // x agar num1 hi ho jata hai to wahi minimum hoga kyuki same no per xor
        // karega to zero hi hoga
        int num_bit1 = count_set_bits(num1);
        int num_bit2 = count_set_bits(num2);
        // xor property same bit -- 0  diff bit -- 1
        int bit = 0; // position ko reprsent kar raha bit number mai
        if (num_bit1 > num_bit2)
        {
            // lsb to msb mai jaha per bhi pahela one dikhage usse unset karuga
            // taki min weight add ho
            int diff = num_bit1 - num_bit2;
            while (diff != 0)
            {
                if (is_set(num1, bit))
                {
                    // bit wo min position hai jaha per 1 mila hai remove kar do
                    // iss one ko
                    remove_bit(num1, bit); // num1 pass by reference hai
                    diff--;
                }
                bit++;
            }
        }
        else if (num_bit1 < num_bit2)
        {
            // bits ko set karna hai num1 ki
            int diff = num_bit2 - num_bit1;
            while (diff != 0)
            {
                if (!is_set(num1, bit))
                {
                    // jis least position per 0 hoga uski position bit mai
                    // return kardega
                    add_bit(num1, bit);
                    diff--;
                }
                bit++; // num1 pass by reference hai
            }
        }
        return num1;
    }
};
int main()
{
}