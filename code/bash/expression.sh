#!/bin/bash
x=(10 20)
y=30
z=`expr ${x[0]} + ${x[1]} + $y + 40`
echo $z
