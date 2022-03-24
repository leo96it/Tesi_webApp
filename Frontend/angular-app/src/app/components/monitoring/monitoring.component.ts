import { Component, OnDestroy, OnInit } from '@angular/core';
import { MachineryProductService } from 'src/app/services/machinery-product.service';
import { servizioTest } from 'src/app/tests/test-service.service';
import { ProductionDataModel } from "src/app/models/production-data.model";
import { Subscription } from 'rxjs';

@Component({
  selector: 'app-monitoring',
  templateUrl: './monitoring.component.html',
  styleUrls: ['./monitoring.component.css']
})
export class MonitoringComponent implements OnInit, OnDestroy
{
  //Array di macchinari con i relativi dati 
  machineryData: ProductionDataModel[] = [];

  //ID macchinario selezionato da cercare
  selected_idMachinery: string = "";

  //Contenitore di una subscribe di un Observable, la uso per fare l'unsubscribe
  subscription?: Subscription;

  //Stringa per segnalare un messaggio all'utente se l'idMachinery non è trovato
  message: string = "";

  /**
   * Flag booleano per segnalare se il bottone "Search" è attivo o meno:
   * Se flag è TRUE allora visualizza solo l'idMachinery selezionato
   * Se flag è FALSE allora visualizza tutto ciò che si riceve da backend
   */ 
  buttonFlag: boolean = false;

  constructor(private mpService: MachineryProductService, private testService: servizioTest) { }

  ngOnInit(): void 
  {
    //console.log('Componente Monitoring inizializzato');

    this.message = ""; //Svuoto la stringa contenente il messaggio

    /* Richiesta dati al servizio */
    //this.subscription = this.testService.getDati().subscribe(res => this.machineryData = res);  //* TEST con dati mockati
    this.subscription = this.mpService.getDati().subscribe(res => 
    {
      this.mpService.popAll(this.machineryData); //svuoto array machineryData

      /*
      * Con Object.assign faccio a meno di usare l'operatore "=" che in javascript
      * assegna ad entrambi gli operandi lo stesso valore.
      * [] serve per specificare il tipo di ritorno, ovvero un array.
      */
      this.machineryData = Object.assign([], res); 

      /**
       * Funzione per la ricerca di un solo macchinario con 
       * idMachinery uguale a quello inserito nel form su HTML
       */
      this.viewOneMachinery();
    });
  }



  selectMachinery(event: any)
  {
    this.buttonFlag = true; 

    //Cerca idMachinery in machineryData
    const machineryFound = this.machineryData.find(machinery => machinery.idMachinery === this.selected_idMachinery);
    
    if(machineryFound != undefined) { return; } //Se l'idMachinery esiste allora esci

    this.mpService.stopPollingFunction(); //Fermo il polling
    this.mpService.popAll(this.machineryData); //Rimuovo tutti gli elementi da machineryData

    this.message = "Machinery not found!"; //Stampo un messaggio di errore
  }


  viewOneMachinery(): void
  {
    if(this.buttonFlag)
    {
      this.machineryData = this.machineryData.filter(item => item.idMachinery === this.selected_idMachinery);
    }
  }


  reloadMachinery(event: any) 
  {
    this.message = "";
    this.selected_idMachinery = "";
    this.buttonFlag = false; 

    this.ngOnInit(); //Riprendi il polling dei dati
  }


  ngOnDestroy(): void 
  {
    /**
     * Alla distruzione del componente smetti di effettuare richieste
     */
    this.subscription?.unsubscribe();

    //console.log('Componente distrutto');
  }
}
