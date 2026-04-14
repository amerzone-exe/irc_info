
Client : Ce qui se connect au server et qui n'est pas un server. Son nickname fait 9 caracteres maximum. Le server doit connaitre : le vrai nom de l'host sur lequel le client est, l'username du client et le server sur  lequel le client est connecté.

Operator: Il peut connecté et deconnecté le server.
Il peut aussi :

| Commande | Parametre                                                            | Fonction                                                                                          | Autre                                                         |
| -------- | -------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------- | ------------------------------------------------------------- |
| KICK     | `<channel> <user> [<comment>]`                                       | Supprimer un user d'un channel                                                                    |                                                               |
| INVITE   | `<nickname> <channel>`                                               | inviter des utilisateurs à rejoindre un canal (si le mode invite only est activé dans le channel) | Il y a aucune obligation que le server existe ou soit valide. |
| TOPIC    | `<channel [<topic>]`                                                 | Afficher le topic du channel ou le changer si le parametre `[<topic>]` est rempli.                |                                                               |
| MODE     | `<channel> {[+\|-]\|i\|t\|k\|o\|l} [<limit>] [<user>] [<ban mask>] ` | Permettre a l'operator de changer les caracteristique de sont channel.                            |                                                               |

Option a implementer de la commande MODE:

*activer les options avec + et les enlever avec - *

- i: Permet de mettre le channel en mode inviter et donc de pouvoir utiliser la commande INVITE
- t: permet de mettre le changement de TOPIC possible uniquement en mode OPERATOR
- k: Permet de mettre un password pour un channel.
- o: Donner ou enlever les privilege d'OPERATOR a quelqu'un.
- l: Permet de fixer une limite d'utilisateur.

note:

- Le channel est ouvert a tous tant que le mode invite only n'est pas active.
De plus lorsque le channel n' est pas en invite only tous le monde peut inviter quelqu'un sur le channel.
- Lorsqu'un user rejoint un channel qui n'existe pas celui ci est automatiquement cree et le user devient un OPERATOR.
- Desactiver de base la possibilite d'envoyer un msg dans un channel qu'on a pas rejoint.
Autoriser seulement les messages prive entre les clients et pas  dún client a un server.

Commande client:

