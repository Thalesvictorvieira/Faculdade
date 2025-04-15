var canvas = document.getElementById('progress');
var ctx = canvas.getContext('2d');
var x = 0;
var y = 0;
var altura = 10;
var largura =0;
var fator = 60;
var resolucao = 1280;

ctx.fillStyle = "#4169E1";
function animacao(){
    ctx.fillRect(x,y,largura = largura + fator, altura);
    if (largura > resolucao){
        clearInterval(atualiza);
    }
}
var atualiza = setInterval(animacao, 10);