add(){
	local sum=$(($1 + $2))
	echo $sum
}

result=$(add 5 3)
echo "The sum is $result"
