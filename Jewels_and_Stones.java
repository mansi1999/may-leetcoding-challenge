/* Jewels and Stones
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:

Input: J = "z", S = "ZZ"
Output: 0

Note:

    S and J will consist of letters and have length at most 50.
    The characters in J are distinct.

*/

class Solution {
    public int numJewelsInStones(String J, String S) {
        char []j_arr=J.toCharArray();
        char []s_arr=S.toCharArray();
		int total = 0;
        for(int i=0;i<j_arr.length;i++){
			char temp=j_arr[i];
			int count=0;
			for(int j=0;j<s_arr.length;j++){
				if(temp==s_arr[j]){
					count++;
				}
				
			}
			total=total+count;
		}
		return total;
    }
}