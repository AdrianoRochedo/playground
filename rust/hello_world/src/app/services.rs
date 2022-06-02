use crate::app::models::Cachorro;

use super::models::Animal;

pub struct CommomServices;

impl CommomServices
{
    pub fn emitir_som(animal: Box<dyn Animal>) 
    {
        animal.emitir_som();
    }
}