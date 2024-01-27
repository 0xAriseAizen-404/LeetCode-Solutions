/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    let value = 0;
    return function(x) {
        value = x;
        for(let i=functions.length-1;i>=0;--i) {
            value = functions[i](value);
        }
        return value;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */