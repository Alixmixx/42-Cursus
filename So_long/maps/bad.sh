#!/bin/bash

make -C ./ so_long

for i in {0..7}; do ./so_long ./maps/bad$i.ber; done
./so_long ./maps/bad8.be
