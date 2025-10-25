FROM gcc:latest

WORKDIR /app

COPY ./main.c .

RUN gcc -Wall main.c -o main