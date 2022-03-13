/**
 * In questa route vado a definire il percorso e le funzioni per raccogliere i dati  
 * sullo stato del ciclo di produzione, tramite delle POST da parte di ESP32 e le
 * fornisco al client che effettua delle GET
 */

const express = require('express'); //importo il modulo express
const router = express.Router(); //importo il modulo interno di express per la gestione delle route

//definisco un modello per i dati di produzione da salvare sul database
const productionDB = require("../models/ProductionDB");

var dati = []; // variabile array per la memorizzazione dei dati di produzione


// localhost:3000/produzione/monitora
router.get("/monitora", (req,res) =>
{
    /* Se si vuole inviare del semplice testo 
    res.set('Content-Type', 'text/plain');
    res.write("Pagina produzione");
    res.status(200).end();
    */
    
    // Invio dei dati di produzione
    res.send(dati).status(200); 
});



// localhost:3000/produzione/inserisci
router.post("/inserisci", (req,res) =>
{
    let {idMachinery,idProduct,position,status,errorCode} = req.body;
    let dato = req.body;
    let i;


    console.log(i);
    //ricerca del codice idMachienry all'nterno dell'array "dati"
    dati.forEach( (element, index) =>
    {
        if(element.idMachinery === dato.idMachinery) 
        {
            i = index;
        }
    });
    console.log(i);

    if(i === undefined || (i === 0 && dati.length < 1))
    {
        //inserisce nuovo elemento nell'array
        dati.push(req.body);
    }
    else
    {
        //sostituisce elemento con idMachinery uguale
        dati.splice(i, 1, req.body);
    }



    console.log("Dati da inviare ad Angular: ");
    console.log(idMachinery + ", " + idProduct + ", " + position + ", " + status + ", " + errorCode);

    res.send("Ricevuto").status(200);

    //inserisce nuova riga nel DB
    addRow({idMachinery,idProduct,position,status,errorCode});
});


function addRow({idMachinery,idProduct,position,status,errorCode}) 
{
    //funzione di sequelize per creare una riga in tabella
    productionDB.create({idMachinery,idProduct,position,status,errorCode}) 
    .catch(err => console.log(err));
}

module.exports = router;