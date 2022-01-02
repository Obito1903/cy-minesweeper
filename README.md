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
