import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] strs = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++)
        {
            strs[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(strs, (a, b) -> (a + b).compareTo(b + a));
        
        for(int i = strs.length-1; i >= 0; i--)
        {
            answer += strs[i];
        }
        
        if(answer.charAt(0) == '0')
        {
            answer = "0";
        }
        
        return answer;
    }
}