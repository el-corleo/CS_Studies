fn main() {
    let _a: i8 = 5;
    let _b: i16 = 5;
    let _c: i32 = 5;
    let _d: i64 = 5;

    // Will not compile
    //let q = a + b;
    //println!("{}", q);

    // also have unsigned ints
    // for when negatives not needed
    let _e: u8 = 5;
    let _f: u16 = 5;
    let _g: u32 = 5;
    let _h: u64 = 5;

    // an int that is sized according to OS
    // 32-bit or 64-bit (Rust apparently doesn't support 16-bit OSes)
    let _i: isize = 2;

    let arr = [1, 2, 3];
    let j: usize = 2;
    println!("{}", arr[j]);
    // NOTE:
    // print!("{}", arr[i])
    // would generate a compilation error
    // as would a u32 int on a 64-bit system and vice versa
    // In fact, Rust will not allow u32/u64 ints as pointers
    //      directly on 32-bit/64-bit OS for reasons of portability

    // for int type inference, the default is i32
    // thus, the following generaters a compiler error
    //let k = 8_000_000_000;
    //print!("{}", k);

    // floating-point number types include only: f32 and f64
    // default for float is f64

    // casting is possible
    // downcasting & upcasting both possible
    // downcasting appears to truncate
    let k: i16 = 12;
    let l: u32 = 4;
    let m: f32 = 3.7;
    println!("{}", k as i8 + l as i8 + m as i8);
    println!("{}", k as f64 + l as f64 + m as f64);

    // enum
    #[derive(PartialEq)]
    enum Attacks {
        Punch,
        Kick,
        Throw,
    }

    // match (i.e., switch statements)
    let mut attack = Attacks::Punch;

    while attack != Attacks::Throw {
        match attack {
            Attacks::Punch => {
                println!("Kick!");
                attack = Attacks::Kick;
            },
            Attacks::Kick => {
                println!("Hiya!");
                attack = Attacks::Throw;
            },
            Attacks::Throw => println!("Finish it! THROW!"),
        }
    }

    // default case
    match attack {
        Attacks::Punch => println!("This is impossible."),
        Attacks::Kick => println!("This ain't happening."),
        _ => println!("This is a default case."),
    }

    // more complex enums
    enum Result {
        Success(f64),
        Failure(u16, char),
        Uncertainty,
    }

    let outcome = Result::Failure(1200, 'x');

    match outcome {
        Result::Success(value) =>
            println!("Result: {}.", value),
        Result::Failure(error_code, module) =>
            println!("Error {} in module {}.", error_code, module),
        _ => {},
    }

    // this is also possible
    for n in -2 .. 5 {
        println!("{} is {}.", n, match n {
            0 => "zero",
            1 => "one",
            _ if n < 0 => "negative",
            _ => "positive",
        })
    }

    // tuples
    let mut tup_1 = ("Bobo", 5, 29.9);
    println!("{} {} {}", tup_1.0, tup_1.1, tup_1.2);
    tup_1.0 = "Bobo McGee";
    println!("{} {} {}", tup_1.0, tup_1.1, tup_1.2);

    // can also be explicit
    let tup_2: (&str, u8, f32) = ("Bobo", 5, 29.9);
    println!("{} {} {}", tup_2.0, tup_2.1, tup_2.2);

    // structs are like tuples but with named fields
    struct Bobo {
        name: String,
        age: u8,
        wenis: f32,
    }

    let generic_bobo = Bobo {
        name: "Bobo McGee".to_string(),
        age: 10,
        wenis: 29.9,
    };

    println!("{} {} {}", generic_bobo.name, generic_bobo.age, generic_bobo.wenis);

    // tuple-structs exist, which are basically structs with unnamed fields
    // NOTE: use parentheses instead of curly braces
    struct SomeData (
        i32,
        f32,
        char,
        [u8; 5],
    );
    let data = SomeData (
        10_000_000,
        183.19,
        'Q',
        [9, 0, 250, 60, 200],
    );
    println!("{}, {}, {}, {}", data.2, data.0, data.1, data.3[2]);


    // ON CONVENTIONS
    const MAXIMUM_POWER: u16 = 600; // constants are underscore-separated caps

    // structs and enums are PascalCase
    enum VehicleKind {
        Motorcycle,
        Car,
        Truck,
    }

    // variable names are underscore-separated lower case
    struct VehicleData {     
        kind: VehicleKind,     
        registration_year: u16,     
        registration_month: u8,     
        power: u16,
    }

    let vehicle = VehicleData {     
        kind: VehicleKind::Car,     
        registration_year: 2003,     
        registration_month: 11,     
        power: 120,
    };

    if vehicle.power > MAXIMUM_POWER {     
        println!("Too powerful");
    }
}
