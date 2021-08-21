#!/bin/sh
mv main.cpp $1.cpp
git commit -m "Solve acmicpc.net $1 '$2'"
cp template.cpp main.cpp