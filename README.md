# Projet C
Le projet C s'inscrit dans le cadre de la formation du diplôme d'ingénieur à CY TECH. Le but est de créer un éditeur textuel pour les **automate** d'**état fini** (**AEF**). Un automate fini ou automate avec un nombre fini d'états (en anglais finite-state automaton ou finite state machine ou FSM) est un modèle mathématique de calcul, utilisé dans de nombreuses circonstances, allant de la conception de programmes informatiques et de circuits en logique séquentielle aux applications dans des protocoles de communication, en passant par le contrôle des processus, la linguistique et même la biologie.


# Documentation

## Guide d'utilisation
> Pas de guide d'utilisation pour le moment ...

## Fichiers
> Pas d'arborescence pour le moment ...

## Fonctions
> Pas de fichier pour le moment ...




# Travail à réaliser

Il nous est demandé de réaliser un éditeur dédié aux automates finis. Dans ce qui suit, X
est un alphabet (un ensemble de symbole). L’éditeur permet de :

1. Manipuler des mots d’un alphabet
	- Vérifier si un mot appartient à X*.
	- Calculer la puissance d’un mot.
	- Vérifier si un mot est vide (3psilon).
	- Concaténer deux mots.
	- Calculer le miroir d’un mot.
	- Vérifier si une chaine de caractères représente un mot fini.

2. Manipuler un AEF
	- Saisir un AEF.
	- Importer un AEF à partir d’un fichier.
	- Modifier un AEF.
	- Sauvegarder un AEF dans un fichier.

3. Vérifier si un mot est reconnu par un AEF.

4. Vérifier si un automate est complet.

5. Rendre un automate complet.

6. Vérifier si un automate est déterministe.

7. Rendre un AEF déterministe.

8. Vérifier que tous les cycles d’un AEF sont unitaires. Répondre par vrai pour tout AEF sans cycle. Un cycle est un chemin fermé (une boucle).

9. Extraire le langage reconnu par un AEF. Vous supposez que seuls les cycles
unitaires sont pris en charge.

10. Suppression des transitions epsilon (vides).

11. Réaliser des opérations suivantes sur les AEFs :
	- Complément d’un AEF.
	- Miroir d’un AEF.
	- Produit de deux AEFs.
	- Concaténation de deux AEFs.

12. Vérifier si deux automates sont équivalents Vous supposez que seuls les cycles
unitaires sont pris en charge.

13. Rendre minimal un EDF déterministe ([Wikipedia - Minimisation d'un automate fini déterministe](https://fr.wikipedia.org/wiki/Minimisation_d%27un_automate_fini_d%C3%A9terminist))

14. Expressions régulières (Ers)
	1. Manipuler une ER :
		- Saisir une ER.
		- Importer une ER à partir d’un fichier.
		- Modifier une ER.
		- Sauvegarder une ER dans un fichier.
	2. Vérifier si une ER est correcte
	3. Vérifier si un mot est reconnu par une ER.
	4. Traduire une ER en un AEF équivalent.
