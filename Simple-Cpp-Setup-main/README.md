# Simple-Cpp-Setup

Welcome to this minimalist C++ project!

## If you use the Dev Container

If you install [ms-vscode-remote.remote-containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) and [Docker](https://www.docker.com/products/docker-desktop), you will be able to run your code inside a Linux container (kind of like a virtual machine, but faster). Also, you will get static analyzers, code formatters and useful extensions installed out of the box! It is a great option to get started with C++ quickly.

(Unfortunately, if you want to do GUI applications they don't work well from within a container and you might have to do a proper setup on your own desktop instead. But for simple command-line applications this works amazingly well!)

NB: the container might take a while to build the first time.

## If you don't use the Dev Container

### Compiling

You need to install [CMake](https://cmake.org/download/).

To use CMake I recommend this VS Code extension : [ms-vscode.cmake-tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools). You will need to setup the extension with a compiler. Here is [the tutorial](https://code.visualstudio.com/docs/cpp/cmake-linux). It is based on Linux but at the bottom of the page you will find the explanations to adapt it for [Windows](https://code.visualstudio.com/docs/cpp/config-msvc) and [Mac](https://code.visualstudio.com/docs/cpp/config-clang-mac).

Alternatively you can just create a *build* folder at the root of this project, open a terminal and run `cmake ..`; chances are it will detect what compiler you have installed and generate the appropriate Makefile / Visual Studio solution / Xcode project.

### Auto-formatting

[Check this out](https://julesfouchy.github.io//Learn--Clean-Code-With-Cpp/lessons/formatting-tool) to learn why you would want to use a code formatter and how to do it.

### Static analysis

[Check this out](https://julesfouchy.github.io/Learn--Clean-Code-With-Cpp/lessons/static-analysis-and-sanitizers) to learn why you would want to use static analysis and how to do it.



## prog-objet-IMAC2

### Premiere seance le 09/02/22

### 16/02/22
- Level 1 lu et complété
- 2 premiers cours du level 2 lus

### 23/02/22
- Dossier déposé sur ce repo github
- Jeu guess the number codé et fonctionnel (attention à la place de cmake pour la compilation)
- Début de Hangman (idées, début de code mais pas terminé)

### 02/03/22
- Création du fichier rand.hpp pour utiliser la fonction rand partout où on en a besoin
- Hangman suite : encore quelques erreurs à régler mais la structure globale est faite
- 3e cours du level 2 lu
-> correction des erreurs le 03/03 et commit à cette date

### 09/03/22
- Quiz
- 4e cours du level 2 lu
- Création des fichiers get_input_from_user.hpp et .cpp, et menu.hpp et .cpp
- Menu à améliorer (mais pour l'instant il n'y a pas d'erreur)

### 16/03/22
- Quelques améliorations sur Hangman.cpp et corrections d'erreurs sur l'ensemble du code
- 5e cours du level 2 lu

### 23/03/22
- Hier : ajout de commentaires + const pour la méthode word_is_found()
- Modification Hangman car les messages dans le terminal se répétaient
- Correction de la fonction random()
- 6e et 7e cours du level 2 lus

### 06/04/22
- Derniers cours du level 2 lus
- Modification du menu (pas d'erreur mais ne fonctionne pas encore)

### 13/04/22
- Submodule p6 : premiers essais, lecture, etc.

### 11/05/22
- Continuer sur le morpion avec p6