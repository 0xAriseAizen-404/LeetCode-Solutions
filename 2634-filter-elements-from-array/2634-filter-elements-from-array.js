/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const result = [];
    
    for(const i in arr) { // we use 'in' for index: String and 'of' for values
        if(fn(arr[i], Number(i))) result.push(arr[i])
    }
    
    return result;
};