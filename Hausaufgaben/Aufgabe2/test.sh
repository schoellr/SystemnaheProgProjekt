#!/bin/bash

source test-env

find $@ > find.txt 2>&1
./find $@ > me.txt 2>&1
diff find.txt me.txt

#meld find.txt me.txt
