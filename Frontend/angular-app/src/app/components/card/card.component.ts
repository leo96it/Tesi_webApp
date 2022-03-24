import { Component, Input, OnInit } from '@angular/core';
import { ProductionDataModel } from "src/app/models/production-data.model";

@Component({
  selector: 'app-card',
  templateUrl: './card.component.html',
  styleUrls: ['./card.component.css']
})
export class CardComponent implements OnInit 
{

  @Input()
  machineData!: ProductionDataModel;

  constructor() { }

  ngOnInit(): void 
  { 
    //console.log(this.machineData);
  }
}
