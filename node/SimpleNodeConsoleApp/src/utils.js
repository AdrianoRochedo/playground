
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
    try
    {
        var data = fs.readFileSync('assets/conteudo.txt');
        console.log();
        console.log(data.toString('utf8'));
    }
    catch (err)
    {
        console.error(err);
    };
};

exports.retornarPessoas = () =>
{
    var jsonData = '{"persons":[{"name":"John","city":"New York"},{"name":"Phil","city":"Ohio"}]}';

    // parse json
    var jsonParsed = JSON.parse(jsonData);

    // access elements
    return jsonParsed
};

exports.retornarUmaPessoa = () =>
{
    var pessoa =
    {
        name: 'John Doe',
        emai: 'john.doe@example.com',
        age: 27,
        gender: 'Male',
        profession: 'Software Developer'
    };

    return pessoa;
};
