# projet_c

Lancer la compilation avec :
Sous windows :
docker build -t oui .\
docker run --rm -v ".\:/app" dockerfile
docker run --rm -v ".\:/app" oui cp main .\
docker run --rm -v .\:/app -w /app gcc:latest gcc -Wall main.c -o main

Sous linux :
docker build -t compil_image_c .
docker run --rm -v $(pwd):/app compil_image_c
docker run --rm -v .\:/app myapp cp /app/main .