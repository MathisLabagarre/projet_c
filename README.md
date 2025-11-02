# projet_c

Lancer la compilation avec depuis le dossier où se situent main.c et le dockerfile:
docker build -t projet .
docker run --rm -v ./:/app projet make

Au lancement :
Arguments obligatoires : 
-G [fichiertexte] pour la génération de condensats
OU
-L [fichiertexte] pour le chargement en mémoire des condensats (ne fais pas la différence entre condensats et chaines de caractères classiques)
par défaut, donne la main à l'utiliateur pour la recherche de condensat

Arguments optionnels :
Allant avec -G :
-h pour choisir l'algo de hachage 
-o pour le fichier de sortie (sinon hash.txt par défaut et écrase l'ancien si existant)

Allant avec -L:


Sans -H l'algo par défaut est sha256