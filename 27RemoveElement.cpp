class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int w=0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=val) {
                nums[w]=nums[i];
                w++;
            }
        }
        return w;        
    }
    int removeElement2(vector<int>& nums, int val) {
        if (nums.size()==0) return 0;
        int *a=&nums.back();
        for (int i=0; i<nums.size(); i++) {
            if (&nums[i]==a) {
                return (a[0]==val) ? i : i+1;
            }
            if (nums[i]==val) {
                while (a[0]==val) {
                    a--;
                    if (&nums[i]==a) return (a[0]==val) ? i : i+1;
                }
                nums[i]=a[0];
                a--;
                if (&nums[i]==a) return i+1;
            }
        }
        return 0;
    }
};