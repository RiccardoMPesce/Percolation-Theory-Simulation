# Percolation Theory Simulation
Project for the class "Advanced Programming Languages"

## Come usare il progetto
Il progetto viene containerizzato per evitare problemi di compatibilità, pertanto è richiesto Docker per poterlo avviare. Se si vuole avviare la versione senza docker, passare al branch `executable_version`.

Nella directory principale, avviare il comando `docker-compose up --build` in una finestra terminale. Questo avvierà il progetto. 

Come si evince dal `Dockerfile` e da `docker-compose.yml`, il programma all'interno del container gira all'indirizzo 0.0.0.0 alla porta 5000, che attraverso `docker-compose.yml` viene mappata alla porta 5000 dell'host (il sistema operativo __sul__ quale gira Docker): in poche parole, l'indirizzo base è `0.0.0.0:5000`. 

### Documentazione API
Utilizzando `curl` od un web browser, digitare nella barra degli indirizzi `http://0.0.0.0/5000/simulation/simulate/{dimensione}/{numero_campioni}` (con curl, anteporre `curl` all'indirizzo), specificando la dimensione del lattice ed il numero di campioni. Verrà tornato un oggetto json contenente `threshold`, ossia la soglia di percolazione calcolata sul campione, `threshold_std`, ossia la deviazione standard del campione ed infine `results`, che sarebbe l'array di dimensione `dimensione` contenente i risultati delle `numero_campioni` simulazioni.
Utilizzando sempre `curl` od un browser, si può usare il comando `http://0.0.0.0/5000/simulation/simulate_custom_p/{soglia}/{dimensione}/{numero_campioni}` per simulare la proporzione di campioni che percola data una soglia scelta dall'utente.
