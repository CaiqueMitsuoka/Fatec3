var http = require ('http');
http.get(process.argv[2], function callback (response){
    // console.log('got response : ' + response.statusCode);
    response.on ("data", console.log);
    response.on ("error", console.error);
});
