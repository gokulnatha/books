echo "Enter n: "
read n
s=0
for((i=0;i<n;i++))
do
read a
s=`expr $s + $a`
done
echo "Result: "$s

