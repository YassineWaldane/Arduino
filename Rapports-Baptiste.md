# Rapport Projet d’Arduino

## 07/12/2018 :

Pris connaissance de la manière de réaliser le projet : Sur quoi le projet repose principalement ?
Au départ nous partions sur un accéléromètre, pour calculer l’accélération linéaire selon les 3 coordonnées afin de situer la balle dans l’espace.
Après avoir tenté de comprendre le principe de fonctionnement de l’accéléromètre, grâce à l’exxxxxxxxxxxxxxcellent cour de monsieur Masson, nous nous sommes rendu compte qu’il existait un moyen bien plus simple de connaitre la position d’une balle sur un écran.
C’est un écran dit  résistif : qui envoie en output la position x et y de la balle sur la plaque, on note que la position en z (hauteurs) n’est pas utile.

Maintenant que nous avons opté pour un écran reste à choisir le lequel prendre ? Quelle taille ?
Le tout avec un prix raisonnable > qui ne sera au finale pas un problème ce type d’écran n’étant pas si cher.
17 Ou 8 pouces ? Dans le deux cas nous avions trouvé des projets similaires au notre, prouvant que les deux écrans étaient compatibles avec celui-ci.
Nous avons noté que plus l’écran était grand moins le « Centrage » de la balle était précis dû à une plus grande incertitude.
Nous avons, en optant pour la précision, commandé un écran 8pouces.

Reste maintenant à choisir les moteurs : Pas à pas ou servo

## 14/12/2018 :

Donc, nous commençons par choisir les moteurs .Nous avons étudié plusieurs projets du même type , la plupart utilisent des servomoteurs mais le projet qui nous sert de modèle utilise des moteurs pas à pas cependant , nous avons remarqué la présence d’encodeurs dans ce projet , leurs utilités est de trouver la position zero de chaque moteurs pas à pas, d’autres problèmes sont liés aux moteurs pas à pas, nous avons donc décidé de choisir des servomoteurs pour palier à ces différents soucis.
 Pour la référence exacte du servo, on s’inspire encore une fois de projets similaires pour avoir une idée de la vitesse de rotation et le couple nécessaires au bon fonctionnement de note projet.
On opte finalement pour le servo suivant : MG946R

Pour le moment nous faisons tout en duo mais maintenant il faut répartir les différentes taches afin d’optimiser le temps de travail, nous divisons donc le projet en plusieurs grandes parties :

- Liste du matériel (déjà fait) > Yassine + Baptiste

- Gestion de l’écran résistif > Yassine +Baptiste

- Gestion du PID (la plus complexe) > Baptiste

- Gestion des Servomoteurs > Yassine

- Gestion du code > Baptiste,

- Réalisation matériel (maquette en bois) > Yassine

Cette répartition étant bien évidemment provisoire.

Nous allons suivre la progression de chacun constamment, l’assignement des taches correspond juste à une spécification dans un certain domaine.

## 18/12/2018 :

Aujourd’hui, nous avons commencé à suivre nos répartitions de taches, j’ai donc commencé la compréhension du Pid, premièrement au niveau théorique, le principe est assez simple, le PID est divisé en 3 parties : Proportionnal , Intergral , Derivative d’où PID , chaque partie à une fonction différente. Pour expliquer sans rentrer dans les détails, je vais donner un exemple pour chaque partie,
Soit un pendule, qu’on lâche à une hauteur h (position P), on veut que grâce au PID, il se stop à l’origine, avec le moins d’oscillation possible :
Les calculs que va faire le PID sont les suivants,

`Proportionnal` : « A quel point je suis loin de la position d’origine ? », Plus je suis loin plus la vitesse que l’on va me donner est grande.

`Integral` : « Depuis combien de temps que l’on ma lâché de la position P ? » Plus on m’a lâché depuis longtemps, plus on doit me donner de la vitesse.

`Derivative` : « A quel point je suis proche de l’origine » Plus je suis proche de celle-ci, moins on doit me donner de vitesse (ralentissement).

Bien évidemment, derrière ses principes, il y a des calculs extrêmement complexes que j’ai compris en diagonal, mais j’ai vite compris que vouloir comprendre l’intégralité des calculs allait être une perte de temps.
 J’ai alors malgré, l’absence de matériel pour l’instant, commencé la partie code du TouchScreen, en m’appropriant les fonctions de base de la bibliothèque TouchScreen.h, Les fonctions sont plutôt simple à utiliser, l’ensemble est plutôt simple à manipuler.
Nous avons aussi effectué un changement majeur dans notre projet, l’utilisation de 2 servomoteurs au lieu de 3 prévus, un servo gérera l’axe l’autre l’axe y.

 ## 11/01/2019 :

