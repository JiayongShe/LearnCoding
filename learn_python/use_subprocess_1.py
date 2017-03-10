#!/usr/bin/env python
# -*- coding: utf-8; -*-

import subprocess
from subprocess import Popen
from subprocess import PIPE

s = Popen('ls -l', shell=True, stdout=PIPE)
print (s.communicate())

