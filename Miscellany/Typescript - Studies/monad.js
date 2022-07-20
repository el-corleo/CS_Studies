/* Based of youtube video v=C2w45qRc3aU
 *
 * Monads are a useful pattern when seeking function chaining
 *
 * Monads require three distinct components:
 *  1.) A wrapper that marks the type of the monad: e.g., NumberWithLogs
 *  2.) A function to wrap items such that it may later interact with the generic unwrap & transform function: e.g., wrapWithLogs
 *      - This function essentially translates between items not of this monad with the monad ecosystem
 *  3.) A generic function that will unwrap wrapped contents and apply transform: e.g., runWithLogs
 *
 * Common Monads:
 *  - Haskell: Maybe
 *  - Java: Optional
 *  - Javascript: Promise
 */
/*
 * Wrapper function
 */
function wrapWithLogs(x) {
    return {
        result: x,
        logs: []
    };
}
/*
 * Generic function to unwrap NumberWithLogs and then apply specified transformation to result
 */
function runWithLogs(input, transform) {
    var newThingWithLogs = transform(input.result);
    return {
        result: newThingWithLogs.result,
        logs: input.logs.concat(newThingWithLogs.logs)
    };
}
function square(x) {
    return {
        result: x * x,
        logs: ["Squared ".concat(x, " to get ").concat(x * x)]
    };
}
function addOne(x) {
    return {
        result: x + 1,
        logs: ["Added 1 to ".concat(x, " to get ").concat(x + 1)]
    };
}
var a = wrapWithLogs(5);
var b = runWithLogs(a, addOne);
var c = runWithLogs(b, square);
console.log(a);
console.log(b);
console.log(c);
