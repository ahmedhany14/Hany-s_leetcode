/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */
var countConsistentStrings = function(allowed, words) {
    let appear = {};

    for (let i in allowed) {
      appear[allowed[i]] = true;
    }

    let answer = 0;

    words.forEach((word) => {
      let isAllowed = true;
      for (let i in word) {
        if (!appear[word[i]]) {
          isAllowed = false;
          break;
        }
      }
      if (isAllowed) {
        answer++;
      }
    });

    return answer;
};