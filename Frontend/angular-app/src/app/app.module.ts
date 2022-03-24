import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from "@angular/common/http";
import { FormsModule } from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { MenuComponent } from './components/menu/menu.component';
import { CardComponent } from './components/card/card.component';
import { HistoricalComponent } from './components/historical/historical.component';
import { HomeComponent } from './components/home/home.component';
import { MonitoringComponent } from './components/monitoring/monitoring.component';
import { servizioTest } from './tests/test-service.service';
import { MachineryProductService } from './services/machinery-product.service';

@NgModule({
  declarations: [
    AppComponent,
    MenuComponent,
    CardComponent,
    HistoricalComponent,
    HomeComponent,
    MonitoringComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    FormsModule
  ],
  providers: [servizioTest, MachineryProductService],
  bootstrap: [AppComponent]
})
export class AppModule { }
