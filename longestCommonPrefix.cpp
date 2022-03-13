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

// 2st version O(nlogn + m)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end()); // O(nlogn)

        auto beg = strs.begin();
        auto ed = strs.end() - 1;

        int min_len = beg->size() < ed->size() ?
            beg->size() : ed->size();

        int i;
        for (i = 0; i < min_len && (*beg)[i] == (*ed)[i]; i++);

        return strs.begin()->substr(0, i);
    }

};
