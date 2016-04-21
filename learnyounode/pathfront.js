function imprimir (who) {
    console.log(who);
}
var back = require('./pathback.js')
back(process.argv[2], process.argv[3], imprimir)
