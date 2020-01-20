## Questions

En vous inspirant du contenu du répertoire *gps/*, répondre aux questions
suivantes:

**Question 1**: Qu'est ce qu'un Makefile? À quoi sert make?

Un makefile sert à faciliter la compilation en listant la liste des commandes à exécuter, un utilisateur n'a donc pas besoin de le faire étape par étape et a moins de risques de faire des erreurs. 

**Question 2**: Quel compilateur est utilisé ici?

Ici, GCC est utilisé.

**Question 3**: Qu'est ce qu'une librairie partagée?

Une bibliothèque partagée est une bibliothèque liée à un exécutable, elle est chargé uniquement à l'exécution. Elle peut être utilisée par plusieurs fichier exécutable en même temps. 

**Question 4**: Donnez un exemple de fichier C et la ligne de commande
                correspondante pour obtenir un binaire exécutable (un hello
                world par exemple).

$ gcc -Wall -o hello hello.c

**Question 5**: Donnez un exemple de fichier C et les lignes de commandes
                correspondantes pour obtenir une librairie partagée.

$ gcc -c -Wall -Werror -fpic helol.c  
$ gcc -shared -o libhelol.so helol.o  
$ gcc -L/home/philibert/Documents/ENSTA/embsys/labs/sysprog/ -Wall -o test main.c -lhelol  
$ LD_LIBRARY_PATH=/home/philibert/Documents/ENSTA/embsys/labs/sysprog/:$LD_LIBRARY_PATH  
$ export LD_LIBRARY_PATH=/home/philibert/Documents/ENSTA/embsys/labs/sysprog/:$LD_LIBRARY_PATH
