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


interface ThingWithLogs<T> {
  result: T
  logs: string[]
}

/*
 * Wrapper function
 */
function wrapWithLogs<T>(x: T): ThingWithLogs<T> {
  return {
    result: x,
    logs: []
  }
}

/*
 * Generic function to unwrap NumberWithLogs and then apply specified transformation to result
 */
function runWithLogs<T>(
  input: ThingWithLogs<T>,
  transform: (_: T) => ThingWithLogs<T>
): ThingWithLogs<T> {
  const newThingWithLogs = transform(input.result)
  return {
    result: newThingWithLogs.result,
    logs: input.logs.concat(newThingWithLogs.logs)
  }
}

function square(x: number): ThingWithLogs<number> {
  return {
    result: x * x,
    logs: [`Squared ${x} to get ${x * x}`]
  }
}

function addOne(x: number): ThingWithLogs<number> {
  return {
    result: x + 1,
    logs: [`Added 1 to ${x} to get ${x + 1}`]
  }
}

const a = wrapWithLogs(5)
const b = runWithLogs(a, addOne)
const c = runWithLogs(b, square)

console.log(a)
console.log(b)
console.log(c)
