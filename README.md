# Percolation Theory Simulation
Project for the class "Advanced Programming Languages"

## Come usare il progetto
Questa versione non richiede docker, ma richiede che venga avviato il comando `pip install requirements.txt` per installare le dipendenze. Se si vuole usare la versione con Docker, passare al branch `main`.

Nella directory principale, avviare il comando `python main.py` in una finestra terminale. Questo avvierà il progetto. 

Il programma girerà all'indirizzo `http://0.0.0.0/5000`. Se si vuole cambiare indirizzo e/o porta, modificare il file `main.py` nella root.

Il modulo wrapper è gia compilato, se si desidera ricompilarlo, eseguire `cd build && cmake .. && make` sempre dalla root directory del progetto.

### Documentazione API
Utilizzando `curl` od un web browser, digitare nella barra degli indirizzi `http://0.0.0.0/5000/simulation/simulate/{dimensione}/{numero_campioni}` (con curl, anteporre `curl` all'indirizzo), specificando la dimensione del lattice ed il numero di campioni. Verrà tornato un oggetto json contenente `threshold`, ossia la soglia di percolazione calcolata sul campione, `threshold_std`, ossia la deviazione standard del campione ed infine `results`, che sarebbe l'array di dimensione `dimensione` contenente i risultati delle `numero_campioni` simulazioni.
Utilizzando sempre `curl` od un browser, si può usare il comando `http://0.0.0.0/5000/simulation/simulate_custom_p/{soglia}/{dimensione}/{numero_campioni}` per simulare la proporzione di campioni che percola data una soglia scelta dall'utente.

### Cosa fare per aggiornare pybind
Avviare il seguente comando (CMake potrebbe fallire altrimenti) `git submodule update --init --recursive`.
