gcc -g -c -Wall -o ./tableau ./tableau.c
gcc -g -c -Wall -o ./inputhandler ./inputhandler.c
ar -rc ./util ./inputhandler ./tableau

gcc -g -Wall -o ./main ./main.c ./util

