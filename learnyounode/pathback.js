module.exports = function listaext (caminho, ext, Print) {
    var fs = require('fs');
    var path = require('path')
    fs.readdir (caminho, function opa (err, data) {
        if (err != null){
            return Print(null)
        }
        data.forEach (function (cam) {
            if (path.extname(cam) === '.' + ext) {
                return Print(cam);
            }
        })
    });
}
