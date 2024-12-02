function isPrefixOfWord(sentence: string, searchWord: string): number {
    const words = sentence.split(' ');

    for (let i = 0; i < words.length; i++) {

        if (words[i][0] === searchWord[0] && words[i].length >= searchWord.length) {
            let j = 0;
            while (j < searchWord.length && words[i][j] === searchWord[j]) j++;
            if (j === searchWord.length) return i + 1;
        }
    }

    return -1;
};