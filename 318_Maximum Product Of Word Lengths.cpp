class Solution {
public:
    int maxProduct(vector<string>& words) {
	    vector<int> hsh;
	    for(string& s: words){
		    hsh.push_back(0);
		    for(char c: s)
			    hsh.back() |= 1 << (c-'a');
	    }
	    size_t maxProduct = 0;
	    for (int i=0;i<words.size();++i)
		    for (int j=i+1;j<words.size();++j)
			    if ( (hsh[i] & hsh[j]) == 0)
				    maxProduct = max(maxProduct, words[i].length() * words[j].length());
	    return maxProduct;
    }
};