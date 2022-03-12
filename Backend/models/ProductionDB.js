/**
 * Questo modulo rappresenta la tabella e racchiude al suo interno tutti gli attributi 
 * e le caratteristiche della tabella, come il tipo di dato delle colonne, il numero di colonne,
 * il nome della tabella (che è definito in db.define ed in tableName)
 */

 const Sequelize = require("sequelize"); //importo il modulo sequelize
 const db = require("../routes/initDB"); //richiedo il modulo per l'inizializzazione del DB
 const settings = require('../configuration/config.json');
 
 // Modello per la tabella Production
 const table = db.define(settings.database.tableName, 
 {
   id: 
   {
     type: Sequelize.INTEGER,
     primaryKey: true,
     autoIncrement: true
   },
   idMachinery: 
   {
     type: Sequelize.STRING,
     allowNull: false
   },
   idProduct: 
   {
     type: Sequelize.STRING,
     allowNull: false
   },
   position: 
   {
     type: Sequelize.STRING,
     allowNull: false
   },
   status: 
   {
     type: Sequelize.BOOLEAN,
     allowNull: true,
     default: false
   },
   errorCode: 
   {
     type: Sequelize.INTEGER,
     allowNull: true
   }
 },
 {
   // Define the table's name
   tableName: settings.database.tableName
 });
 
 module.exports = table;