Reprise post-vacances du projet, je n’ai personnellement pas vraiment travaillé sur le projet pendant celles-ci, ne possédant pas le matériel nécessaire et n’ayant pas le temps (fêtes + plusieurs DS à préparer).
Pendant cette séance, j’ai bossé sur le touchscreen, celui-ci enfin en notre possession, avant les vacances j’avais écrit le code pour tester le Touchscreen, j’ai donc pu le tester.
Résultat : après quelques problèmes d’exportation de librairies, le programme nous renvoie des coordonnées correspondant à notre position sur le touchscreen, mais il y a un problème :
Au niveau des coordonnées celles-ci sont faussées , en effet le touchscreen est constitué de plusieurs écrans, pour faire simple disons qu’il y en a un grand et un petit, la propriété tactile est présente uniquement sur la surface du petit écran ( rouge ), il y a donc un bord qui n’est pas tactile,

![Image ecran avec bords](https://github.com/YassineWaldane/Arduino/blob/master/images/%C3%A9cranbapt.jpg)

 Pour les calculs avec le PID, seul la surface tactile est importante, or l’origine des coordonnées n’est pas située dans le petit écran, Le coin correspondant au coin  bas-gauche du petit écran correspond au point (66.115), j’ai donc mettre en place 2 variables convert, pour redéfinir l’origine des systèmes de coordonnées.
J’ai ensuite commencé la partie communication, dans notre projet à la place de mettre une manette physique nous permettant par exemple de bouger manuellement la plaque ou de placer la Ball à un endroit précis, nous avons opté pour un système Bluetooth donc une manette virtuelle sans fil, j’ai donc commencé le code correspondant à la manette, celui-ci est fortement incomplet la partie sur les servos moteurs n’étant pas encore faite.

![Image ecran avec zones](https://github.com/YassineWaldane/Arduino/blob/master/images/%C3%A9cranavecbords.png)

Les zones A, B, C, D divisent l’écran en 4 parties, dans lesquels la balle pourra être dirigés à condition d’appuyer sur les boutons correspondants sur la manette,
Finalement j’ai trouvé un code pour la partie PID correspondant à notre projet, code qui n’est pas encore compris dans sa totalité mais la est pas difficulté majeur du projet

## 18/01/2019 :

La première chose à faire et la seul chose que j’ai faite pendant cette séance était de régler le problème de l’écran, le résultat escompté étant que le programme renvoie la position en mm,
Ce qui m’a perturbé, c’est que le point central soit associé à la coordonnée (516,516), l’écran étant rectangle. Les variables convert précédemment étaient basé sur un simple produit en croix, le résultat était convenable quand on regardait l’origine, mais j’ai vite remarqué que ça ne marchait pas pour tous les points.

J’ai donc utilisé la méthode map() d’Arduino, qui prend en paramètre une variable x, un intervalle borné sur lequel elle varie et un intervalle sur laquelle on veut la faire varier,
On prend alors la variable p.x qui correspond à la valeur en x du point auquel une pression est exercée, celle-ci varie de 102 à 925 et on veut qu’elle varie de 10mm à 130mm (pas 0-14cm car les bords ne sont pas tactiles), idem pour p.y, on a alors converti les coordonnées en mm.
On note que pendant cette séance j’ai passé tout mon temps à me battre contre des problèmes de ports et bien évidemment des fautes d’inattention dans mon programme (exemple, inverser p.x et p.y), des erreurs qui n’ont pas été directement corrigés car les résultats étaient quasiment satisfaisants environ 0.5 cm de décalage avec la réalité et ceux avec des erreurs de code.

### Le code qui permet de donner la position de la balle sur l'écran :

![Image code ecran](https://github.com/YassineWaldane/Arduino/blob/master/images/Code%20%C3%A9cran.png)

### Voici le montage de l'écran :

![Image montage ecran](https://github.com/YassineWaldane/Arduino/blob/master/images/montagecranbapt.jpg)
## 06/02/2019

Début de séance, Vérification pour les servos moteurs, avec un simple code test:
![Image code](https://github.com/YassineWaldane/Arduino/blob/master/images/Code%20test%20servo%20.PNG)

Ensuite, il fallait avancer le montage du projet car pour effectuer les tests concrets du code, il nous faut un montage quasi terminé. Les prochaines séances seront consacrées pleinement au montage. 
![Image montage](https://github.com/YassineWaldane/Arduino/blob/master/images/Maquette.PNG)

Avec 1, Le pilier central maintenant la plaque et 2 les servos moteurs contrôlant la plaque, reliés à elle avec des tiges.
Nous sommes donc allés au fable, pour avancer la conception, avec la création des bielles et la mise en place des éléments 
![Schemas](https://github.com/YassineWaldane/Arduino/blob/master/images/Bielle%20(1).jpg)
![Schema](https://github.com/YassineWaldane/Arduino/blob/master/images/Bielle%20(2).jpg)

## Réalisation : ( bielles = geomag )
![ImageIRL](https://github.com/YassineWaldane/Arduino/blob/master/images/bielle%2Bsupport%20irl.jpg)

## 13/02 :

Début de séance au fablab, pendant 2 heures, pour continuer la conception de la maquette, le nouveau support / bielles étant prêts, nous avons décidé de support pour l’écran. Ayant eu quelque problème, la création de celui-ci nous a pris du temps, notamment dû à l’importation de fichier inventor vers svg.

## Ancien support:
![Ancien](https://github.com/YassineWaldane/Arduino/blob/master/images/Ancien.jpg)

## Nouveau support :
![nouveausupport](https://github.com/YassineWaldane/Arduino/blob/master/images/Nouveau.jpg)

## Montage:
![Support+bielles](https://github.com/YassineWaldane/Arduino/blob/master/images/nouveau%20%2B%20bielles.jpg)

Ensuite nous avons mis en place, les différents éléments et collé les supports servos, on note que pour placer ces supports il fallait faire attention à alignements des éléments  

## Mise en place + fixation des support Servos
![miseenplace](https://github.com/YassineWaldane/Arduino/blob/master/images/Support%20Servos.jpg)

La dernière étape pour finaliser la maquette, créé une « extension » pour la bielle afin de pour créer une liaison pivot servo-bielle, étant donné que percer directement les barres géomag est impossible

## Extention schéma:
![test](https://github.com/YassineWaldane/Arduino/blob/master/images/Pivot%20.jpg)


## 28/03

Pendant cette séance, il fallait finir la maquette de projet pour pouvoir avancer.
Donc imprimer en 3d , les supports bielles et créer le pilier centrale.
 Tout d'abord, nous avons imprimé au fablab le modèle précédemment esquisser. Les premieres impressions étant raté nous avons du nous y prendre à plusieurs reprises, l'imprimante du Fablab étant d'une extreme imprecision. Pour au final nous rendre compte que : Le modèle choisi ne correspondait pas à nos  attentes.  Nous avons donc du imaginer un nouveau modèle de support bielle.( Voir schéma explicatif  fin ).
 
 L'avantage de ce nouveau modèle, en plus qu'il correspond à nos attentes et que nous ne sommes pas obligé de réimprimer des supports, en poncant au papier de verre, on peut passer du modèle 1 au modèle 2.
 Les supports bielles étant finis et donc les bielles étant finis, il ne restait plus que le pilier centrale à finir ( voir schéma explicatif fin ).
 
 Après quelques calculs pour obtenir les dimensions de chaque pièces du pilier, nous avons pu le finaliser et ainsi finaliser la maquette.
 
On note que chaque millimètre compte dans ce genre de projet, qui se base sur l'équilibre, d'ou le temps investit dans la réalisation de maquette.

## Schéma explicatif

![Schema piece 1](https://github.com/YassineWaldane/Arduino/blob/master/images/Schema%20piece%20(1).jpg)
![Schema piece 2](https://github.com/YassineWaldane/Arduino/blob/master/images/Schema%20piece%20(2).jpg)

## SCHEMA MAQUETTE 

La maquette n'est pas fini à 100% certain éléments ne sont pas encore collés entre eux, d'ou le fait que le rendu ne soit pas encore parfaitement droit.

![Maquette](https://github.com/YassineWaldane/Arduino/blob/master/images/Maquette%201.jpg)
![Maquette 2](https://github.com/YassineWaldane/Arduino/blob/master/images/Maquette%202.jpg)


Petite précision sur le magnétisme dans notre projet :

Les billes métalliques ne sont pas polarisés, elles n'attirent donc pas le métal, les barres magnétiques polarisent alors les billes, d'ou l'attration entre ces deux éléments et la non-présence de colle, l'attration étant assez forte pour lier les deux élements.
Pour le pilier, la bille et le tube sont non polarisés, et on ne peut pas utilisé, une barre magnétique comme pour les bielles, le pilier devant être bien plus imposant, Nous avons donc utilisé un aimant, pour revenir à la situation précedemment expliquée celui-ci polarisera le tube et la bille. ( Ce procédé est assez complexe à expliquer et bien plus simple a illustré En direct avec une manipulation simple )
Le gros avantage de ce servir des forces magnétique, et que nous utilisons peu de colle, et donc nous pouvons à tout moment revenir en arrière.


