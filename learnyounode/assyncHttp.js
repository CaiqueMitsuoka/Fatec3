var bl = require('bl');
var http = require('http');
var str = [];
var a;
var much = 0;
data = http.get(process.argv[2], function callback(response) {
    response.pipe(bl(function (error, data) {
        if(error){
            console.log('error code:' + error);
        }
        str[0] = data.toString();
        much++;
    }));
});
data.setEncoding('utf-8')
console.log(data.response);
// http.get(process.argv[3], function callback(response) {
//     response.pipe(bl(function (error, data) {
//         if(error){
//             console.log('error code:' + error);
//         }
//         str[1] = data.toString();
//         much++;
//     }));
// });
// http.get(process.argv[4], function callback(response) {
//     response.pipe(bl(function (error, data) {
//         if(error){
//             console.log('error code:' + error);
//         }
//         str[2] = data.toString();
//         much++;
//     }));
// });
