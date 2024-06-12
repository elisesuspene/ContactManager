# ContactManager

C++ school project : contact app

#LE PROJET :
-
Ce projet a été réalisé sur QTCreator. C'est une application gestionnaire de contacts : la page d'accueil affiche une vue du tableau des contacts. Le tableau complet est présent dans le fichier .ui, mais caché (not visible) à l'exécution. On peut ajouter un contact à l'aide d'un bouton dédié ou en supprimer un en double-clickant sur la ligne. On dispose d'une barre de recherche pour trouver les contacts dont les noms contiennent une lettre ou une séquence de lettres, insensiblement à la casse. Des filtres sont aussi proposés et fonctionnent en parallèle. Les contacts sont stockés dans un fichier contacts.json, ce qui permet de les retrouver même après avoir fermé la fenêtre.

Image de la page d'accueil vide :
![image](https://github.com/elisesuspene/ContactManager/assets/114237450/6d7a51e0-a7eb-4828-8782-47be220bef10)
Avec une entrée : 
![image](https://github.com/elisesuspene/ContactManager/assets/114237450/547567fb-05f3-404b-9ddc-53adf529496e)
Boîte de dialogue pour suppression d'un contact :
![image](https://github.com/elisesuspene/ContactManager/assets/114237450/8f984630-8165-41e5-8dc8-ccb1c8f19556)

#CE QUI A ETE DIFFICILE :
-
-l'installation de Qt de manière compatible avec QTCreator. Malgré mon tâtonnement, l'aide du professeur m'a été indispensable.
-prendre en main Qt. Le sujet de TD du cours électif m'a été très utile car il m'a permis de me familiariser avec Qt, mais cela m'a pris du temps de le faire, que je n'ai pas passé sur mon projet.
-bien référencer chaque fichier dans les autres fichiers : comprendre quel est le nom de la classe, le nom du fichier, faire les bons imports (fichiers .h et .ui) et mettre les noms de classes avant les noms de fonctions.
-utiliser les models et proxymodels pour faciliter la barre de navigation et le filtrage : comprendre les fonctions et objets prédéfinis dans les objets QSortFilterProxyModel par exemple.
