/**
 * @param {string} s
 * @return {number}
 */
var minimumSteps = function(s) {
    let left = 0, right = s.length - 1, answer = 0, ones = 0;
    while(right != -1 && s[right] == '1') right -= 1;
    
        while (left <= right) {
            if (s[left] == '1')
                while (left <= right && s[left] == '1') {
                    left += 1;
                    ones += 1;
                }
            else{
                answer += ones;
                left += 1;
            }
        }
        return answer;

};