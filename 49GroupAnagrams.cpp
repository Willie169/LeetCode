class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagrams;
        for (auto& word : strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            anagrams[sorted_word].push_back(word);
        }
        for (auto& [key, group] : anagrams) {
            res.push_back(group);
        }
        return res;
    }
    
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& str : strs) {
            unsigned short count[26] = {0};
            for (char c : str) count[c - 'a']++;
            string key;
            for (unsigned i = 0; i != 26; ++i) {
                key += to_string(count[i]) + '#';
            }
            groups[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(move(group));
        }
        return result;
    }

    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        unsigned short arr[26] = {0};
        for (auto i=s.begin(); i!=s.end(); i++) {
            arr[*i-'a']++;
        }
        for (auto i=t.begin(); i!=t.end(); i++) {
            if (arr[*i-'a']<1) return false;
            arr[*i-'a']--;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams3(vector<string>& strs) {
        if (strs.empty()) return {{}};
        vector<vector<string>> a={{strs[0]}};
        for (auto i=strs.begin()+1; i!=strs.end(); i++) {
            for (auto j=a.begin(); j!=a.end(); j++) {
                if (isAnagram(*i,(*j)[0])) {
                    (*j).push_back(*i);
                    goto p;
                }
            }
            a.push_back({*i});
            p:
        }
        return a;
    }
};
