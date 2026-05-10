#!/bin/bash

sudo apt update

sudo apt install -y \
xorg xinit \
libx11-dev libxft-dev libxinerama-dev \
build-essential make gcc git \
picom feh x11-xserver-utils \
dmenu fonts-noto fonts-noto-color-emoji \
python3-pywal
