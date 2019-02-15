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

# `Semaine 5 18/01/2019:`

J'ai adapté deux bielles sur la partie du support de l'écran 
afin de transmettre le mouvement à l'écran plus tard.
J'ai dû agandir les petits troux sur le support pour y faire passer des tiges 
filettées qui feront office d'axes de rotations. Puis j'ai aussi troué les tubes
de métal qui seront les bielles transemttent le mouvement au support de l'écran.

## Le support de l'écran ressemble donc à :

![Image du support d'écran complet 1](https://github.com/YassineWaldane/Arduino/blob/master/images/support%20final%201.jpg)

![Image du support d'écran complet 2](https://github.com/YassineWaldane/Arduino/blob/master/images/support%20final%202.jpg)

J'ai fait un petit programme simple pour les servomoteurs, qui sert juste a faire 
tourner l'axe du moteur par rapport à la tension du potentiometre.

## Le programme des servomoteurs :

![Image du programme des servomoteurs](https://github.com/YassineWaldane/Arduino/blob/master/images/code%20moteur%2Bpotentio.png)

Il fonctionne très bien avec les servomoteurs basiques mais lorsque j'ai essayé
de faire le fonctionner avec les servomoteurs que l'on utilisera pour notre projet
il y a un problème d'alimention des servomoteurs.
Ils ne fonctionnent pas avec du 6V et 170mA comme ils le devraient selon
leurs datasheets.
J'essayerai de corriger cela durant la semaine qui vient.
 
 
## `Semaine 6 ( 06 / 02 / 2019 ) :`

Après avoir fais un bon paquet de test j'ai réglé le problème des servomoteurs
en trouvant que ce problème venait de l'adaptateur qui ne fonctionnait pas.
Reste à savoir si je peut alimenter les deux servomoteurs avec cet adaptateur seulement.

Puis nous sommes aller au Fablab pour refaire certaines parties du chassis
tel que les deux bielles entre les servo et le support de l'écran.
Cette fois ci avec les bonnes côtes, mais dans le bus pendant les 45 minutes
de trajet commun avec Baptiste nous avons vivement débattu et nous avons trouvé
LA solution utiliser des Geomag pour nos bielles, les Geomag permettent des liaisons
rotules ce qui nous pensons supprimera certaines contraintes que j'expliquerai à
l'oral car c'est pas très bien expliquable à l'écrit.

## `Semaine 7	(13 / 02 / 2019) :`

Cette séance nous a permis d'achever toutes les parties du supports que ce soit le nouveau support d'écran ou encore le placement des support des servomoteurs sur le suport au sol.
Nous avons perdu pas mal de temps à la découpe laser car Incscape n'est oas très pratique, nous avons donc refait notre modèle sur inventor puis exporter ce modèle en svg (format qu'accepte la découpeuse laser). 

Voici le résultat:

![Image du support écran V3](https://github.com/YassineWaldane/Arduino/blob/master/images/Nouveau.jpg)

Comme je l'ai dis la semaine dernière afin d'avoir le minimum de contrainte nous avons décider d'utiliser des geomags pour faire nos liaison voici une fiche récapitulative: 

![Fiche récap 1](https://github.com/YassineWaldane/Arduino/blob/master/images/Bielle%20(1).jpg)
![Fiche récap 2](https://github.com/YassineWaldane/Arduino/blob/master/images/Bielle%20(2).jpg)

Nous avons donc fixé les liaisons sur le support.

![Support fini](https://github.com/YassineWaldane/Arduino/blob/master/images/nouveau%20%2B%20bielles.jpg)

Ainsi que les supports de servomoteurs à leur place.

![Support servos](https://github.com/YassineWaldane/Arduino/blob/master/images/Support%20Servos.jpg)

J'ai aussi modélisé les liaisons bielles-servomoteurs que l'on imprimera en 3D si possible 
![bielle servos](https://github.com/YassineWaldane/Arduino/blob/master/images/bielleServo.jpg)
![bielle servos 1](https://github.com/YassineWaldane/Arduino/blob/master/images/bielleservo1.jpg)
