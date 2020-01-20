# Partie 2: Compilation, debug et gestionnaire de signaux


## Exercice 1 : GDB et fichier core

**Question 1** : Que se passe-t-il au bout de quelques secondes? Qu'en
                 déduisez vous?

Au bout de quelques secondes, segmentation fault (core dumped). Il y a un problème d’accès mémoire quelque part dans le code.

**Question 2** : Quel signal a reçu le processus pour se terminer ainsi? Comment
                vérifiez vous le numéro du signal reçu?

Le signal que reçoit un processus dans le cas d’une erreur de segmentation est SIGSEGV. On le vérifie en récupérant la valeur de retour du binaire et en étudiant la liste des signaux :

$ echo $?
$ kill -l

**Question 3** : Grâce à GDB et au fichier *core* généré, analysez la source du
                 problème du binaire *gps*. Quelle partie du code est fausse?
                 Pourquoi?

 D’après GDB, on remarque que le bug provoquant l’erreur de segmentation se trouve dans la fonction knot_to_kmh_str()de la librairie libnmea.so.

 Le problème vient de "puts(NULL)", d'où un pointeur "NULL". C'est une erreur volontaire car présente seulement dans le cas où "GPS_OK" n’est pas définie.

**Question 4** : Que se passe-t-il quand vous lancez GDB en mode interactif sur
                 le binaire *gps*?

GDB indique qu’il n’arrive pas à exécuter car il lui manque la librairie "libptmx.so".

**Question 5** : À quoi sert la commande *ldd*? Quelle information
                supplémentaire cela vous apporte-t-il?

"ldd" liste les librairie partagées utilisées pour l'exécution. 
En plus de librairie libptmx.so, il manque aussi libnmea.so.

**Question 6** : Comment résoudre ce problème en tant qu'utilisateur? N'hésitez
                 pas à regarder le fichier *gps/run.sh*.

Il faut ajouter le path pour les librairies manquantes avec :

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib

**Question 7** : Quelle est la différence entre les commandes *s* et *n* dans
                 le prompt gdb suite à un breakpoint?

*s* et *n* correspondent à *step* et *next*. *step* continue jusqu'à la fin de la ligne de code, alors que *next* ne rentre pas dans les fonctions.

**Question 8** : Dans quel contexte ce type d'outils peut être intéressant?

Gdbserver est intéressant lors de débugage d’un exécutable sur un système embarqué. Il n'y a donc pas besoin de travailler avec GDB directement sur la carte.


## Exercice 2 : LD_PRELOAD et sigaction

**Question 1** : Implémentez dans le fichier hook.c la fonction à l'origine du
                 problème repéré au sein du simulateur GPS mais cette fois-çi
                 sans erreur.

OK

**Question 2** : Éditez le Makefile pour compiler *hook.c* sous la forme d'une
                 librairie partagée nommée *libhook.so* (s'inspirer de
                 *gps/src/lib/ptmx/Makefile*). Testez la compilation.

OK

**Question 3** : Éditez le fichier *run.sh* pour utiliser LD_PRELOAD au moment
                 de lancer le simulateur et ainsi hooker le binaire avec la
                 librairie libhook.so. Exécutez run.sh : le simulateur ne doit
                 plus partir en segfault.

OK

**Question 4** : Utilisez le *man* pour déterminer le prototype de la fonction
                 *printf* (expliquez comment vous utilisez *man* dans ce cas et
                 pourquoi). Comment est appelé ce type de fonction?

On veut *printf* de libc, avec *man man* section 3, on a les infos.
C'est une fonction variadique.

**Question 5** : Analysez *gps/src/bin/gps/gps.c* et repérez où se trouve le
                 gestionnaire de signaux. Décrivez les fonctions utilisez
                 ainsi que les signaux gérés.

Il se trouve dans le main. 
sigemptyset = initialise le signal à recevoir (ici *ctrl+C*)
signals_handler = ferme proprement le processus 

**Question 6** : Hookez le simulateur pour que ce dernier ne puisse plus
                 être interrompu par le signal SIGINT (Ctrl-C) en
                 réimplémentant la fonction *printf* dans libhook.so. Pour
                 cela, utilisez la fonction *sigaction* pour mettre en place
                 un gestionnaire de signaux au sein même de la fonction
                 *printf*  réimplémentée.

OK

**Question 7** : Comment faire pour interrompre le processus étant donné
                 que ce dernier ne répond plus au Ctrl-C? Citez deux méthodes.

On peut utiliser *ctrl+Z*, puis *ps* et *kill*
Sinon, on peut juste fermer le terminal

**Question 8** : En regardant le fichier *gps/Makefile*, que pouvez-vous dire
                 de la règle *ok*? À quoi sert-elle et comment
                 fonctionne-t-elle?

La règle *ok* sert à vérifier que tout soit bien compilé.
