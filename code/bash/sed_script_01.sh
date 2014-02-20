#!/bin/bash

#remove first 2 characters of the file on each line; update on same file
sed -i 's/\(.\{1\}\)//' $1

