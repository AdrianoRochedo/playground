fn main() 
{
    println!("Hello world from Rust");
    readkey();
}

fn readkey()
{
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed to read line"); 
}
