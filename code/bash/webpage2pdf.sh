#!/bin/bash

for i in `ls $1`
do
wkhtmltopdf $i $1/pdfs/$i.pdf
done
