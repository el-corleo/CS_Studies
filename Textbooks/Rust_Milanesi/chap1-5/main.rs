fn main() {
    print!("{}, {}\n", "Hello", "World!");
    println!("This is a thing, too.");
    println!("The sum of {} and {} is {}", 80, 34, 80+34);
    // cannot mix numerica types
    // println!("{}", 100 / 7.2); // <- This yields a compiler error
    println!("{}", 100. / 7.2);   // <- This does not

    let mut this_num = 20; // <- variables are immutable by default; must declare mutable if desired
    let that_num = -20;

    println!("{}", this_num + that_num);

    // The following doesn't work because this_num and that_num were originally declared as int
    // this_num = 20.0;
    // that_num = -20.0;
    // println!("{}", this_num + that_num);

    this_num = 30;
    // that_num = 20; <- throws a compile-time error because variable was not declared mut [i.e.,
    // mutable]
    println!("{}", this_num);

    // let next_num = 20; <- throws a compile-time warning because the variable is declared, but never used
    let _next_num = 20; // <- throws not warning, as prefixing with underscores silences 'variable not used' warnings
    let _ = 20; // also possible for throwaway variables [ala Python]; but cannot evaluate variable '_' ever, will issue a compile-time error

    // Only booleans are truthy
    // if 1 { println!("True"); }
    // if "" { println!("True"); }
    // if 3.14 < 3 { println!("True"); } <- invalid because items being compared are not of the
    // same type
    if 3 < 5 { println!("True"); }
    if "ab" < "ac" { println!("True"); } // <- sorting is lexicographical
    if "ab" < "Ac" { println!("True"); } // <- sorting is lexicographical
    if "Ab" < "ac" { println!("True"); } // <- sorting is lexicographical
    if "ab" < "abc" { println!("True"); } // <- sorting is lexicographical

    if !("ab" < "ac") { println!("!"); }
    else              { println!("!!"); }


    // can redeclare variables
    // these can change types
    let mut n = 0;
    println!("mut n {}", n);
    n = 1;
    println!("mut n {}", n);
    let n = 2.1;
    println!("n {}", n);

    let x = 3.2;
    println!("x {}", x);
    let mut x = 3;
    println!("mut x {}", x);
    x = 2;
    println!("mut x {}", x);

    let y = 3;
    println!("y {}", y);
    let y = 3.1;
    println!("y {}", y);


    // std library functions need to be imported
    println!("{} {}", str::len("abcde"), "abcde".len());

    // while (true) equivalent is:
    let mut n = 1;
    let limit = 10;
    loop {
        n += 1;
        if n >= limit { break; }
    }

    // for loops share some Python and some Haskell features
    // index variable declared in for loop shadows but does not affect the other index variable
    //      - Different scopes(?)
    let index = 8;
    for index in 1..10 {
        println!("{}", index);
    }
    println!("{}", index);

    // limit used in for loop is fixed at what value is at start
    // thus, this loop still goes through 3 cycles instead of 2 (as it would in C languages)
    let mut limit = 4;
    for i in 1..limit {
        limit -= 1;
        println!("{}", i);
    }
    println!("{}", limit);

    // arrays have a fixed size set by a constant and are homogenous of type
    // the following produces an array of 10 1s
    let arr = [1; 10];
    // and the following produces an array of 10 as
    let arr_2 = ["a"; 10];
    // multidimensional arrays also work similarly
    let multi_arr = [[1; 10]; 10];
    print!("{} {} {}", arr.len(), arr_2.len(), multi_arr.len());

    // brilliant fibonacci implementation!
    let mut fib = [1; 15];
    for i in 2..fib.len() {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for i in 0..fib.len() {
        print!("{}, ", fib[i]);
    }

    // vectors offer array structures of modifiable size, but still type-homogenous
    // can use a variable to set the length of a vector
    // but NOT the length of an array
    let length = 1;
    let mut x = vec!["this"; length];
    x.push("is");
    x.push("a");
    x.push("sentence.");
    x.insert(3, "short"); // displaces all items at and after specified index
    x[0] = "This";
    for i in 0..x.len() { print!("{} ", x[i]); }
    x.remove(3); // exact inverse of insert
    for i in 0..x.len() { print!("{} ", x[i]); }
    x.pop();
    x.pop();
    for i in 0..x.len() { print!("{} ", x[i]); }
    x.push("not a pipe.");
    for i in 0..x.len() { print!("{} ", x[i]); }

    // empty arrays & vectors are declared thus
    let _x = [""; 0];
    let _y = vec![true; 0];


    // debug printing for arrays & vectors
    let _a = ["a"; 4];
    let _b = vec![true; 4];

    println!("{:?} {:?}", _a, _b);

    // copying arrays: assignment does not just change pointer address, but actually copies the values
    // NOTE: does not work with arrays of different lengths, e.g., and array of length 3 cannot
    // be reassigned to an array of length 4
    let mut _c = [1, 2, 3];
    let mut _d = [4, 5, 6];
    println!("{:?}", _c);
    _c = _d;
    println!("{:?}", _c);
    _d[0] = -4;
    println!("{:?}", _c);

    // vectors of different lengths can be swapped
    let mut _e = vec![1, 2, 3];
    let mut _f = vec![4, 5];
    println!("{:?}", _e);
    _e = _f.to_vec();
    println!("{:?}", _e);
    _f.remove(0);
    _f.insert(0, -4);
    println!("{:?}", _e);


}
