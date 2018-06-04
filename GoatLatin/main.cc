/* A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

	We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

	The rules of Goat Latin are as follows:

	If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
	For example, the word 'apple' becomes 'applema'.
	 
	If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
	For example, the word "goat" becomes "oatgma".
	 
	Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
	For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
	Return the final sentence representing the conversion from S to Goat Latin. 

	 

	Example 1:

	Input: "I speak Goat Latin"
	Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
	Example 2:

	Input: "The quick brown fox jumped over the lazy dog"
	Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
	 

	Notes:

	S contains only uppercase, lowercase and spaces. Exactly one space between each word.
	1 <= S.length <= 150.
	
	https://leetcode.com/problems/goat-latin/description/
	
	*/
	
class Solution {
public:
    
    vector<string> tokenize(const string& s) {
        vector<string> str;
        
        string temp;
        
        for (auto& i: s) {
            if (i == ' ') {
                if (temp.size() > 0) {
                    str.push_back(temp);
                }
                temp = "";
            }
            else {
                temp += i;
            }
        }
        
        if (temp.size() > 0) {
            str.push_back(temp);
        }
        
        return str;
    }
    
    string toGoatLatin(string S) {
        vector<string> tokens = tokenize(S);
        string res;
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 1;
        
        for (auto& s: tokens) {
            assert(s.size() > 0);
            
            if ( count > 1) {
                res += " ";
            }
            
            if (vowels.count(s[0])) {
                res += s + "ma";
            }
            else {
                res += s.substr(1, s.size() - 1) + s[0] + "ma"; 
            }
            
            for (int i = 0; i < count; i++) {
                res += "a";
            }
            count++;
        }
        
        return res;
    }
};