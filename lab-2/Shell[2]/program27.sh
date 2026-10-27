if [ -f "$1" -a  -r "$1" ]; then
	echo "File exists and is readable"
fi

if [ -f "$1" -o -d "$1" ]; then
	echo "It is either a file or a directory"
fi
