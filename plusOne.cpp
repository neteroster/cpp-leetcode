class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto e = digits.end();
        while(e-- != digits.begin())
        {
            if (*e == 9)
            {
                *e = 0; 
                if (e != digits.begin())
                    continue;
                digits.insert(digits.begin(), 1);
                break;
            }
            (*e)++; break;
        }
        return digits;
    }
};
