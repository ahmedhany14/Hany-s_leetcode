/**
 * @param {string} allowed
 * @param {string[]} words
 * @return {number}
 */
var countConsistentStrings = function(allowed, words) {

    let appear = {};

    for (let i in allowed) appear[allowed[i]] = true;

    let answer = 0;

    words.forEach((word) => {
      let isAllowed = 1;
      for (let i in word) isAllowed &= appear[word[i]];
      answer += isAllowed;
    });

    return answer;

};