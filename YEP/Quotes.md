Notions vue dans le Indie Studio : 

* Mémoire :)  ` La mémoire c'est bien, il faut en prendre soin `


1) new & delete dans le main.cpp 

New & delete : c'est cool mais il faut pas oublier de delete sinon ça fait des leaks, et c'est pas cool. 

Ne pas oublier l'étoile sinon ça marche moins bien


2) Smart pointers

#include <memory>

Eux c'est vrailment des frères, il gère directement la mémoire pour toi implicitement donc vraiment, pas de soucis. On devrait toujours utiliser des smart pointers quand c'est possible pour éviter les surprises


a) Le fréro unique 

On peut en trouver un peux partout dans les classes, on l'initie avec un : std::make_unique<type>(args).
Et à partir de ce moment, ça va être impossible de le copier, ce qui implique donc, lors d'appel de fonction d'envoyer l'adresse.

EXEMPLE : my_function(std::unique_ptr<class> *e)

et tu l'appelles comme ça my_function(&uniqu_ptr)


b) Le fréro shared
C'est le même que unique sans la spécification d'unicité, en gros ça te casse moins la tête pour le passer à une fonction et l'allocation dynamique de mémoire est faite, genre il lachera quand il sera hors-scope

Pour ce qui est de la création, c'est grâce à std::make_shared<type>(args) 


3) Malheusement, on a du malloc..

Alors malloc, en c++ c'est a éviter bien sûr, je sais pas si tu te rappelles la tête de Gabriel quand il l'a découvert..
Mais c'était pas la joie, bref si on te met un couteau sous la gorge pour l'utiliser, free le.

C'est le même principe que New & Delete, mais en plus relou..

Sah à éviter



* Les containers, `Une force du cpp, in-jouable`

Liste / Vector  : On en trouve dans le gamecore.
#include <list> / <vector> / <map>

Ces trucs là, c'est vraiment fort, tu peux faire tout ce que tu veux avec, hésite pas à regarder les fonctions membre de chaques pour voir si tu as plutot besoin d'une liste ou d'un vector.
Mais a notre niveau, je pense que tu peux aller au pif ils font le taf.

gamecore 200 tu peux voir comment faire des boucles list / vector(en dessous)

Avec ça, tu peux tout faire, il faut juste arriver à penser la solution.

Map : 

Les maps sont composé de 2 types, <key><second>
Par exemple la liste de player a <int><unique_ptr<Player>>

Si tu vas gamecore 102 tu vas voir un for basique qui parcours une map.

On utilise les maps pour stocker des valeurs pairs unique, sinon ça crash.



* Exceptions, `L'art de throw comme il se doit`

exemple error.cpp


L'idée, c'est de créer des erreurs personalisée pour chaque grande partie du projet. ( cf Namespace)

Il faut créer une classe qui hérite directe de `std::exception`pour pouvoir le catch via try


<interlude Try>
Tu peux en voir dans le main.cpp
Alors c'est une mauvaise utilisation de try, c'est pas optimal, mais à notre niveau on accepte encore mais attention pour la suite.

L'idée de try c'est de catch les exceptions le plus tôt possible pour pouvoir agir en conséquence, mais ça c'est dans l'idéal.

Dans notre cas (Plazza/Arcade/Indi)
On fait des gros try et on gère que des exceptions ou on ne peut pas 'fix'. Du coup exceptions -> crash


* <TEMPLATE> 

voir controldata.hpp & menu.cpp l30

Alors le but de la template, c'est de créer une classe, qui se base sur un type, mais il ne faut pas le spécifier.

Ça doit marcher avec des int/string et j'en passe, pour tout.
C'est ça la force des templates, tu codes le truc 1x et tu peux l'utiliser autant que tu veux, dans n'importe quel contexte.

On met le type en majuscule par convention, ici T


* <Mutex>

Alors c'est assez simple et extrèmement utilse sur les projet ou on utilise plusieurs process en même temps.
Soit via des child process, où via du multithreading. (cc plazza)

C'est juste un cadena que tu met en place pour isoler une partie du code pour éviter de la run trop de fois, tu le lock juste avant, et puis tu le unlock ensuite.

C'est très utile par exemple quand tu as besoin de mettre a jour une variable ou soustraire une valeur etc..


* <Namespace>

cf Plazza

Alors le but de ce mot clé, c'est de séparer le code en morceau pour s'y retrouver. On peut donc avoir deux fonctions qui ont le même nom dans des namespaces différent.

Ça peut très bien se marier avec les exceptions du fait que ça sépare tout, des exceptions bien placé, ça peut être très fort.

Il faut juste pas oublier, de l'include (là ou en a besoin).
De la définir DANS le namespace, comme tu peux le voir dans kitchen.cpp

Et bien sur quand on appelle une fonction d'un namespace, on fait comme ça : <namespace>::fonction()

Sinon tu vas te prendre des undefined reference et tu vas pas comprendre


* <Const> && <Adresse>

C'est ultra important de faire ce check en fin de projet (si tu as pas l'habitude de coder tel quel). Car niveau performance, l'impact est énorme, surtout quand tu utilises des <containers>

Tout ce qui peut être const doit l'être, et après tu vérifies si tu peux envoyer l'adresse.
Dans les constructeurs, on envoie souvent const + adresse, tu peux en voir ici dans mon day09. On le fait rarement, sah il faudrait le faire +

# Character::Character(const std::string &name, int level) : 
#    Level(1), Health(100), Energy(100), Strength(5), Stamina(5), Intelligence(5), Spirit(5), Agility(5)
# {
#    Name = name;
#    Level = level;
#    Classe = "Character";
#    Race = "Human";
#    Range = Character::CLOSE;
#    
#    std::cout << name << " Created" << std::endl;
# }


* <Héritage>

# tu en trouveras day09 C++ pool

Ça c'est un gros morceau, et ça doit être dans ta tête quand tu fais ton architecture en <class>.

La classe fille héritera de tout les fields <protected>, mais pas des <private> donc fait bien attention lequel tu utilises et dans quel contexte.

On s'en sert aussi dans les exceptions, comme spécifié au dessus, mais c'est vraiment avec des <class_personalisée>




ELSE 

Oublie pas de mettre les fonctions dans le bon ordres lors des appels;

Utilise <this> dans les classes, seulement quand tu peux pas faire autrements, ça alourdi le code pour pas grand chose;

Si c'est pas le ., c'est la ->

Créer des types personnalisé quand c'est possible/utile (surtout quand tu taf sur une autre librairie)

Delete tout les commentaires/code mort avant la fin du projets

Essaye de return des <ENUM>
