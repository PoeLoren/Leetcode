public class Solution {
    public bool WordPattern(string pattern, string str) {
        Dictionary<string, char> match = new Dictionary<string, char>();
        string[] strList = str.Split(' ');
        if(strList.Length != pattern.Length)
            return false;
        for(int i = 0; i < strList.Length; ++i){
            if(match.ContainsKey(strList[i])){
                if(pattern[i] != match[strList[i]])
                    return false;
            }else{
                if(match.ContainsValue(pattern[i]))
                    return false;
                match.Add(strList[i], pattern[i]);
            }
        }
        return true;
    }
}