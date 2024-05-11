
# GameEngine

Squelette d'un moteur de jeu en c++.



## Features

- Gestion d'une **Scene** au travers d'un **SceneManager**
- Une **Scene** contient des **GameObjects**
- Un **GameObject** contient des **Components**
- Le moteur contient un **EngineContext** en charge des updates
- L'**EngineContext** contient un **Engine** en charge des **SubSystem**
- Il existe un sous-système dédié à l'update des **Components** de type Transform et tout ce qui touche à la physique.
- Il existe un sous-système dédié à l'update des **Components** de type Behaviour et tout ce qui touche au comportement.
- Nous utilisons un architecture observer afin de manipuler facilement l'ajout des **Components** dans une **Scene**
- Nous utilisons une pool préallouée de GameObjects afin de limiter les interactions mémoires au runtime.
- Cependants les **Components** sont alloués dynamiquement au runtime. C'est un axe d'amélioration envisageable vers une Object Arena.
- Il est possible de sauvegarder/charger la scène actuelle dans un JSON.
- On peut ajouter des objects templates à la scène actuelle.
- On peut créer une scène pour remplacer la scène actuelle. cette dernière est alors sauvegardée.
- La scène contient un nom qui permet de l'identifier. Il est utilisé pour créer le JSON. Si la scène est chargée depuis un fichier, le nom du fichier est utilisé.
