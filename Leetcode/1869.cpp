// * @param 1859. Sorting the Sentence // 

// * @param A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

// * @param A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

// * @param For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".

// * @param Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

#include <cctype>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string sortSentence(std::string s) {
    //    std::sort(s.begin() , s.end());
        int length = s.length();
        std::string tmp = "";
        std::unordered_map<int , std::string> map; 
        for (int i = 0; i < length; ++i) {
            if (std::isdigit(s[i])) {
                int pos = s[i] - '0';
                map[pos] = tmp;
                tmp = "";
            } else if (std::isalpha(s[i])) {
                tmp = tmp + s[i]; 
            }
        }
        std::string result = "";
        for (int i = 1; i <= map.size(); ++i) {
            result = result + map[i] + " ";
        }
        result.pop_back();
        return result; 
    }
};