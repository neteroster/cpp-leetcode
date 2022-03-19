// time: 0ms

class Solution {
public:
    bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    string s2 = s + s;
    for (auto p = s2.begin(); p + goal.size() != s2.end(); p++)
    {
        bool match_flag = true;
        for (auto x = goal.begin(); x != goal.end(); x++)
        {
            if (p[x - goal.begin()] != *x)
            {
                match_flag = false;
                break;
            }
        }
        if (match_flag) return true;
        

    }
    return false;
    }
};
