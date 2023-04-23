use std::io;
use std::io::{Write, BufReader, BufRead, ErrorKind};
use std::fs::File;
use std::cmp::Ordering;
use rand::Rng;


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
        Ordering::Equal => println!("rust_analyzer sucks")
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
}
