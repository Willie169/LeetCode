class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long r = 0;
        int y = x;
        while (y > 0) {
            r = (r * 10) + (y % 10);
            y /= 10;
        }

        return r == x;        
    }
};
