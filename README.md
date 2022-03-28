# Tesi_webApp

This project was made for the degree in computer engineering at Uninettuno.
It consist of a web server with a backend server, a mysql database and frontend web site. The server receive data from several hardware clients, based on ESP8266 or ESP32 microcontroller.

## Hardware - build with Arduino IDE v1.8.5 and KiCad v5

To run the hardware part, first you need to insert your wifi `SSID` and `password`, then you need to change the `serverURL` variable to match your local IP address.
Finally you can boot the firmware onto the ESP8266 devboard.
ATTENTION: the Arduino IDE require the download of card manager for ESP32 and ESP8266.

## Database - build with MySQL v8.0.28

Download MySQL with the MySQL installer (Windows) from:  https://dev.mysql.com/downloads/installer/.
Create the database called `ESP32_plant1` to match the variable `dbname` in config.json (backend).

## Server - build with NodeJS v14.17.5

Download all the module with `npm i` and start the MYSQL80 system variable. Then run `npm start`.

## Frontend - build with Angular CLI v13.0.3, NPM 6.14.14 and Grafana

First you need to set the Grafana dashboard, follow the PDF file `Elaborato finale - Barea Leonardo` in Extras folder, for the procedure and `query-Grafana` in Database folder for the query from Grafana to MySQL.
Run `ng serve` for a dev server. Navigate to `http://localhost:4200/`. The app will automatically reload if you change any of the source files.

