//deverá fazer validação de campo para coleta de e-mail.
//Mostrar mensagem de erro e de orientação 
//(escolha a melhor forma de apresesentar essa mensagem)
//explicando a estrutura de um e-mail.

var email;
function getEmail(){
    email = document.getElementById("email").value;

    // Verifica se o email está vazio ou contém apenas espaços
    if (email.trim() === '') {
        console.log('O email não é válido');
        alert('Esse email não e valido')
    } else {
        console.log(email);
    }
}