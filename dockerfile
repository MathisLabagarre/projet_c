FROM gcc:latest

WORKDIR /app

COPY ./main.c .

RUN sudo apt install libssl-dev

RUN gcc -Wall main.c -o main