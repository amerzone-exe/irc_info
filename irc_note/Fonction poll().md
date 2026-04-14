
Note :




### Explication

poll() va prendre une liste de fd (en l'occurence des sockets) en parametre et va les surveiller et va bloquer tant qu'au moins un socket est quelque choses a faire, par exemple des donnés a lire.

## Ce qu'on lui passe

On lui donne un tableau de `struct poolfd`, Chaques elements va contenir:

- `fd`: le numero de la socket.
-  `events` : ce que tu veux surveiller, par exemple POLLIN "je veux savoir si je peux lire".
-  `revents` : rempli par poll() pour dire ce qui s'est reellement passé.

## Comment ça marche

1. Tu crées une socket.
    
2. Tu mets cette socket dans un tableau `pollfd`.
    
3. Tu appelles `poll()`.
    
4. `poll()` attend.
    
5. Dès qu’un événement arrive, il remplit `revents`.
    
6. Tu regardes quelles sockets sont prêtes et tu lis avec `recv()` ou `read()`.
    

## Exemple mental

Tu as 3 clients :

- client A n’envoie rien.
    
- client B envoie un message.
    
- client C est déconnecté.
    

`poll()` va se réveiller et te dire :

- B a `POLLIN` → tu peux lire.
    
- C a peut-être `POLLHUP` → la connexion est fermée.
    
- A n’a rien → tu l’ignores pour l’instant.[](https://manpages.ubuntu.com/manpages/jammy/fr/man2/poll.2.html)
    

## Pourquoi c’est utile

Sans `poll()`, ton serveur ferait souvent :

- soit il bloque sur un seul client,
    
- soit il utilise un thread par client.
    

Avec `poll()`, un seul thread peut gérer plusieurs clients en regardant qui est prêt, sans tourner en boucle inutilement.

## Les événements importants

- `POLLIN` : il y a des données à lire.
    
- `POLLHUP` : l’autre côté a fermé la connexion.
    
- `POLLERR` : il y a une erreur sur la socket.