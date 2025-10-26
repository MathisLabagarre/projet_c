FROM gcc:latest

RUN apt-get update && apt-get install -y libssl-dev && apt-get install -y make

WORKDIR /app

COPY ./main.c .
COPY ./tree .
COPY ./hash .
COPY ./file .
COPY ./storage .
COPY makefile .