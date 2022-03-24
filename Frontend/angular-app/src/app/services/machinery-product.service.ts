import { HttpClient, HttpHeaders } from "@angular/common/http";
import { Injectable, OnDestroy } from "@angular/core";
import { Observable, retry, share, Subject, switchMap, takeUntil, timer } from "rxjs";



@Injectable()
export class MachineryProductService implements OnDestroy
{
    private serverUrl: string = 'http://localhost:3000/produzione/monitora';
    private stopPolling = new Subject();
    
    constructor(private http: HttpClient) { }

    getDati(): Observable<any>
    {
        //Per ricevere testo devo aggiungere alla GET questi headers
        //const headers = new HttpHeaders().set('Content-Type', 'text/plain; charset=utf-8');

        /**  https://blog.angulartraining.com/how-to-do-polling-with-rxjs-and-angular-50d635574965 
         * timer(x, y): Funzione che permette di impostare un intervallo di x millisecondi 
         *              la prima volta e y millisecondi tra una richiesta e l'altra
         * switchMap: trasforma un input Observable in un altro Observable, nel nostro caso,
         *            trasformeremo ogni numero emesso dal timer in una richiesta HTTP al backend
         * retry(n): Risottoscrive su un errore n volte, se il campo è vuoto lo farà all'infinito
         * share(): Per default, gli Observables RxJs creano un nuovo task per ogni subscriber 
         *          mentre si verifica la subcription. Nel nostro caso, tre subscribers finirebbero
         *          per creare un'istanza del meccanismo di polling 3 volte, quindi 3 richieste HTTP.
         *          L'operatore share() assicura che ogni subscriber utilizzi lo stesso polling.
         * takeUntil(...): Per fermare un Observable stream mentre sta emettendo (es. componente distrutto)
         */
        return timer(1,1000).pipe(switchMap( () =>
        this.http.get(this.serverUrl) ),
        retry(1),
        share(),
        takeUntil(this.stopPolling));
    }


    //Metodo per svuotare un array
    popAll(array: any): void
    {
      while (array.pop() != undefined) { }
    } 
    

    //Metodo che permette di interrompere il polling HTTP alla distruzione del componente
    ngOnDestroy(): void 
    {
        this.stopPolling.next(void 0);
    }


    //Metodo che permette di interrompere il polling HTTP manualmente
    stopPollingFunction(): void
    {
        this.stopPolling.next(void 0);
    }
}