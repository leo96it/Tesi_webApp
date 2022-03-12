function responseError(err, req, res, next)
{
    //err= oggetto che solleviamo in fase di istanziamento dell'errore
    res.status(err.code).send(err.message); 
}

module.exports = responseError;