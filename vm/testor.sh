#dir=../fxtest/tests
dir=./test_erreurs

rm $dir/*.cor
for file in $dir/*.s;
do
	echo "==> $file <=="
	valgrind ./asm $file 2>> eee
	echo ""
	echo ""
done
