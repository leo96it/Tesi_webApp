/* PASS postazione 1 */
SELECT idProduct, COUNT(idProduct) as 'PASS'
FROM production
WHERE position = 'Station 1: User load / unload'
AND status = true
GROUP BY idProduct
ORDER BY idProduct ASC;

/* FAIL postazione 1 */
SELECT idProduct, COUNT(idProduct) as 'FAIL'
FROM production
WHERE position = 'Station 1: User load / unload'
AND status = false
GROUP BY idProduct
ORDER BY idProduct ASC;


/* PASS postazione 2 */
SELECT idProduct, COUNT(idProduct) as 'PASS'
FROM production
WHERE position = 'Station 2: CNC roughing'
AND status = true
GROUP BY idProduct
ORDER BY idProduct ASC;

/* FAIL postazione 2 */
SELECT idProduct, COUNT(idProduct) as 'FAIL'
FROM production
WHERE position = 'Station 2: CNC roughing'
AND status = false
GROUP BY idProduct
ORDER BY idProduct ASC;


/* PASS postazione 3 */
SELECT idProduct, COUNT(idProduct) as 'PASS'
FROM production
WHERE position = 'Station 3: Protective paint'
AND status = true
GROUP BY idProduct
ORDER BY idProduct ASC;

/* FAIL postazione 3 */
SELECT idProduct, COUNT(idProduct) as 'FAIL'
FROM production
WHERE position = 'Station 3: Protective paint'
AND status = false
GROUP BY idProduct
ORDER BY idProduct ASC;


/* PASS postazione 4 */
SELECT idProduct, COUNT(idProduct) as 'PASS'
FROM production
WHERE position = 'Station 4: Laser Labeling'
AND status = true
GROUP BY idProduct
ORDER BY idProduct ASC;

/* FAIL postazione 4 */
SELECT idProduct, COUNT(idProduct) as 'FAIL'
FROM production
WHERE position = 'Station 4: Laser Labeling'
AND status = false
GROUP BY idProduct
ORDER BY idProduct ASC;


/* Grafico temporale pezzi prodotti */
SELECT  STR_TO_DATE(createdAt, '%Y-%m-%d') AS 'time',
COUNT(id) AS 'Pezzi prodotti'
FROM production
WHERE status = true
AND position = 'Station 4: Laser Labeling'
GROUP BY time
ORDER BY time;


/* Grafico conteggio codici errore */
SELECT COUNT(errorCode), errorCode
FROM production
WHERE errorCode <> 0 
AND errorCode <> 200
GROUP BY errorCode
ORDER BY errorCode ASC;