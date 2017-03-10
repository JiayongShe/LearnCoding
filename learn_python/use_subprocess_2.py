#!/usr/bin/env python
# -*- coding: utf-8; -*-

import subprocess
from subprocess import Popen
from subprocess import PIPE

child1 = Popen(["ls", "-l"], stdout=PIPE)
child2 = Popen(["wc"], stdin=child1.stdout, stdout=PIPE)
out = child2.communicate()
print out

