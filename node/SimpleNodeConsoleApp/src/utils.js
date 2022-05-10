
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

exports.lerArquivo = () =>
{
    var fs = require('fs');
    fs.readFile('assets/conteudo.txt', function (err, data)
    {
        if (err)
            console.error(err);
        else
        {
            console.log();
            console.log(data.toString('utf8'));
        }
    });
};

exports.retornarPessoas = () =>
{
    var jsonData = '{"persons":[{"name":"John","city":"New York"},{"name":"Phil","city":"Ohio"}]}';

    // parse json
    var jsonParsed = JSON.parse(jsonData);

    // access elements
    return jsonParsed
};
