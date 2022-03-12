/**
 * Server che gestisce la comunicazione tra diversi client (in questo caso solo 1), per il 
 * monitoraggio del processo produttivo di una linea di produzione.
 * Il server riceve, tramite le API HTTP, dei dati da un ESP32 (il client), il quale li 
 * preleva da dei sensori posti sulla macchina. Il server alla ricezione dei dati, effettua 
 * delle query ad un database (Mysql in questo caso) e le stampa a browser tramite Angular.
 */


const express = require('express'); //importo il modulo express
const production = require("./routes/production.js"); //definisco tutte le route per l'invio dei dati di produzione

const errorHandler = require('./middleware/error');
const responseError = require('./middleware/errorResponder');

const app = express(); //creo un'istanza di express
const settings = require('./configuration/config.json');
const port = settings.server.port; //definisco la porta del server

// CORS policy
app.use((req, res, next) => 
{
  res.header("Access-Control-Allow-Origin", "*");
  res.header("Access-Control-Allow-Methods", "GET,PUT,POST,DELETE,PATCH,OPTIONS");
  res.header("Access-Control-Allow-Headers", "Content-Type, Authorization, Content-Length, X-Requested-With");
  next();
});

app.use(express.json()); //middleware di express per leggere i json
app.use(express.text()); //middleware di express per leggere i testi

// Utilizzo la route production per definire tutti i percorsi dopo localhost:3000/produzione
app.use('/produzione', production);

app.use(errorHandler); //middleware per la gestione degli errori
app.use(responseError); //middleware per la risposta agli errori


// Richieste HTTP
app.get('/', (req, res) => 
{
    res.send("Accesso eseguito!").status(200);
});


// Definisco una funzione per per gestire tutte le richieste a path inesistenti
app.all("*", (req,res) =>
{
    res.send("404 non trovato").status(404);
});


// Metto il server in ascolto sulla porta "port"
app.listen(port, () => console.log(`Server app listening on port ${port}!`)); 

// Evita che node si chiuda su un errore (se non c'è nodemon)
process.on('uncaughtException', function (err) 
{
    console.log('Caught exception: ', err);
});
