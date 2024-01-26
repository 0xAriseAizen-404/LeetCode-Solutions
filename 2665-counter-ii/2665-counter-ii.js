/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let value = init;
    const original = init;
    return {
        increment() {
            return ++value;
        },
        reset: () => {
            value = original;
            return value;
        },
        decrement: function() {
            return --value;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */