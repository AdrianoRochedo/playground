
// Rust nao tem heranca (da implementacao) pois nao eh OOP full .. mas (olhar mais abaixo)

// -----------------------------------------------

// interface

pub trait Animal
{
    fn emitir_som(&self);
}

// object factory

pub fn criar_animal(animal: char) -> Box<dyn Animal>
{
    if animal == 'C'
    {
        return Box::new(Cachorro {raça: "Pastor".to_string(), num_patas: 4})
    }

    if animal == 'G'
    {
        return Box::new(Gato {})
    }

    panic!("animal desconhecido");
}

// ------------------------------------------------

// classe Cachorro 

#[derive(Debug)]
pub struct Cachorro
{
    raça: String,
    num_patas: i32,
}

impl Animal for Cachorro 
{
    fn emitir_som(&self)
    {
        println!("au au");
    }    
}

// classe Gato

pub struct Gato
{

}

impl Animal for Gato 
{
    fn emitir_som(&self)
    {
        println!("miau");
    }    
}

// ----------------------------------------------

// mas a herenca de traits eh permitida

// https://doc.rust-lang.org/rust-by-example/trait/supertraits.html

trait Person {
    fn name(&self) -> String;
}

// Person is a supertrait of Student.
// Implementing Student requires you to also impl Person.
trait Student: Person {
    fn university(&self) -> String;
}

trait Programmer {
    fn fav_language(&self) -> String;
}

// CompSciStudent (computer science student) is a subtrait of both Programmer 
// and Student. Implementing CompSciStudent requires you to impl both supertraits.
trait CompSciStudent: Programmer + Student {
    fn git_username(&self) -> String;
}

fn comp_sci_student_greeting(student: &dyn CompSciStudent) -> String {
    format!(
        "My name is {} and I attend {}. My favorite language is {}. My Git username is {}",
        student.name(),
        student.university(),
        student.fav_language(),
        student.git_username()
    )
}

// .. implementar todos os traits num tipo concreto
