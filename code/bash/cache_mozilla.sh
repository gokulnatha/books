#!/bin/bash
#mozilla cache script
CACHE=~/.mozilla/firefox/lb4s81wm.default/Cache
OUTPUTDIR=~/chefidel/buffer/cache/
MINFILESIZE=2M

for f in `find $CACHE -size +$MINFILESIZE`
do
    cp "$f" "$OUTPUTDIR/$o"
done
