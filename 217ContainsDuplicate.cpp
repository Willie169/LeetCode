class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
	unordered_set<int> s;
        for (auto i=nums.begin(); i<nums.end(); i++) {
            if (s.count(*i)) return true;
            s.insert(*i);
	}
	return false;
    }
};
