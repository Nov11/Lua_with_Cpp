#!/bin/bash

g++ main.cpp -llua5.2 -ldl -I/usr/include/lua5.2
./a.out
