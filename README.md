# TP

## Compilation

```sh
make all
```

## Execution

Pour lancer le jeu en mode normal (10x20 10 Bombes) :

```sh
make run
```

Pour lancer le programme avec des paramètres personalisés :

```
bin/TP9 -H <Hauteur> -L <Longueur> -M <Nombre de mines>
```

Si in des arguments n'est pas specifié il sera initialisé a ca valeur par défaut.

### Arguments possibles

- `-L <int>` : Longueur du plateau
- `-H <int>` : Hauteur du plateau
- `-M <int>` : Nombres de mines
- `-h`       : Affiche l'aide du programme


### Gameplay

|     Caractère     |           Signification            |
| :---------------: | :--------------------------------: |
|        `~`        |        Case non découverte         |
|        `⸰`        |              Curseur               |
|        `⚑`        |              Drapeau               |
| `1,2,3,4,5,6,7,8` | Nombre de bombes autour de la case |


#### Interactions

|          Touche           |                                Action                                |
| :-----------------------: | :------------------------------------------------------------------: |
| `Flèches directionnelles` |                          Deplace le curseur                          |
|            `D`            |           Change le mode du curseur (Drapeau, Découverte)            |
|         `Espace`          |    Découvre ou met un Drapeau sur la case la case sous le curseur    |
|      `Clique gauche`      |      Découvre la case pointé et déplace le curseur à cette case      |
|     `Clique molette`      | Met un Drapeau sur la case pointé et déplace le curseur à cette case |


## doxygen

```sh
make docs
```

Elle est aussi accessible a cette addresse [http://programation-c-ing1.rodriguess.me/tp9](http://programation-c-ing1.rodriguess.me/tp9)

## zip

Remplacer `login` par votre nom d'utilisateur

```sh
USER=login make give
```
