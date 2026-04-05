echo ""
echo "========= Question 4 ========="
echo -n "Enter a number to reverse: "
read num

rev=0

while [ $num -gt 0 ]
do
    digit=$((num % 10))
    rev=$((rev * 10 + digit))
    num=$((num / 10))
done

echo "Reversed Number: $rev"

#gedit 04_reverse.sh
#bash 04_reverse.sh