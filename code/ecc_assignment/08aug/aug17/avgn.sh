echo "Enter the no to be avg: "
read n
s=0
for((i=0;i<n;i++))
do
read a
s=$[a+s]
done
r=$[$[$[s%n]*10]/n]
s=$[s/n]
echo "AVG:"$s"."$r
