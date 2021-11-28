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
}
