/**
 * Utilizzo di sequelize, che è un framework ORM (Object Relational Mapper), ovvero una tecnica
 * (modello di progettazione) per accedere a DB relazionali, utilizzando un linguaggio OO (Object Oriented).
 * Sequelize necessita appunto di questa interfaccia ORM che traduce il linguaggio e la logica,
 * questa interfaccia è costituita dall'oggetto che fornisce l'accesso ai dati ed in particolare agli 
 * attributi ed alle entità della tabella (le colonne). Nel nostro caso questa interfaccia è rappresentata 
 * dal modello "ProductionDB" nella cartella "models"
 */

const Sequelize = require("sequelize"); //importo il modulo sequelize
const settings = require('../configuration/config.json');

// Fornisco i dati di accesso al DB 
const db = new Sequelize(settings.database.dbname, settings.database.user, settings.database.password, settings.database.options);


// Effettuo un test per verificare la connessione
db.authenticate()
.then(() => 
{
  console.log("Database connected");
})
.catch((err) => console.log(err));


// Synchronization database
/**
 * Permette di sincronizzare il database con le query che andiamo a creare,
 * quindi, se la tabella non c'è la crea, se ha una colonna in meno la aggiunge...
 */
db.sync(
{
    force: false, //false: se la tabella esiste già non ne ricrea una nuova
    alter: true //true: controlla lo stato dell'attuale tabella sul DB ed applica i cambiamenti per farla corrispondere a ciò che gli passiamo
})
.then(() => 
{
    console.log("Database synchronized");
})
.catch((err) => console.log(err));
  


module.exports = db;