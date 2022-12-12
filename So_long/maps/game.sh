#!/bin/bash

make -C ./ so_long

for i in {0..8}; do ./so_long ./maps/level$i.ber; done

