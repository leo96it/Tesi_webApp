import { Component, OnDestroy, OnInit } from '@angular/core';
import { Subscription } from 'rxjs';
import { ProductionDataModel } from 'src/app/models/production-data.model';
import { MachineryProductService } from 'src/app/services/machinery-product.service';
import { servizioTest } from 'src/app/tests/test-service.service';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit, OnDestroy
{
  //Array di macchinari con i relativi dati 
  machineryData: ProductionDataModel[] = [];

  //Array contenente gli idMachinery disponibili
  idsMachinery: string[] = [];

  //Contenitore di una subscribe di un Observable, la uso per fare l'unsubscribe
  subscription?: Subscription;

  //ID macchinario da cercare
  selected_idMachinery: string = ""; 


  constructor(private mpService: MachineryProductService, private testService: servizioTest) { } 

  ngOnInit(): void 
  { 
    //console.log('Componente Home inizializzato');

    /* Richiesta dati al servizio */
    //this.subscription = this.testService.getDati().subscribe(res => this.machineryData = res);  //* TEST con dati mockati
    this.subscription = this.mpService.getDati().subscribe(res => 
    {
      /*
      * Con Object.assign faccio a meno di usare l'operatore "=" che in javascript
      * assegna ad entrambi gli operandi lo stesso valore.
      * [] serve per specificare il tipo di ritorno, ovvero un array.
      */
      this.machineryData = Object.assign([], res); 

      //svuoto l'array idsMachinery e lo riempio con i nuovi dati
      this.mpService.popAll(this.idsMachinery);
      this.machineryData.forEach(element => this.idsMachinery.push(element.idMachinery));
    });    
  }


  ngOnDestroy(): void 
  {
    /**
     * Alla distruzione del componente smetti di effettuare richieste
     */
    this.subscription?.unsubscribe();
    
    //console.log('Componente Home distrutto');
  }
}
