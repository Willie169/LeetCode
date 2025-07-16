class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
	string t="";
	const char *a=s.data();
	for (int i=0; i<s.size(); i+=2*(numRows-1)) t.push_back(a[i]);
	for (int j=2; j<numRows; j++) {
		for (int i=j-1; i<s.size(); i+=2*(numRows-1)) {
			t.push_back(a[i]);
			if (i+2*(numRows-j)<s.size()) t.push_back(a[i+2*(numRows-j)]);
		}
	}
	for (int i=numRows-1; i<s.size(); i+=2*(numRows-1)) t.push_back(a[i]);
	return t;
    }
};
