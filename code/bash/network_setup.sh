#!/bin/bash
/etc/init.d/networking restart
ping -c 3 google.com
