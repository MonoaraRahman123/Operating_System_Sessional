filename="input.txt"
IFS=
while read -r line
do
	echo "Line: $line"
done < "$filename"
