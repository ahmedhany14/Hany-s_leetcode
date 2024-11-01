class Solution(object):
    def makeFancyString(self, s):
        result = ''
        for char in s:
            if not result[-2:] == char * 2:
                result += char
        return result
