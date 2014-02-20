#!/bin/bash
i=1
for i in {1..30}
do
wget http://www.gktoday.in/gk/current-affairs-april-2012/page/$i/
mv index.html page_$i.html
done
