
use std::io;
use rand::Rng;

pub mod app;

fn main() 
{
    print!("\n");

    //guess_the_number();
    common_programming_concepts();
    understanding_ownership();
    structs();
}

// itens:
//   - leitura de conteudo do console
//   - geracao de numero aleatorio
//   - conversao de string para numero
//   - captura de erro
//   - comparacao
fn guess_the_number()
{
    title("Guess the number -------------------");

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

// itens:
//   - shadowing
//   - data types
fn common_programming_concepts()
{
    title("Common Programming Concepts -----------------");

    fn shadowing()
    {
        title("Shadowing");

        let x = 5;

        let x = x + 1;
    
        {
            let x = x * 2;
            println!("The value of x in the inner scope is: {}", x);
        }
    
        println!("The value of x is: {}", x);    
    }

    fn data_types()
    {
        title("Data Types (primitives)");

        // integers
        let int_32  : i32 = "42".parse().expect("Not a number!"); // i32 (default)
        let int_128 : i128 = 125_887_665_665_554_553_333; // i128

        // floats
        let f_32 : f32 = 2.6654; // float
        let f_64 : f64 = 2.2456; // double (default)

        // boolean
        let b : bool = true;

        title("Advanced Data Types");

        // tuples
        let tup: (i32, f64, u8) = (500, 6.4, 1);
        
        // tuples => deconstrucao
        let (x, y, z) = tup;

        // tuples => deconstrucao individual
        let x = tup.0;
        let y = tup.1;
        let z = tup.2;

        //arrays
        let a = [1, 2, 3, 4, 5];
        let a: [f32; 5] = [1.0, 2.0, 3.14, 4.0, 5.1];
        let a = [3; 5]; // [3, 3, 3, 3, 3]

        // print
        println!("int 128 => {}", int_128);
        println!("f 64    => {}", f_64);
        println!("boolean => {}", b);
        println!("tuple   => {}", tup.2);
        println!("array   => {}", a[3]);

    }

    shadowing();
    data_types();
}

// itens:
fn understanding_ownership()
{
    title("Understanding Ownership --------------------");

    fn ownership()
    {
        title("Ownership");
        // https://doc.rust-lang.org/book/ch04-01-what-is-ownership.html

        // NAO PODE (pois referenciam a mesma area de memoria => HEAP)
        let x = String::from("hello");
        let y = x;
        // println!("{}, world!", x); ERRO => borrow of moved value: `x`

        // PODE (com clonagem => as referencias serao diferentes)
        let s1 = String::from("hello");
        let s2 = s1.clone();
        println!("s1 = {}, s2 = {}", s1, s2);        

        // PODE - tipos primitivos (pois aqui existe a COPIA pois estamos na STACK)
        let x = 5;
        let y = x;
        println!("x = {}, y = {}", x, y);

        // devolvendo a posse (ownership) de algo criado internamente por uma funcao
        fn criar_string(v: i32) -> String
        {
            let s = String::from("criar string => ") + &v.to_string();
            return s;
        }

        let s1 = criar_string(12345);
        println!("devolvendo a posse => {}", s1);
    }

    fn references_and_borrowing()
    {
        title("References and Borrowing");
        // https://doc.rust-lang.org/book/ch04-02-references-and-borrowing.html

        fn change(some_string: &mut String) 
        {
            some_string.push_str(", world");
        }
        
        // mudando algo criado em outro lugar
        let mut s = String::from("hello"); // "s" eh criado aqui e sera modificado por "change"
        change(&mut s);
        println!("{}", s);
        change(&mut s);
        println!("{}", s);

        title("Dangling References");

        println!("Ver exemplo no codigo");
        
        //fn dangle() -> &String // error[E0106]: missing lifetime specifier
        //{
        //    let s = String::from("hello");
        //    return &s;
        //}
        //let reference_to_nothing = dangle();

        println!("solucao => retornar diretamente a string => fn dangle() -> String ... return s;");
        println!("pois assim nao havera desalocacao na perda do scopo e a posse sera passada para quem chamou");

    }

    fn the_slice_type()
    {
        title("The Slice Type");

        // https://doc.rust-lang.org/book/ch04-03-slices.html

        // Slices let you reference a contiguous sequence of elements in a collection rather than the whole collection. 
        // A slice is a kind of reference, so it does not have ownership.
        // String Literals Are Slices (&str)
        // &str is an immutable reference

        fn first_word(s: &str) -> &str 
        {
            let bytes = s.as_bytes();
        
            for (i, &item) in bytes.iter().enumerate() {
                if item == b' ' {
                    return &s[0..i];
                }
            }
        
            return &s[..];
        }

        let s = "adriano rochedo conceicao";
        let word = first_word(s); // pode ser "s" ou "&s"
        println!("{}", word);

        let s = String::from("adriano rochedo conceicao");
        let word = first_word(&s);
        println!("{}", word);
    }

    ownership();
    references_and_borrowing();
    the_slice_type();
}

fn structs()
{
    title("Structs");

    use app::structs::*;

    let s1 = MyStruct1
    {
        bool_field: true,
        int_field: 49,
    };

    println!("{:?}", s1);
}

fn title(s: &str)
{
    print!("\n{s}\n\n");
}