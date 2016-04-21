var fs = require('fs');
fs.readdir(process.argv[2], function callback (err, data) {
    // console.log(data);
    for(var a = 0; a < data.length; a++) {
        file = data[a].split('.')
        if (file[1] == process.argv[3]){
            console.log(data[a]);
        }
    }
});
