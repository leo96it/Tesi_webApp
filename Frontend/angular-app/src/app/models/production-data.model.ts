/**
 * Per specificare il tipo dell'oggetto risposta, definire prima un'interfaccia 
 * con le proprietà richieste. Utilizzare un'interfaccia anziché una classe, 
 * perché la risposta è un oggetto semplice che non può essere convertito 
 * automaticamente in un'istanza di una classe.
 */


export interface ProductionDataModel
{
    id: number;
    idMachinery: string;
    idProduct: string;
    position: string;
    status: boolean;
    errorCode: number;
    createdAt: string;
    updatedAt: string;
}