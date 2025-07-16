class Solution
{
  public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int,int> m;
		vector<int> r;
		for (int i=0; i<nums.size(); i++)
		{
			m.insert({nums[i],i});
		}
		int *s=&nums[0];
		int *e=&nums[nums.size()-1];
		while (1)
		{
			if (s[0]+e[0]==target)
			{
				r.push_back(m[s[0]]);
				r.push_back(m[e[0]]);
				return r;
			}
			else if (s[0]+e[0]<target)
			{
				s=&s[1];
			}
			else
			{
				e=&e[-1];
			}
		}
	}
};
