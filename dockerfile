FROM gcc:latest

RUN sudo apt install libssl-dev

WORKDIR /app

COPY ./main.c .
COPY ./tree .
COPY ./hash .
COPY ./file .
COPY ./storage .
COPY makefile .

RUN make