import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { HistoricalComponent } from './components/historical/historical.component';
import { HomeComponent } from './components/home/home.component';
import { MonitoringComponent } from './components/monitoring/monitoring.component';

const ROUTES: Routes = 
[
  {
    path: '', pathMatch: 'full', redirectTo: 'home' //path url: localhost://4200
  },
  {
    path: 'home', //path url: localhost://4200/home
    component: HomeComponent
  },
  {
    path: 'monitoring', //path url: localhost://4200/monitoring
    component: MonitoringComponent
  },
  {
    path: 'historical', //path url: localhost://4200/historical
    component: HistoricalComponent
  }
];

@NgModule({
  imports: [RouterModule.forRoot(ROUTES)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
