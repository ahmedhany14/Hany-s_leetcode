/**
 * @param {number[]} arr
 * @param {number[][]} queries
 * @return {number[]}
 */
var xorQueries = function(arr, queries) {
    let prefix_xor = Array(arr.length + 1).fill(0);

    for (let i = 0; i < arr.length; i++) {
      prefix_xor[i + 1] = prefix_xor[i] ^ arr[i];
    }

    let result = [];
    for (let i = 0; i < queries.length; i++) {
      result.push(prefix_xor[queries[i][0]] ^ prefix_xor[queries[i][1] + 1]);
    }
    return result;    
};