#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const vector<string> digitString =
    {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};

class Solution
{
    vector<string> output;

public:
    vector<string> letterCombinations(string digits)
    {

        if (digits.size() == 0)
        {
            return output;
        }
        else
        {
            dfs(digits, 0, "");
        }
        return output;
    }

    void dfs(string digits, int index, string s)
    {

        if (index == digits.size())
        {
            output.push_back(s);
            return;
        }

        int num = (int)digits[index] - '0';
        string str = digitString[num];

        for (int j = 0; j < str.size(); j++)
        {
            dfs(digits, index, s + str[j]);
        }
    }
};

int main()
{

    Solution solution;
    vector<string> result = solution.letterCombinations("2");
    for (const auto &combination : result)
    {
        cout << combination << endl;
    }
}
