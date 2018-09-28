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
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_push_back"
if [ -f j11/ex01/$FILE.c ] && [ -f j11/ex01/ft_list.h ]
then
	gcc -o z.out j11/ex01/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_push_front"
if [ -f j11/ex02/$FILE.c ] && [ -f j11/ex02/ft_list.h ]
then
	gcc -o z.out j11/ex02/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_size"
if [ -f j11/ex03/$FILE.c ] && [ -f j11/ex03/ft_list.h ]
then
	gcc -o z.out j11/ex03/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_last"
if [ -f j11/ex04/$FILE.c ] && [ -f j11/ex04/ft_list.h ]
then
	gcc -o z.out j11/ex04/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_push_params"
if [ -f j11/ex05/$FILE.c ] && [ -f j11/ex05/ft_list.h ]
then
	gcc -o z.out j11/ex05/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out hello good bye || errorExit "Error: $FILE with 'hello', 'good' and 'bye' as args failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_clear"
if [ -f j11/ex06/$FILE.c ] && [ -f j11/ex06/ft_list.h ]
then
	gcc -o z.out j11/ex06/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_at"
if [ -f j11/ex07/$FILE.c ] && [ -f j11/ex07/ft_list.h ]
then
	gcc -o z.out j11/ex07/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_reverse"
if [ -f j11/ex08/$FILE.c ] && [ -f j11/ex08/ft_list.h ]
then
	gcc -o z.out j11/ex08/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_foreach"
if [ -f j11/ex09/$FILE.c ] && [ -f j11/ex09/ft_list.h ]
then
	gcc -o z.out j11/ex09/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_foreach_if"
if [ -f j11/ex10/$FILE.c ] && [ -f j11/ex10/ft_list.h ]
then
	gcc -o z.out j11/ex10/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_find"
if [ -f j11/ex11/$FILE.c ] && [ -f j11/ex11/ft_list.h ]
then
	gcc -o z.out j11/ex11/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_remove_if"
if [ -f j11/ex12/$FILE.c ] && [ -f j11/ex12/ft_list.h ]
then
	gcc -o z.out j11/ex12/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_merge"
if [ -f j11/ex13/$FILE.c ] && [ -f j11/ex13/ft_list.h ]
then
	gcc -o z.out j11/ex13/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_sort"
if [ -f j11/ex14/$FILE.c ] && [ -f j11/ex14/ft_list.h ]
then
	gcc -o z.out j11/ex14/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_list_reverse_fun"
if [ -f j11/ex15/$FILE.c ] && [ -f j11/ex15/ft_list.h ]
then
	gcc -o z.out j11/ex15/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_sorted_list_insert"
if [ -f j11/ex16/$FILE.c ] && [ -f j11/ex16/ft_list.h ]
then
	gcc -o z.out j11/ex16/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
FILE="ft_sorted_list_merge"
if [ -f j11/ex17/$FILE.c ] && [ -f j11/ex17/ft_list.h ]
then
	gcc -o z.out j11/ex17/$FILE.c $FILE.test.c ft_create_elem.c || errorExit "Error: compilation $FILE failed";
	./z.out || errorExit "Error: $FILE failed";
	let "n = n + 1"
fi
rm z.out
echo "resultat = $n"
