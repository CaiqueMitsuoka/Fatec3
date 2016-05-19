var net = require('net');
var server = net.createServer( function(socket) {
    date = new Date();
    mes = (date.getMonth() + 1);
    if (mes < 10){
        mes = '0' + mes;
    }
    dia = date.getDate();
    if (dia < 10){
        dia = '0' + dia;
    }
    hora = date.getHours();
    if (hora < 10){
        hora = '0' + hora;
    }
    minuto = date.getMinutes();
    if (minuto < 10){
        minuto = '0' + minuto;
    }
    response = date.getFullYear() + '-' + mes + '-' + dia + ' ' + hora + ':' + minuto + '\n';
    socket.write(response);
    socket.end();
});
server.listen(process.argv[2]);
