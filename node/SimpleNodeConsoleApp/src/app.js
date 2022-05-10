var utils = require("./utils");

console.clear();

console.log("Ola, Adriano");
console.log();

utils.teste();
console.log();

utils.lerArquivo();
console.log();

var pessoa = utils.retornarUmaPessoa();
console.log(pessoa);
console.log();

var pessoas = utils.retornarPessoas();
console.log(pessoas);
console.log();

utils.keyPress();