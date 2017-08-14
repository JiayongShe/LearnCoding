#!/bin/env bash

repeat() { while :; do $@ && return; sleep 3; done }

#repeat ls -l
repeat date
