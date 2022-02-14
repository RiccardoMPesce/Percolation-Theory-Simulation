# Percolation Theory Simulation
Project for the class "Advanced Programming Languages"

## Come usare il progetto
Il progetto viene containerizzato per evitare problemi di compatibilità, pertanto è richiesto Docker per poterlo avviare.

Nella directory principale, avviare il comando `docker-compose up --build` in una finestra terminale. Questo avvierà il progetto. 

Come si evince dal `Dockerfile` e da `docker-compose.yml`, il programma all'interno del container gira all'indirizzo 0.0.0.0 alla porta 5000, che attraverso `docker-compose.yml` viene mappata alla porta 5000 dell'host (il sistema operativo __sul__ quale gira Docker): in poche parole, l'indirizzo base è `0.0.0.0:5000`. 


