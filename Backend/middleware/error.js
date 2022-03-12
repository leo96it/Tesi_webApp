function errorHandler(err, req, res, next)
{
    //err= oggetto che solleviamo in fase di istanziamento dell'errore
    console.log(err.code + " " + err.message);
    next(err); //passaggio dell'errore al prossimo middleware
}

module.exports = errorHandler;