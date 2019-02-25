#!/bin/zsh
commentHeader() {
	file=$1
		comm=\#include\ $2
		sed -i '' "s|$comm|\/\/$comm|" $file
# echo commenting $header
}
uncommentHeader() {
	file=$1
		sed -i '' "/#include/s|\/\/||g" $file
# echo commenting out $header
}
for file in `ls **/**/**.c`
					do
					echo "\033[1;34m===>    SCANNING FILE:    $file\033[0m"
					for header in `grep "^[ \t]*#include" $file | awk '{print $2;}'`
					do
#echo Matched header $header
touch $file # update file's modification date to trigger MAKEFILE'S RECOMPILATION
commentHeader $file $header
make 1>/dev/null 2> MAKE_log
if [ -s MAKE_log ]
then
echo "\033[1;32m> Header needed: $header\033[0m"
else
echo "\033[1;31m> ERROR! UNUSED HEADER: $header\033[0m"
cat MAKE_log
fi
uncommentHeader $file
done
done
