/**
 * Servizio per test senza backend, permette di utilizzare i dati presenti in "mock-data"
 * lasciando inalterata la struttura del codice.
 * * Per usarlo, serve commentare la relativa riga in monitoring.component.ts
 */


import { Injectable } from "@angular/core";
import { Observable, of } from "rxjs";
import { ProductionDataModel } from "../models/production-data.model";
import { DATA } from "./mock-data";



@Injectable()
export class servizioTest
{
    /** getDati(), ritorna un observable di tipo ProductionDataModel */
    getDati(): Observable<ProductionDataModel[]>  
    {
        console.log('Richiesta dati mock');
        return of(DATA); // ritorno i dati mockati 
    }
}