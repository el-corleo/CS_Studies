/*
Complete the method/function so that it converts dash/underscore delimited words into camel casing. The first word within the output should be capitalized only if the original word was capitalized (known as Upper Camel Case, also often referred to as Pascal case). The next words should be always capitalized.
Examples

"the-stealth-warrior" gets converted to "theStealthWarrior"

"The_Stealth_Warrior" gets converted to "TheStealthWarrior"

"The_Stealth-Warrior" gets converted to "TheStealthWarrior"
*/
use std::env;


fn to_camel_case(text: &str) -> String {
    let mut mutatedStr = String::from("");
    let mut capitalize = false;
    for (i, c) in text.chars().enumerate() {
        if i == 0 { mutatedStr.push(c); continue;}
        if c == '-' || c == '_' { capitalize = true; continue; }
        if capitalize { mutatedStr.push(c.to_ascii_uppercase()); capitalize = false; continue; }
        mutatedStr.push(c);
    }
    
    return mutatedStr;
}

fn main() {
    let args: Vec<_> = env::args().collect();
    if args.len() > 1 {
        println!("{}", to_camel_case(&args[1]));
    }
}
