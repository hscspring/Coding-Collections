class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        lenps = 0
        res = ""
        for i in range(n):
            j, k = 1, 1
            # For odd number substring
            while i-j >= 0 and i+j < n and s[i-j] == s[i+j]:
                j += 1
            # For even number substring
            while i-(k-1) >= 0 and i+k < n and s[i-k+1] == s[i+k]:
                k += 1
            psj = s[i-j+1: i+j]
            psk = s[i-(k-1)+1: i+(k-1)+1]
            ps = psj if len(psj) > len(psk) else psk
            if len(ps) > lenps:
                res = ps
                lenps = len(ps)
        return res

if __name__ == '__main__':
    solution = Solution()
    string = "babad"
    assert solution.longestPalindrome(string) == "bab"
    string = "abcdcba"
    assert solution.longestPalindrome(string) == "abcdcba"
    string = "abba"
    assert solution.longestPalindrome(string) == "abba"
    string = "aabaa"
    assert solution.longestPalindrome(string) == "aabaa"
    string = "aaaaab"
    assert solution.longestPalindrome(string) == "aaaaa"
    string = "aaaaaab"
    assert solution.longestPalindrome(string) == "aaaaaa"
    string = "baaaaaa"
    assert solution.longestPalindrome(string) == "aaaaaa"
    string = "baaaaa"
    assert solution.longestPalindrome(string) == "aaaaa"
    string = "aaaaaa"
    assert solution.longestPalindrome(string) == "aaaaaa"
    string = "aaaaa"
    assert solution.longestPalindrome(string) == "aaaaa"
    string = "cbbd"
    assert solution.longestPalindrome(string) == "bb"