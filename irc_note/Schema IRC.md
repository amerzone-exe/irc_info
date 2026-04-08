
SERVEUR IRC
│
├── Collection de Channels
│   │
│   ├── #general                    #channel1
│   │   ├── name: "#general"        name: "#dev"
│   │   ├── topic: "Chat général"   topic: "Développement"
│   │   ├── mode: "t" (topic)       mode: "k" (key)
│   │   ├── password: ""            password: "secret"
│   │   │                           │
│   │   └── members:                └── members:
│   │       ├── user1 (@op)         ├── user2 (@op) 
│   │       ├── user3               ├── user4
│   │       └── user5               └── user5
│   │
│   └── #random                     #help
        ├── name: "#random"
        ├── topic: ""

### Relation Client -> Channel

USER1 (nick="alice", fd=5)
├── channels: ["#general", "#dev"]
└── operator_of: ["#general"]

USER2 (nick="bob", fd=7)
├── channels: ["#dev"]
└── operator_of: ["#dev"]

USER5 (nick="charlie", fd=12)
├── channels: ["#general", "#dev", "#help"]
└── operator_of: []

### Logique des operations

JOIN #general
├── Channel "#general" existe ? 
│   ├── OUI → Ajouter user à members[]
│   └── NON → Créer channel + user1 = @op
├── Notifier tous les members: ":alice JOIN #general"
└── Ajouter "#general" à user.channels[]

PRIVMSG #general :salut
├── Vérifier user ∈ channel.members[]
├── Si OUI → Broadcast vers TOUS les members
└── Si NON → ERR_CANNOTSENDTOCHAN

PART #general
├── Retirer user de channel.members[]
├── Si channel.members[] vide → Supprimer channel
└── Notifier: ":alice PART #general"

### Etat a suivre

Channel states:
├── members_count > 0     → Channel actif
├── members_count = 0     → Supprimer channel  
├── first_member = @op    → Premier membre = opérateur
└── modes.active          → Appliquer règles d'accès
