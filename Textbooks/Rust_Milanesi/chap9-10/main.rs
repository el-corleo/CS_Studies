fn main() {
    let mut arr = [5, -4, 9, 0, -7, -1, 3, 5, 3, 1];
    // this and double_negatives_again are functionally equivalent
    double_negatives(&mut arr);
    println!("{:?}", arr);
    double_negatives_again(&mut arr);
    println!("{:?}", arr);

    // other uses of references
    let a = 15;
    let a_ref = &a;

    println!("{} {} {}", a, *a_ref, a_ref); // a_ref is auto-dereferenced

    // mutability of references
    let mut a: i32 = 10;
    let mut b: i32 = 20;
    let mut p: &mut i32 = &mut a;
    println!("{} ", *p);
    *p += 1;
    print!("{} ", *p);
    // println!("a={} | *p={} ", a, *p); <-- throws an immutable borrow error
    // println!("a={} | *p={} ", &mut a, *p); <-- throws a second mutable borrow error
    // These two errors disappear as soon as p is reassigned to &mut b in the following line
    p = &mut b;
    print!("{} ", *p);
    *p += 1;
    print!("{}", *p);

    println!("a={} | *p={} ", &mut a, *p);

    // GENERIC FUNCTIONS
    println!("{}", print_stuff('a', 3.2, 16.2));
    println!("{:?}", print_diff_stuff(3.2, 16));
}

fn double_negatives(a: &mut [i32; 10]) {
    for i in 0..10 {
        // dereference needs to be in parenthesis because [] has a higher precedence than *
        if (*a)[i] < 0 { (*a)[i] *= 2; }
    }
}

fn double_negatives_again(a: &mut [i32; 10]) {
    for i in 0..10 {
        if a[i] < 0 { a[i] *= 2; }
    }
}

fn print_stuff<T>(ch: char, num1: T, num2: T) -> T {
    if ch == 'a'  { num1 }
    else          { num2 }
}

fn print_diff_stuff<T,U>(first: T, second: U) -> (T, U) {
    (first, second)
}
