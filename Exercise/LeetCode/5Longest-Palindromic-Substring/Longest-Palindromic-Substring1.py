# the last test case time exceeded
class Solution:
    def ispalindromic(self, string):
        index = int(len(string)/2)
        res = True
        for i in range(index):
            if string[i] == string[-i-1]:
                continue
            else:
                res = False
                break
        return res
    def longestPalindrome(self, s: str) -> str:
        res = ""
        length = 0
        for i in range(len(s)):
            base = s[i:]
            if len(base) <= length:
                continue
            for i in reversed(range(len(base))):
                subs = base[:i+1]
                if len(subs) <= length:
                    continue
                if self.ispalindromic(subs):
                    res = subs
                    length = len(subs)
        return res