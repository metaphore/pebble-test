#!/usr/bin/env bash

pebble build

# Install to through the phone to a real watch.
#pebble install -v --phone 192.168.0.123

# Install to the emulator.
pebble install -v --emulator diorite

#pebble logs --color
