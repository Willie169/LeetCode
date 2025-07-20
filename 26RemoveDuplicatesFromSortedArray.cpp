class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int w=1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i]!=nums[w-1]) {
                nums[w]=nums[i];
                w++;
            }
        }
        return w;
    }
};