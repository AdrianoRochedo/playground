
// Rust nao tem heranca pois nao eh OOP full

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
