/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const result = [];
    
    for(const i in arr) { // we use 'in' for index: String and 'of' for values
        result.push(fn(arr[i], Number(i)));
    }
    
    return result;
};