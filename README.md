# Opdracht: simuleer op een Nucleo onderstaande case

## Vereisten:

* Werk volgens OOP

* Gebruik de aangeleerde zaken binnen deze cursus

* Alles wat gelijktijdig zou moeten kunnen gebeuren moet zo geprogrammeerd worden

## Case:

Bijna alle betalingen die mensen vandaag de dag in een winkel uitvoeren worden betaald aan een betaalterminal.

Voor deze casus maken we een aantal vereenvoudigingen, zo zullen er 3 servers zijn van de terminaleigenaar en elk van deze servers kan 2 connecties tegelijk onderhouden. Verder zullen we 3 terminals verbinden per server van de terminaleigenaar. De servers van de terminaleigenaars staan allen in verbinding met de servers van de banken in België. Voor deze casus werken we met 2 banken, Belfius en KBC, elk met 1 server. Deze servers kunnen elk 2 gelijktijdige connecties aan met terminalservers.

De betaling aan een terminal gebeurt als volgt: De verkoper tikt het benodigde bedrag in op de terminal en vervolgens tikt de consument zijn code in om de betaling goed te keuren (we houden in deze casus geen rekening met mensen die hun code niet weten). De betaalterminal stuurt alle noodzakelijke details (account opdrachtgever, account ontvanger, bedrag) door naar een server van de terminaleigenaar (Visa). Deze server stuurt de informatie door naar de juiste bank en deze bank zal bekijken of de opdrachtgever voldoende heeft staan op zijn/haar rekening. Tijdens dit proces blijft de betaalterminal volgende melding geven: “Betaling controleren”. Na de controle van de bank zal de transactie al dan niet verwerkt worden en zal deze ook nota geven van het al dan niet doorlaten van de transactie aan de server van de terminaleigenaar. Deze server zal de boodschap doorsturen naar de betaalterminal.

De effectieve verwerking van de betalingen dienen verder in detail te worden besproken. Indien het gaat over een betaling tussen opdrachtgever en ontvanger die beide bij dezelfde bank een account hebben, dan zal de verwerking onmiddellijk uitgevoerd worden. Indien het gaat over een interbancaire transactie dan wordt deze transactie bewaard tot op een minder druk moment. Wanneer het een minder druk moment is zullen alle interbancaire transacties uitgevoerd worden tussen de twee banken. Tijdens deze batch zal het LED lampje branden om te duiden dat beide servers volop in communicatie treden.

Voor een goede simulatie dienen we rekening te houden met het tijdstip van de dag. We simuleren een volledige dag van 24u op 5 minuten. Dit wordt bijgehouden door een aparte timerthread die ten allen tijde correct dient te staan. Tussen 7u en 20u vallen het grootste deel van de transacties, buiten deze uren vallen er nog enkele transacties maar veel minder frequent (1/50 tov. de uren overdag).

Belangrijk: zorg dat er geen foutieve transacties doorgaan. 
