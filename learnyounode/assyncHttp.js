var bl = require('bl');
var http = require('http');
cont = 0;
str = [];
function getContent(where, who){
    data = http.get(where, function callback(response) {
        response.pipe(bl(function (error, data) {
            if(error){
                console.log('error code:' + error);
            }
            str[who] = data.toString();
            cont++;
            if (cont == 3){
                for( d = 0 ; d < 3 ; d++){
                    console.log(str[d]);
                }
            }
        }));
    });
}
for( a = 0 ; a < 3 ; a++){
    getContent(process.argv[a + 2], a);
}
