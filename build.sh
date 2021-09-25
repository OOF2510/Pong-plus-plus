#!/usr/bin/env bash

mkdir -p build
cd build
g++ -std=c++11 -c ../main.cpp
g++ -o pong main.o -lsfml-window -lsfml-audio -lsfml-system -lsfml-graphics
mkdir -p ../dist
zip -9 -r ../dist/pong-plus-plus.zip pong ../data/ ../assets/