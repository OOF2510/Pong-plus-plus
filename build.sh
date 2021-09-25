#!/usr/bin/env bash

g++ -std=c++11 -c main.cpp
g++ -o pong main.o -lsfml-window -lsfml-audio -lsfml-system -lsfml-graphics
