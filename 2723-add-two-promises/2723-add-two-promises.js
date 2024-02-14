/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    try {
        const [value1, value2] = await Promise.all([promise1, promise2]);
        return value1 + value2;
    } catch (error) {
        throw new Error("Returned promise should resolve with a number");
    }
};