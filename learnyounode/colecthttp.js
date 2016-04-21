var bl = require('bl')
var http = require('http')
http.get(process.argv[2], function callback(response) {
    response.pipe(bl(function (error, data) {
        if(error){
            console.log('error code:' + error)
        }
        console.log( data.length)
        console.log(data.toString())
    }));
});
