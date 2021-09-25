FROM alpine:edge

RUN apk add --no-cache g++ sfml-dev \
&& mkdir -p /usr/src/Pong-plus-plus

WORKDIR /usr/src/Pong-plus-plus

COPY . .
RUN g++ -std=c++11 -c main.cpp \
&& g++ -o pong main.o -lsfml-window -lsfml-system -lsfml-audio -lsfml-graphics

