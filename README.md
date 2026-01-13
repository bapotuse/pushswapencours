*This activity has been created as part of the 42 curriculum by rpetite, bbeaux.*

# Push_Swap         

## Description

Push_Swap est un programme qui trie une pile d'entiers en utilisant un ensemble limité d'opérations, en cherchant à minimiser le nombre de mouvements nécessaires. 

## Instructions

Compiler le projet :

```bash
make
```
Nettoyer les fichiers objets

```
make clean
```

Supprimer les fichiers objets

```
make fclean
```

\
**Test du projet :**

```bash
./push_swap [liste de nombres]
```

Exemple :
```bash
./push_swap 3 2 5 1 4
```

Le programme affiche la liste des opérations nécessaires pour trier la pile.

## Opérations disponibles

- `sa` : swap a - échange les 2 premiers éléments de la pile a
- `sb` : swap b - échange les 2 premiers éléments de la pile b
- `ss` : sa et sb en même temps
- `pa` : push a - prend le premier élément de b et le met sur a
- `pb` : push b - prend le premier élément de a et le met sur b
- `ra` : rotate a - décale tous les éléments de a vers le haut
- `rb` : rotate b - décale tous les éléments de b vers le haut
- `rr` : ra et rb en même temps
- `rra` : reverse rotate a - décale tous les éléments de a vers le bas
- `rrb` : reverse rotate b - décale tous les éléments de b vers le bas
- `rrr` : rra et rrb en même temps

## Algorithmes

Le programme utilise différentes stratégies selon la taille de la pile :
- Algorithme simple pour les petites piles (2-3 éléments)
- Algorithme moyen pour les piles de taille moyenne (4-5 éléments)
- Algorithme complexe pour les grandes piles (plus de 5 éléments)
- Algorithme adaptatif qui choisit automatiquement la meilleure stratégie. 

## Resources

J'ai réalisé ce projet à l'aide de plusieurs sites, notamment KooR.fr, j'ai aussi regardé des tutoriels sur YouTube afin d'apprendre plusieurs notions (notamment les stacks), et j'ai aussi beaucoup demandé à mes camarades.