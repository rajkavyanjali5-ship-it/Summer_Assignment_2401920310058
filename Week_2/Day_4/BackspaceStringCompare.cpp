class Solution {
public:
    string build(string s) {
        string result;

        for(char c : s) {
            if(c != '#') {
                result.push_back(c);
            } else if(!result.empty()) {
                result.pop_back();
            }
        }

        return result;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};
