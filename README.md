# **Réalisation du jeu de société Sonar Family en C**

## **Utilisation de la bibliothèque graphique SDL2**

### **UTILISER** le projet, dépendances à installer :
    sudo apt install libsdl2-2.0-0 libsdl2-ttf-2.0-0 libsdl2-mixer-2.0-0 libsdl2-image-2.0-0 libsdl2-gfx-1.0-0


### **EDITER** le projet, dépendendances à installer (dev):
    sudo apt install libsdl2-dev libsdl2-gfx-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
    sudo apt-get install valgrind lcov

Il faut aussi installer Cmocka pour les tests unitaires : [Site officiel](https://cmocka.org/)
### **TESTER** le projet:
- Se rendre dans le répertoire _./Projet_C_
- Pour compiler avec les Tests Unitaires : `make TEST=yes`
- Pour compiler avec les pertes de mémoires : `make MEM=yes`
- Possibilité de combiner les 2 tests
- Executable des Tests Unitaires _./Projet_C/Test_Unitaires/UTest_modele_
- Code Coverage du modèle : _./Projet_C/Test_Unitaires/Coverage_model_info/index.html_
- Code Coverage des Tests : _./Projet_C/Test_Unitaires/Coverage_test_info/index.html_



### **NETTOYER** le projet:
- Se rendre dans le répertoire _./Projet_C_
- `make allClean` Nettoie tout le projet sauf les Tests Unitaires
- `make testClean` Nettoie le dossier des Tests Unitaires


### **INSTALLER** le projet :
- Se rendre dans le répertoire _./Projet_C_
- Exécuter la commande `make `


### **LANCER** le projet :
- Faire `./Launcher` dans le répertoire _./Projet_C_ pour lancer le jeu

### **EN CAS D'ERREUR** :
Si vous avez une erreur de librairie malformée, il vous suffit de faire un `make allClean` puis de rebuid le projet depuis
le dossier _./Projet_C_

## **Projet Réalisé par** :
- Robin Deplanques
- Alexis Rabiller 
- Audrey Cornec
- Rafael Rojas Galvan

## **Encadrants**:
Alban Marie

## **Responsables de projet**:
Karol Desnos
Muriel Pressigout

