echo "Enter nos to be arranged: "
read n
for((i=0;i<n;i++))
do
read a[i]
done
for((i=0;i<n;i++))
do
for((j=0;j<i;j++))
do
if [ $[a[i]] -lt $[a[j]] ]
then
s=$[a[i]]
a[i]=$[a[j]]
a[j]=$s
fi
done
done
echo "Sorted as ascending: "
for((i=0;i<n;i++))
do
echo $[a[i]]
done
