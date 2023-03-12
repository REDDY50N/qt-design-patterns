#!/bin/bash

OS=$(cat /etc/*-release | grep ^ID= | tr -d 'ID=')
PKG=doxygen
DOXYFILE=Doxyfile
OUTPUT=latex #pdf # html, pdf, rtf

if [ $OS == ubuntu ]; then
  if [ dpkg-query -l doxygen ]; then
    echo "The package $PKG is already installed!"
  else
    echo "Install $PKG package."
    sudo apt install $PKG
  fi
fi

if [ $OS == arch ]; then
  if pacman -Qs $PKG > /dev/null ; then
    echo "The package $PKG is already installed!"
  else
    echo "Install $PKG package."
    sudo pacman -Sy $PKG 
  fi
fi


if [ ! -f Doxyfile ]; then
  echo "Creating the config file: $DOXYFILE"
  doxygen -g $DOXYFILE
else
  echo "Build the documentation with $DOXYFILE"
  doxygen $DOXYFILE
  python3 -m webbrowser "doxygen/index.html"
fi

python3 -m webbrowser "doxygen/html/index.html"
