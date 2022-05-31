
use std::io;
use rand::Rng;

fn main() 
{
    guess_the_number();
}

// exemplos:
//   - leitura de conteudo do console
//   - geracao de numero aleatorio
//   - conversao de string para numero
//   - captura de erro
//   - comparacao
fn guess_the_number()
{
    println!("\nGuess the number!\n");

    // seu chute

    println!("Please input a number between 1 and 100");

    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

    println!("You guessed: {}", guess);

    // numero sorteado
    
    let secret_number = rand::thread_rng().gen_range(1..100);

    // teste

    match guess.trim().parse::<i32>()
    {
        Ok(guess_number) => 
        {
            use std::cmp::Ordering;

            match guess_number.cmp(&secret_number) 
            {
                Ordering::Less    => println!("Too small!"),
                Ordering::Greater => println!("Too big!"),
                Ordering::Equal   => println!("You win!"),
            }    
        },

        Err(_) => 
        {
            println!("{guess} is not a number !")
        },
    }

    println!("The secret number is: {}", secret_number);

}
