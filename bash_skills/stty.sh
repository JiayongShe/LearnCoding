#!/usr/bin/env bash
echo -e "Enter password: "
stty -echo
read password
stty echo
echo
echo Password read.
echo $password
