fn main() {
    print!("{}, {}\n", "Hello", "World!");
    println!("This is a thing, too.");
    println!("The sum of {} and {} is {}", 80, 34, 80+34);
    // cannot mix numerica types
    // println!("{}", 100 / 7.2); // <- This yields a compiler error
    println!("{}", 100. / 7.2);   // <- This does not

    let mut this_num = 20;
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
}
