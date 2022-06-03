var utils = require("./utils");
var classes = require("./class");

console.clear();

console.log("Ola, Adriano");
console.log();

utils.teste();
console.log();

utils.lerArquivo();
console.log();

const pessoa = utils.retornarUmaPessoa();
console.log(pessoa);
console.log();

const pessoas = utils.retornarPessoas();
console.log(pessoas);
console.log();

const rec = new classes.Rectangle(5, 20);
console.log(rec.toString());
console.log();

const square = new classes.Square(5);
console.log(square.toString());
console.log();

utils.keyPress();