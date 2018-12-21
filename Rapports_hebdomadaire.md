 ## Rapport de projet :

## `Semaine 1 	(07 / 12 / 2018) :`

Lors de cette première séance nous avons commencé à faire les premiers choix techniques pour notre projet.
Au début pour équilibrer notre plaque nous voulions utiliser un accéléromètre afin de savoir comment est notre plaque pour faire en sorte de la redressé. En lisant l’exxxxxxxxcellent cours de M. Masson nous avons compris que ce choix n’était pas le meilleur car nous avons trouvé beaucoup plus simple et pratique : Un écran résistif. Cet écran permet de savoir où se trouve la balle grâce à la pression que celle-ci créée sur l’écran. L’écran renvoie la position en x et en y de la balle.
![Image de l'écran](https://raw.githubusercontent.com/YassineWaldane/Arduino/master/%C3%A9cran.jpg)
Cet écran 4 fils (VDD, Ground, position x, position y).

Après ce choix, nous avons dû choisir entre un écran de 8’’ et un écran de 17’’. Dans les deux cas nous avons trouvé des projets similaires au notre.
Or pour l’écran 17’’ il y avait une précision beaucoup plus simple que sur celui de 8’’. Nous avons donc opté pour l’écran 8’’ pour être plus précis.
Nous avons fini la séance en nous demandant quel type de moteurs allons-nous utiliser (pas à pas ou servo).

## `Semaine 2 	(14 / 12 / 2018) :`

Cette semaine nous avons choisit les moteurs que nous utiliserons. Nous avons dû choisir entre des moteurs pas à pas et des servomoteurs.
Dans le projet qui nous sert de guide, les moteurs choisit étaient des pas à pas avec des encodeurs afin de gérer les erreurs des moteurs (pertes de pas, …). Nous avons vu qu’avec des servomoteurs gérés en microsecondes nous n’aurons aucun de ces problèmes avec en prime une meilleure précision.

Nous avons aussi distribué les tâches : 

-	Liste de matériel et distribution des tâches -> à deux
-	Écran résistif -> Yassine
-	PID -> Baptiste RIP
-	Servomoteurs -> Yassine
-	Maquette –> à deux

J'ai aussi commencé a créé la maquette de notre projet sur Inventor.

# Semaine 3 (21 / 12 /2018):

Cette semaine j'ai créé des chassis sur inventor qui auraient étaient pour l'un un hexagone avec des emplacements pour les 3 moteurs (que j'ai modélisé avec des cylidres avec des barres) et un support pour l'écran.

![Image du 1er chassis](https://github.com/YassineWaldane/Arduino/blob/master/Croquis%204.png)

Puis j'ai changé je support recangulaire en support triangulaire avec des creux pour pouvoir faire une articulations du mecanisme.

![Image du 2nd chassis](https://github.com/YassineWaldane/Arduino/blob/master/Croquis%206.png)

MAIS avec Baptiste nous avons pas mal discuté sur le fait d'utiliser trois moteurs. surtout par rapport aux calculs d'angles que l'on devra faire avec le PID, etc... car on n'a besoin que de bouger que selon deux axes donc l'usage de trois moteurs nous compliquerait la tâche au niveau du code.
Nous avons donc opté pour l'usage de deux moteurs car c'est plus adapté à nos besoins et surtout plus à notre portée.

J'ai donc du refaire un autre support

