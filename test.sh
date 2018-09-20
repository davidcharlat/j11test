errorExit()
{
  echo "$1";
  exit 1;
}

USER_BUILD=$1;

# BUILD
let "n = 0"
FILE="ft_create_elem"
if [ -f j11/ex00/$FILE.c ] && [ -f j11/ex00/ft_list.h ]
then
	gcc -o z.out j11/ex00/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi

rm z.out
exit 0;
	
	
	
	OUTPUT="`./z.out`";
	if [ "$OUTPUT" != "AAAAAA" ]
	then
		echo "error: expected 'AAAAAA' and received '$OUTPUT'"
	else
		let "n = n + 1"
		echo "ex01:  expected 'AAAAAA' and received '$OUTPUT'  : $FILE OK"
	fi
fi
FILE="ft_map"
if [ -f j10/ex02/*.c ]
then
	gcc -o z.out j10/ex02/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi
FILE="ft_any"
if [ -f j10/ex03/*.c ]
then
	gcc -o z.out j10/ex03/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi
FILE="ft_count_if"
if [ -f j10/ex04/*.c ]
then
	gcc -o z.out j10/ex04/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi
FILE="ft_is_sort"
if [ -f j10/ex05/*.c ]
then
	gcc -o z.out j10/ex05/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi
if [ -f j10/ex06/Makefile ]
then
	cd j10/ex06
	make -s all || errorExit "Error: compilation failed"
	if [ -f do-op ]
	then
		echo "do-op must return nothing if the number of arg is incorrect"
		OUTPUT="`./do-op`";
		if [ "$OUTPUT" != "" ]
		then
			errorExit "error: expected nothing and received '$OUTPUT'"
		fi
		OUTPUT="`./do-op 4 - 5 kl`";
		if [ "$OUTPUT" != "" ]
		then
			errorExit "error: expected nothing and received '$OUTPUT'"
		fi
		echo "OK"
		echo "testing '+', '-', '*', '/' and '%'"
		OUTPUT="`./do-op 4 + 79`";
		if [ "$OUTPUT" != "83" ]
		then
			errorExit "error:  4 + 79 expected 83 and received '$OUTPUT'"
		fi
		OUTPUT="`./do-op 4 - 79`";
		if [ "$OUTPUT" != "-75" ]
		then
			errorExit "error:  4 - 79 expected -75 and received '$OUTPUT'"
		fi
		OUTPUT="`./do-op 4 '*' 5`";
		if [ "$OUTPUT" != "20" ]
		then
			errorExit "error:  4 '*' 5 expected 20 and received '$OUTPUT'"
		fi
		OUTPUT="`./do-op 14 '/' 5`";
		if [ "$OUTPUT" != "2" ]
		then
			errorExit "error:  14 '/' 5 expected 2 and received '$OUTPUT'"
		fi
		OUTPUT="`./do-op 14 '%' 5`";
		if [ "$OUTPUT" != "4" ]
		then
			errorExit "error:  14 '%' 5 expected 4 and received '$OUTPUT'"
		fi
		echo "OK"
		echo "testing negative numbers"
		OUTPUT="`./do-op -14 '-' -5`";
		if [ "$OUTPUT" != "-9" ]
		then
			errorExit "error:  -14 '-' -5 expected -9 and received '$OUTPUT'"
		fi
		echo "OK"
		echo "testing incorrect operator"
		OUTPUT="`./do-op -14 '-5' -5`";
		if [ "$OUTPUT" != "0" ]
		then
			errorExit "error:  since operator was '-5', 0 was expected and '$OUTPUT' has been received"
		fi
		echo "OK"
		echo "testing letters in num values"
		OUTPUT="`./do-op 1toto + 5titi`";
		if [ "$OUTPUT" != "6" ]
		then
			errorExit "error:  1toto + 5titi expected 6 and received '$OUTPUT'"
		fi
		OUTPUT="`./do-op f1toto + -5titi`";
		if [ "$OUTPUT" != "-5" ]
		then
			errorExit "error:  f1toto + -5titi expected -5 and received '$OUTPUT'"
		fi
		echo "OK"
		echo "testing division and modulo by 0"
		OUTPUT="`./do-op 10 / 0`";
		if [ "$OUTPUT" != "stop : division by zero" ]
		then
			errorExit "error:  10 / 0 expected 'stop : division by zero' and received '$OUTPUT'"
		fi
		OUTPUT="`./do-op 10 % 0`";
		if [ "$OUTPUT" != "stop : modulo by zero" ]
		then
			errorExit "error:  10 % 0 expected 'stop : modulo by zero' and received '$OUTPUT'"
		fi
		echo "OK"
		echo "prgm do-op OK"
		let "n = n + 1"
	else
		errorExit "Error: do-op not created";
	fi
	make -s clean || errorExit "Error: failed to make clean"
	rm do-op
	cd ../..
	echo "Makefile and ex06 OK"
fi
FILE="ft_sort_wordtab"
if [ -f j10/ex07/*.c ]
then
	gcc -o z.out j10/ex07/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi
FILE="ft_advanced_sort_wordtab"
if [ -f j10/ex08/*.c ]
then
	gcc -o z.out j10/ex08/$FILE.c $FILE.test.c || errorExit "Error: compilation $FILE failed";
	./z.out
	let "n = n + 1"
fi
if [ -f j10/ex09/Makefile ]
then
	echo "testing ft_advanced_do-op"
	cd j10/ex09
	make -s all || errorExit "Error: compilation failed"
	if [ -f ft_advanced_do-op ]
	then
		echo "ft_advanced_do-op must return nothing if the number of arg is incorrect"
		OUTPUT="`./ft_advanced_do-op`";
		if [ "$OUTPUT" != "" ]
		then
			errorExit "error: expected nothing and received '$OUTPUT'"
		fi
		OUTPUT="`./ft_advanced_do-op 4 - 5 kl`";
		if [ "$OUTPUT" != "" ]
		then
			errorExit "error: expected nothing and received '$OUTPUT'"
		fi
		echo "OK"
		echo "testing '+', '-', '*', '/' and '%'"
		OUTPUT="`./ft_advanced_do-op 4 + 79`";
		if [ "$OUTPUT" != "83" ]
		then
			errorExit "error:  4 + 79 expected 83 and received '$OUTPUT'"
		fi
		OUTPUT="`./ft_advanced_do-op 4 - 79`";
		if [ "$OUTPUT" != "-75" ]
		then
			errorExit "error:  4 - 79 expected -75 and received '$OUTPUT'"
		fi
		OUTPUT="`./ft_advanced_do-op 4 '*' 5`";
		if [ "$OUTPUT" != "20" ]
		then
			errorExit "error:  4 '*' 5 expected 20 and received '$OUTPUT'"
		fi
		OUTPUT="`./ft_advanced_do-op 14 '/' 5`";
		if [ "$OUTPUT" != "2" ]
		then
			errorExit "error:  14 '/' 5 expected 2 and received '$OUTPUT'"
		fi
		OUTPUT="`./ft_advanced_do-op 14 '%' 5`";
		if [ "$OUTPUT" != "4" ]
		then
			errorExit "error:  14 '%' 5 expected 4 and received '$OUTPUT'"
		fi
		echo "OK"
		echo "testing negative numbers"
		OUTPUT="`./ft_advanced_do-op -14 '-' -5`";
		if [ "$OUTPUT" != "-9" ]
		then
			errorExit "error:  -14 '-' -5 expected -9 and received '$OUTPUT'"
		fi
		echo "OK"
		echo "incorrect operator: ft_usage must write 'error : only [ - + * / % ] are accepted.'"
		OUTPUT="`./ft_advanced_do-op -14 'p' -5`";
		if [ "$OUTPUT" != "error : only [ - + * / % ] are accepted." ]
		then
			errorExit "error:  since operator was 'p', '$OUTPUT' has been received"
		fi
		echo "tested with 'p' as operator"
		OUTPUT="`./ft_advanced_do-op -14 'ty' -5`";
		if [ "$OUTPUT" != "error : only [ - + * / % ] are accepted." ]
		then
			errorExit "error:  since operator was 'ty', '$OUTPUT' has been received"
		fi
		echo "tested with 'ty' as operator"
		OUTPUT="`./ft_advanced_do-op -14 '-5' -5`";
		if [ "$OUTPUT" != "error : only [ - + * / % ] are accepted." ]
		then
			errorExit "error:  since operator was '-5', '$OUTPUT' has been received"
		fi
		echo "tested with '-5' as operator"
		echo "OK"
		echo "testing letters in num values"
		OUTPUT="`./ft_advanced_do-op 1toto + 5titi`";
		if [ "$OUTPUT" != "6" ]
		then
			errorExit "error:  1toto + 5titi expected 6 and received '$OUTPUT'"
		fi
		OUTPUT="`./ft_advanced_do-op f1toto + -5titi`";
		if [ "$OUTPUT" != "-5" ]
		then
			errorExit "error:  f1toto + -5titi expected -5 and received '$OUTPUT'"
		fi
		echo "OK"
		echo "testing division and modulo by 0"
		OUTPUT="`./ft_advanced_do-op 10 / 0`";
		if [ "$OUTPUT" != "stop : division by zero" ]
		then
			errorExit "error:  10 / 0 expected 'stop : division by zero' and received '$OUTPUT'"
		fi
		OUTPUT="`./ft_advanced_do-op 10 % 0`";
		if [ "$OUTPUT" != "stop : modulo by zero" ]
		then
			errorExit "error:  10 % 0 expected 'stop : modulo by zero' and received '$OUTPUT'"
		fi
		echo "OK"
		echo "prgm ft_ultimate_do-op OK"
		let "n = n + 1"
	else
		errorExit "Error: ft_advanced_do-op not created";
	fi
	make -s clean || errorExit "Error: failed to make clean"
	make -s fclean
	cd ../..
	echo "Makefile and ex09 OK"
fi
rm ./z.out
echo "resultat = $n"
