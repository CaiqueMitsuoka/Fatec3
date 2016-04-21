var fs = require('fs')
var file = fs.readFileSync(process.argv[2])
var strr = file.toString()
var cont = 0
for (var a = 0; a < strr.length; a++) {
  if (strr[a] === '\n') {
    cont += 1
  }
}
console.log(cont)
