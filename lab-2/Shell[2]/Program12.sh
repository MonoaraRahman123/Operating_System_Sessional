a=3.5
b=2.2
result=$(echo "$a + $b" | bc -l)
echo "Sum: $result"
