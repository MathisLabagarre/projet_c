# projet_c

Lancer la compilation avec :
à rajouter

gcc main.c tree/*.c -Wall -lcrypto

Au lancement :
Arguments obligatoires : 
-G [fichiertexte] pour la génération de condensats
OU
-L [fichiertexte] pour le chargement en mémoire des condensats (ne fais pas la différence entre condensats et chaines de caractères classiques)
par défaut, donne la main à l'utiliateur pour la recherche de condensat
OU
-GL [fichiertexte] pour générer les condensats et les charger directement en mémoire sans les écrire

Arguments optionnels :
Allant avec -G :
-h pour choisir l'algo de hachage 
-o pour le fichier de sortie (sinon hash.txt par défaut et écrase l'ancien si existant)

Allant avec -L:
-s pour chercher un condensat une fois chargé (ne redonne pas la main)