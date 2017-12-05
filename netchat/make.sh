#!/usr/bin/env bash
# AUTHOR:   joker
# FILE:     make.sh
# ROLE:     auto build this project
# CREATED:  2017-12-04 14:27:06
# MODIFIED: 2017-12-05 11:05:28

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
