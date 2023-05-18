use std::io;
use std::io::{Write, BufReader, BufRead, ErrorKind};
use std::fs::File;
use std::cmp::Ordering;
use rand::Rng;


fn returning2(x: i32) -> i32 {
    return x * 2;
}


fn returning(x: i32) -> i32 {
    x * 2
    // NOTE: that a semicolon would make the compiler throw and error
}


fn vectors() {
    let vec1: Vec<i32> = Vec::new();
    let mut vec2: Vec<i32> = vec![1,2,3,4];
    vec2.push(5);

    let second: &i32 = &vec2[1];
    match vec2.get(1) {
        Some(second) => println!("2nd: {}", second),
        None => println!("Absent")
    }

    // double
    for i in &mut vec2 {
        *i *= 2;
    }
    for i in &vec2 {
        println!("{}", i);
    }
}


fn enums() {
    enum Day {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    }

    impl Day {
        fn is_weekend(&self) -> bool {
            match self {
                Day::Saturday | Day::Sunday => true,
                _ => false
            }
        }
    }

    let today: Day = Day::Monday;

    println!("Today is a weekend day! {}", today.is_weekend());
}



fn casting() {
    let int_u8: u8 = 5;
    let int2_u8: u8 = 4;
    let int3_u32: u32 = (int_u8 as u32) + (int2_u8 as u32);
    println!("{}", int3_u32);
}


fn strings() {
   let mut st1: String = String::new(); 
   st1.push('A');
   st1.push_str("word");

   for word in st1.split_whitespace() {
       println!("{}", word);
   }

    let st2: String = String::from("d o o u c c h e e");
    let mut v1: Vec<char> = st2.chars().collect();
    v1.sort();
    v1.dedup();

    for char in v1 {
        println!("{}", char);
    }

    let string_literal: &str = "String literal";
    let mut heap_allocated_str: String = string_literal.to_string();
    
    let byte_arr: &[u8] = heap_allocated_str.as_bytes();
    let slice_of_str: &str = &heap_allocated_str[3..10];
    println!("{}", slice_of_str);
}


fn looping() {
    let arr_1: [i32; 4] = [1,2,3,4];
    let mut ind: usize = 0;
    loop {
        if arr_1[ind] == 4 {
            break;
        }
 
        if arr_1[ind] % 2 == 0 {
            ind += 1;
            continue;
        }

        println!("elem: {}", arr_1[ind]);
        ind += 1;
    }

    ind = 0;
    while ind < arr_1.len() {
        println!("elem: {}", arr_1[ind]);
        ind += 1;
    }

    ind = 0;
    for elem in arr_1.iter() {
        println!("elem: {}", arr_1[ind]);
    }

}


fn arrays() {
    let arr_1: [i32; 4] = [1,2,3,4];
    println!("1st elem = {}", arr_1[0]);
    println!("Length arr_1 = {}", arr_1.len());
}


fn matching() {
    let number: i32 = 27;
    match number {
        1..=10 => println!("Not in 1..=10"),
        11..=20 => println!("Not in 11..=20"),
        _ => println!("Something more than 20.")
    };

    let age: i32 = 37;
    let voting_age: i32 = 18;
    match age.cmp(&voting_age) {
        Ordering::Less => println!("Can't vote"),
        Ordering::Greater => println!("Can vote"),
        Ordering::Equal => println!("Can barely vote")
    };
}


fn randNumGen() {
    let random_num: i32 = rand::thread_rng().gen_range(1..101);
    println!("Random: {}", random_num);
}


fn variables() {
    const PI: f32 = 3.145262;
    // shadowing
    let age: &str = "42";
    let mut age: u32 = age.trim().parse()
        .expect("Age wasn't assigned a number.");
    age += 1;
    println!("I am {} years old.", age);
}


fn sayHello() {
    println!("What's your name?");
    let mut name: String = String::new();
    let greeting: &str = "Nice to meet you.";
    io::stdin().read_line(&mut name)
        .expect("Didn't receive input.");
    println!("Hello, {}! {}", name.trim_end(), greeting);
}

fn main() {
    sayHello();
    variables();
    randNumGen();
    matching();
    arrays();
    looping();
    strings();
    casting();
    enums();
    vectors();
    println!("{}", returning(5));
    println!("{}", returning2(10));
}
