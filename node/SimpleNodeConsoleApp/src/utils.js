
exports.keyPress = () =>
{
    var rl = require("readline");
    var prompts = rl.createInterface(process.stdin, process.stdout);
    prompts.question("Precione qualquer tecla para finalizar", function (conteudo)
    {
        process.exit();
    });
};

exports.teste = () =>
{
    console.log("teste");
};

