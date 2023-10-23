#!/bin/bash

gn gen ./out
ninja -C ./out

export LD_LIBRARY_PATH=./out:$LD_LIBRARY_PATH
./out/hello
