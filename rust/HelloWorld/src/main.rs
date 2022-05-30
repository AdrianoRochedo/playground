use std::io::stdin;

fn main() 
{
    println!("Hello world from Rust");
    readkey();
}

fn readkey()
{
    let mut buffer = String::new();
    let x = stdin().read_line(&mut buffer);
    if x.is_ok() 
    {
        // nada
    } 
}
