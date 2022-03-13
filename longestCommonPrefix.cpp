// 1st version
// O(n * m)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int i = 0;
        char tmp = strs[0][0];

        while(true)
        {
            
            for (auto &e : strs)
            {
                if (e.begin() + i == e.end())
                {
                    return result;
                }
                if (e[i] != tmp) return result;
            }
            result += strs[0][i];
            i++;
            tmp = strs[0][i];

        }
    }
};
