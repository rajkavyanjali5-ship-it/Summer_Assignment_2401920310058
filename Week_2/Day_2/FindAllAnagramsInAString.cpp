class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> result;
        vector<int> countP(26, 0);
        vector<int> countS(26, 0);

        for(char c : p) {
            countP[c - 'a']++;
        }

        int k = p.size();

        for(int i = 0; i < s.size(); i++) {

            countS[s[i] - 'a']++;

            if(i >= k) {
                countS[s[i - k] - 'a']--;
            }

            if(countP == countS) {
                result.push_back(i - k + 1);
            }
        }

        return result;
    }
};
