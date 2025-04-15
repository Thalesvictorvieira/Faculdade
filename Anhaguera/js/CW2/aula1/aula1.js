let idade = parseInt(prompt("Informe a sua idade:"));
let body = document.body;
let msg = document.getElementById("mensagem");

if (idade <= 18) {
    body.style.background = 'DarkRed';
    msg.style.fontSize = 'xx-large';
    msg.style.color = 'Cornsilk';
    msg.innerHTML = 'Você é menor de idade';
} else {
    body.style.background = "Aquamarine";
    msg.style.fontSize = "xx-large";
    msg.style.color = "CadetBlue";
    msg.innerHTML = 'Você é maior de idade';
}
