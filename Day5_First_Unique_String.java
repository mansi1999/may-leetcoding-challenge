/* First Unique Character in a String

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters. */

class Solution {
    public int firstUniqChar(String s) {
        int res = Integer.MAX_VALUE;
        
        for(char c = 'a'; c <= 'z'; c++){
            int index = s.indexOf(c);
            
            if(index != -1 && index == s.lastIndexOf(c))
                res = Math.min(res, index);
        }
        
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}
