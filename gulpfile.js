var gulp = require( 'gulp' );
var gutil = require( 'gulp-util' );
var ftp = require( 'vinyl-ftp' );
 
gulp.task( 'deploy', function () {
 
    var conn = ftp.create( {
        host:     'csc.oakton.edu',
        user:     'akuzniat1236',
        password: 'QjAyMjExMjM2',
        port: 22,
        parallel: 10,
        log:      gutil.log
    } );
 
    var globs = [
        './**',
        '/**'
    ];
 
    // using base = '.' will transfer everything to /public_html correctly 
    // turn off buffering in gulp.src for best performance 
 
    return gulp.src( globs, { base: '.', buffer: false } )
        .pipe( conn.newer( '/labs' ) ) // only upload newer files 
        .pipe( conn.dest( '/labs' ) );
 
} );