var OS = require('opensubtitles-api');
var OSub = new OS({
    useragent:'OSTestUserAgent', //test useragent
    username: 'user',
    password: require('crypto').createHash('md5').update('password').digest('hex'),
    ssl: true
});
var chave = '';
OSub.login()
    .then(function(token){
        chave = token;
        OSub.search({
            sublanguageid: 'pob',
            path: './silicon/Silicon Valley - s02e01.mp4',
            filename: 'Silicon Valley - s02e01.mp4',
            extensions: ['srt', 'vtt'],
            limit: 'all',
        }).then(function (subtitles) {
            console.log(subtitles);
            OSub.api.LogOut(chave);

        });
        // console.log(token);
    })
    .catch(function(err){
        console.log(err);
});
// s0osnauugg15b18qqd4cc5ak32

// var movie = [];
// OpenSubtitles.extractInfo('path/to/file.mp4').then(function (infos) {
//         console.log(infos);
//         movie = infos;
//         console.log(movie.moviehash);
//         console.log(movie.moviebytesize);
// });
