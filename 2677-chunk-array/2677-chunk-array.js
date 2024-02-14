/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    const chunkedArray = []
    for(let index=0; index<arr.length; index += size)
        chunkedArray.push(arr.slice(index, index + size))
    return chunkedArray
};
