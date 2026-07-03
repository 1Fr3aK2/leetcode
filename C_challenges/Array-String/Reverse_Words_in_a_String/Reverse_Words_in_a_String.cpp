#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word;
        vector<string>words;
        while (ss >> word) {
            words.push_back(word);
        }
        string result;
        int i = words.size() - 1;
        for (; i >= 0 ; i--)
        {
            result += words[i];
            cout << i << endl;
            if (i > 0)
                result += " ";
        }
        
        return result;;
    }
};

int main()
{
    Solution sol;
    string  str = sol.reverseWords("the sky is blue");
    std::cout << str << std::endl;
}