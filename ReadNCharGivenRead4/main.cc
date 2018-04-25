/*
 * The API: int read4(char *buf) reads 4 characters at a time from a file.
 * The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
 * By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
 * Input: buf = "abc", n = 4
 * Output: "abc"
 * Explanation: The actual number of characters read is 3, which is "abc".
 *
 * Input: buf = "abcde", n = 5 
 * Output: "abcde"
 * https://leetcode.com/problems/read-n-characters-given-read4/description/
 */

 
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int r = 0;
        
        while (n > 0) {
            int t = min(read4(buf), n);
            r += t;
            buf += t;
            n -= t;
         
            if (t < 4) {
                break;
            }
            
        }
        
        return r;
    }
};