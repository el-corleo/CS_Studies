fn main() {
    print!("{}, {}\n", "Hello", "World!");
    println!("This is a thing, too.");
    println!("The sum of {} and {} is {}", 80, 34, 80+34);
    // cannot mix numerica types
    // println!("{}", 100 / 7.2); // <- This yields a compiler error
    println!("{}", 100. / 7.2);   // <- This does not
}
