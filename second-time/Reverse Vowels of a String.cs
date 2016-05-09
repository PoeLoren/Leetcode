public class Solution {
    public string ReverseVowels(string s) {
        char[] charArray = s.ToCharArray();
        int left = 0;
        int right = s.Length - 1;
        HashSet<char> vowels = new HashSet<char>(){'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        while(left < right){
            while(left < right && !vowels.Contains(charArray[left])){
                left++;
            }
            while(left < right && !vowels.Contains(charArray[right])){
                right--;
            }
            char temp = charArray[left];
            charArray[left] = charArray[right];
            charArray[right] = temp;
            left++;
            right--;
        }
        return new string(charArray);
    }
}