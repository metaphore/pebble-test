#!/usr/bin/env bash

pebble build

# Install to through the phone to a real watch.
#export PEBBLE_PHONE=192.168.0.50
#pebble install -v

# Install to the emulator.
pebble install -v --emulator diorite

#pebble logs --color