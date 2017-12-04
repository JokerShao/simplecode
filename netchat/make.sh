#!/usr/bin/env bash
# AUTHOR:   joker
# FILE:     build.sh
# ROLE:     TODO (some explanation)
# CREATED:  2017-12-04 14:27:06
# MODIFIED: 2017-12-04 14:58:00

# build client
if [[ $1 = "clean" ]]; then
	cd client
	make clean
	rm netchat Makefile
	cd ../server
	make clean
	rm -rf build start
else
	cd client
	qmake-qt4
	make -j
	cd ../server
	mkdir build
	make
fi

