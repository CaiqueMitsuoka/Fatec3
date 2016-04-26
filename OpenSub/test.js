var OS = require('opensubtitles-api');
var OSub = new OS({
    useragent:'UserAgent',
    username: 'Username',
    password: 'Password',
    ssl: false
});
OSub.login()
    .then(function(token){
        console.log(token);
    })
    .catch(function(err){
        console.log(err);
});
// var movie = [];
// OpenSubtitles.extractInfo('path/to/file.mp4').then(function (infos) {
//         console.log(infos);
//         movie = infos;
//         console.log(movie.moviehash);
//         console.log(movie.moviebytesize);
// });
