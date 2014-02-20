echo "Enter a: "
read a
echo "Enter b: "
read b
if [ $a -lt $b ]; then
echo "a is smaller"
echo "b is greater"
else
echo "a is greater"
echo "b is smaller"
fi

