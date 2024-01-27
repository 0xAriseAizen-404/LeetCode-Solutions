/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    const fn = (acc, f) => f(acc)
    return function(x) {
        return functions.reduceRight(fn, x)
    //     let value = x;
    //     for(let i=functions.length-1;i>=0;--i) {
    //         value = functions[i](value);
    //     }
    //     return value;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */