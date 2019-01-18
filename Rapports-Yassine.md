 ## Rapport de projet :

## `Semaine 1 	(07 / 12 / 2018) :`

Lors de cette première séance nous avons commencé à faire les premiers choix techniques pour notre projet.
Au début pour équilibrer notre plaque nous voulions utiliser un accéléromètre afin de savoir comment est notre plaque pour faire en sorte de la redressé. En lisant l’exxxxxxxxcellent cours de M. Masson nous avons compris que ce choix n’était pas le meilleur car nous avons trouvé beaucoup plus simple et pratique : Un écran résistif. Cet écran permet de savoir où se trouve la balle grâce à la pression que celle-ci créée sur l’écran. L’écran renvoie la position en x et en y de la balle.
![Image de l'écran](https://raw.githubusercontent.com/YassineWaldane/Arduino/master/images/%C3%A9cran.jpg)
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

# `Semaine 3 (21 / 12 /2018):`

Cette semaine j'ai créé des chassis sur inventor qui auraient étaient pour l'un un hexagone avec des emplacements pour les 3 moteurs (que j'ai modélisé avec des cylidres avec des barres) et un support pour l'écran.

![Image du 1er chassis](https://github.com/YassineWaldane/Arduino/blob/master/images/Croquis%204.png)

En réléchissant un peu j'ai changé de support car le support rectangulaire ne permettait pas de placer d'axe pour les rotations.
J'ai donc opté pour un support triangulaire avec des trous pour y faire passer des axes qui permettront le balançement de l'écran.

![Image du 2nd chassis](https://github.com/YassineWaldane/Arduino/blob/master/images/Croquis%206.png)

## MAIS

Avec Baptiste nous avons pas mal discuté sur le fait d'utiliser trois moteurs. surtout par rapport aux calculs d'angles que l'on devra faire avec le PID, etc... car on n'a besoin que de bouger que selon deux axes donc l'usage de trois moteurs nous compliquerait la tâche au niveau du code.
Nous avons donc opté pour l'usage de deux moteurs car c'est plus adapté à nos besoins et surtout plus à notre portée.

J'ai donc du refaire un autre support où, cette fois ci il y a deux points pour faire bouger la balle ( en x et en y , et une rotule au centre du support qui maintiendra le tout ).

![Image du dernier support](https://github.com/YassineWaldane/Arduino/blob/master/images/Croquis%207.png)

# `Semaine 4 (11 / 01 /2019):`

Aujourd'hui j'ai donc commencé la création de notre première maquette.
Pour cela je suis aller au Fablab de Sophia ( SoFab ) afin d'utiliser la découpe laser.
Pour pouvoir découper avec le matériel du Fablab il faut que le fichier soit sous format
svg, donc j'ai refait les formes dont j'avais besoin sur le logiciel inkscape.

## Pour le support de l'écran:

![Image du support d'écran](https://github.com/YassineWaldane/Arduino/blob/master/images/supportecran.png)


Mais comme toujours on fait des bêtises comme ici ^^ où j'ai raté les encoches:

 
![Image de l'erreurmdr](https://github.com/YassineWaldane/Arduino/blob/master/images/erreurmdr.jpg)

## Pour le support des servomoteurs avec une petite gravure du plus grand duo d'Arduino:

![Image du support](https://github.com/YassineWaldane/Arduino/blob/master/images/grossupport.png)

## Résultat Final :
![Image Final écran](https://github.com/YassineWaldane/Arduino/blob/master/images/finalecran.jpg)
![Image Final grossupport](https://github.com/YassineWaldane/Arduino/blob/master/images/20190111_221210.jpg)

À part ça, j'ai decoupé des tuyaux en métal afin d'en faire des bielles.
Ce week-end je vais essayer de monter le tout.