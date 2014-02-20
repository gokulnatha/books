#!/bin/bash
#cache_proc_script
cp $(file /proc/*/fd/* 2>/dev/null | grep Flash | cut -f1 -d:) /home/stalinsrinivasan/chefidel/buffer/cache_proc/.
