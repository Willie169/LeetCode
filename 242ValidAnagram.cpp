class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        unsigned short arr[26] = {0};
        for (auto i=s.begin(); i<s.end(); i++) {
            arr[*i-'a']++;
        }
        for (auto i=t.begin(); i<t.end(); i++) {
            if (arr[*i-'a']<1) return false;
            arr[*i-'a']--;
        }
        return true;
    }
};
