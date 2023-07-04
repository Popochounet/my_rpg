# Library My Graphics 0.1
La librairie My Graphics est une sur-couche à la CSFML. Elle permet de limiter l'usage par l'utilisateur de fonctions graphiques de la sfml pour manipuler des objets tel que des sprites. La librairie fournie aussi une fenêtre avec un agencement plus complexe pour simplifier la création d'un jeu avec la sfml.

# How to Use
## Window
Premièrement, comme pour la SFML, il faut créer la fenêtre principale.
### What is it
Dans la lib window_t correspond à une structure qui contient entre autre la fenêtre de la SFML. Voici un schéma pour la représenter :
```mermaid
  graph TD;
    A[window] --> B[SFML window structure];
    A --> C[size vecteur];
    A --> D[SFML view];
    A --> E[background layer];
    A --> F[core layer];
    A --> G[fx layer];
    A --> H[ui layer];
    A --> I[splash layer];
    E --next--> F;
    F --next--> G;
    G --next--> H;
    H --next--> I;
```
- **size** est un vecteur à deux dimension qui conserve les dimensions initiales de la window.
- **window** est un pointeur vers la structure sfRenderWindow correspondant à la structure window.
- **view** est globalement une caméra interactive qui permet de modifier le point de vue de la window.
- **background** est une structure layer (voir section correspondante) destinée à contenir tous les assets de fond du jeu sans interactivités.
- **core** est une structure layer (voir section correspondante) destinée à contenir tous les assets manipulables du jeu en lui-même.
- **fx** est une structure layer (voir section correspondante) destinée à contenir tous les effets spéciaux.
- **ui** est une structure layer (voir section correspondante) destinée à contenir les assets de l'interface utilisateur. Ce layer n'est pas affecté par la view.
- **splash** est une structure layer (voir section correspondante) destinée à contenir le splash screen.

### Creation
Pour créer notre fenêtre il suffit de créer une window_t structure en utilisant la fonction suivante :
```c
window_t * create_window(const char * title, const sfVideoMode mode, const char * file);
```
- **title** correspond au titre de la fenêtre.
- **mode** est une structure de la SFML qui contient la largeur, la hauteur et le framerate de la fenêtre.
- **file** est un path vers une image qui peut servir d'icone. Si vous ne voulez pas en fournir, remplacez par NULL.

### Displaying
Pour l'affichage il suffit d'appeler la fonction suivante lors du rafraîchissement de l'image :
```c
void actualize_window(window_t * window);
```
Il suffit de lui donner la window en paramètre et tout sera calculé et affiché par la fonction.
Si toutefois vous souhaitez manipuler vous même les étapes d'affichages vous pouvez utiliser les fonctions d'affichages des sous-structures de la lib.
En revanche l'usage des deux méthodes est incompatible, attention.

### Destruction
Toujours penser à free. En l'occurence il suffit d'appeler la fonction suivante pour free la fenêtre et tout ce qui aura été créé par la lib par la suite (si et seulement si tout est correctement créé) :
```c
void free_window(window_t * window);
```
Bien que cela est possible, il est fortement déconseillé d'appeler les autres fonctions de free de la lib ou de la SFML.

### Manipulate the view
Pour manipuler la caméra on peut utiliser les fonctions suivantes.
```c
void view_resize(window_t * window, sfVector2f size);
void view_center(window_t * window, sfVector2f center);
void view_set_rotation(window_t * window, float angle);
void view_rotate(window_t * window, float angle);
void view_zoom(window_t * window, float factor);
```
La caméra se manipule globalement comme un sprite donc je ne vais pas tout réexpliquer sauf pour view_center. La view, contrairement à un sprite, se manipule grâce à son centre. Il faudra donc penser à donner le centre du sprite et non la position en haut à gauche du sprite.

## Layer
Une fois la window créée, les différents assets à afficher sont répartis sur des layers différents. Par défaut il y en à 5 dans la window cependant on peut en ajouter plus en les chaînants.
### What is it
Un layer agit comme une sorte de fenêtre dans la fenêtre. Donc on peut y appliquer à peu près tout ce que l'on peut faire à la fenêtre d'un point de vue graphique. Cela permet de aisémenet l'affichage de sprites à des profondeurs différentes et les modifications de masse sur plusieurs sprites.
```mermaid
  graph TD;
    A[layer] --> B[type];
    A --> C[render texture];
    A --> D[sprite];
    A --> E[size vecteur];
    A --> F[draw list];
    A --> G[show];
    A --> H[next & previous];
```
- **type** indique à quelle section parmi background, core, fx, ui et splash le layer appartient.
- **texture** est une sfRenderTexture. C'est une texture de la SFML qui agit comme une sfRenderWindow.
- **sprite** permet juste d'afficher la texture du layer sur la fenêtre au moment de l'affichage.
- **size** est un vecteur qui correspond aux dimensions de la texture.
- **draw** est une liste de draw structure (voir section correspondante) qui sont tous les assets qui peuvent être affiché dans ce layer.
- **show** est un bouléen qui indique si le layer doit être affiché sur la window lors du rafraîchissement de l'image.
- **next** & **previous** sont des pointeurs vers les autres layers si existants.
### Creation
Vous n'aurez pas à gérer vous même la création de layer. En cas de besoin, voir dans le header *layer.h* la fonction *create_layer*.
### Displaying
Vous n'aurez pas à gérer vous même l'affichage de layer. En cas de besoin, voir dans le header *layer.h* la fonction *draw_layers*.
### Destruction
Vous n'aurez pas à gérer vous même le free de layer. En cas de besoin, voir dans le header *layer.h* la fonction *free_layers*.

## Draw
Une draw structure est un asset à afficher sur un layer. Cet asset peut être un sprite, un rectangle, un cercle ou du texte (voir les sections correspondantes pour plus d'informations ; PS: pour rectangle et cercle voir shape).
### What is it
Voici un schéma qui représente la draw structure :
```mermaid
  graph TD;
    A[draw] --> B[drawable];
    A --> C[type];
    A --> D[data structure];
    A --> E[id];
    A --> F[show];
    A --> G[next & previous];
```
- **drawable** est un pointeur vers une structure affichable dans un layer
- **type** est une valeur représentant la structure drawable. Voir l'énumération *draw_type_t* dans *draw.h*.
- **data** est un pointeur vers une data structure.
- **id** est un entier qui identifie le draw vis à vis des sprites du background. Si le draw n'est pas lié au background l'id est -1.
- **show** est un bouléen qui indique si l'asset doit être affiché sur le layer lors du rafraîchissement de l'image.
- **next** & **previous** sont des pointeurs vers les autres assets.
### Creation
Pour créer un draw il faut utiliser la fonction suivante :
```c
draw_t * create_draw(void * drawable, draw_type_t type, data_t * data);
```
- **drawable** est un pointeur vers une structure préinitialisée d'un asset.
- **type** est une valeur qui représente la structure drawable.
- **data** est un pointeur vers une data structure préinitialisée.

### Manipulation
Vous pouvez effectuer toutes les manipulations nécessaires sur votre asset depuis la draw structure sauf la création du drawable.
Il y a 8 d'interactions avec une draw structure :
- **set_data** : établir la position, la taille et la rotation
```c
void set_pos_draw(draw_t * draw, sfVector3f position);
void set_size_draw(draw_t * draw, sfVector2f size);
void set_angle_draw(draw_t * draw, float angle);
void set_data_draw(draw_t * draw, data_t * data);
```
- **set_attributes** : *(uniquement pour un draw de type shape ou text)* pour changer la couleur intérieure, extérieure et la largeur du contour.
```c
void set_color_in_draw(draw_t * draw, sfColor color);
void set_color_out_draw(draw_t * draw, sfColor color);
void set_thick_draw(draw_t * draw, int thick);
void set_attributes_draw(draw_t * draw, sfColor color_in, sfColor color_out, int thick);
```
- **modify** : applique une modification relative à l'état actuel du draw. Les modifications possibles sont déplacer, redimensionner et tourner.
```c
void move_draw(draw_t * draw, sfVector2f offset);
void scale_draw(draw_t * draw, sfVector2f scale);
void rotate_draw(draw_t * draw, float angle);
void modify_draw(draw_t * draw, sfVector2f offset, sfVector2f scale, float angle);
```
- **get_data** : fonctions pour récupérer des informations sur l'état actuel du draw.
```c
sfVector2f get_position_draw(draw_t * draw);
float get_rotation_draw(draw_t * draw);
sfVector2f get_scale_draw(draw_t * draw);
sfVector2f get_origin_draw(draw_t * draw);
```
- **get_bounds** : fonction pour récupérer les limites que forme le draw.
```c
sfFloatRect get_local_bounds_draw(draw_t * draw);
sfFloatRect get_global_bounds_draw(draw_t * draw);
```
- **set_string** : *(uniquement pour un draw de type text)* change la chaîne de caractère affichée avec le draw.
```c
void set_string_draw(draw_t * draw, const char * string);
```
- **set_animation** : *(uniquement pour un draw de type sprite)* active l'animation du draw.
```c
void set_animation_draw(draw_t * draw, int nb_frame);
```
- **set_origin** : change le point de référence du draw.
```c
void set_origin_draw(draw_t * draw, sfVector2f origin);
```

### Displaying
Vous n'aurez pas à gérer vous même l'affichage de draw. En cas de besoin, voir dans le header *draw.h* la fonction *draw_draws*.
### Destruction
Vous n'aurez pas à gérer vous même le free de draw. En cas de besoin, voir dans le header *draw.h* la fonction *free_draws*.

## Data
La structure data est une structure de donnée manipulable pour intéragir avec une draw structure sans manipuler le draw lui-même.
### What is it
Voici un schéma des données stockées dans la structure :
```mermaid
  graph TD;
    A[data] --> B[position];
    A --> C[size];
    A --> D[angle];
    A --> E[depth];
```
- position est un vecteur à trois dimensions qui représente la position dans l'espace.
- size est un vecteur à deux dimensions qui représente la taille du draw.
- angle est un nombre qui représente la rotation du draw.
- depth est un score calculé à partir de la position pour déterminer à quelle profondeur se trouve le draw par rapport aux autres.
### Creation
Pour créer une data structure il faut utiliser la fonction suivante :
```c
data_t * create_data(sfVector3f position, sfVector2f size, float angle);
```
- position est un vecteur à trois dimensions.
- size est un vecteur à deux dimensions.
- angle est un nombre décimal.
### Destruction
Vous n'aurez pas à gérer vous même le free de data. En cas de besoin, voir dans le header *data.h* la fonction *free_data*.

## Shape
Une shape est une structure qui représente une forme rectangulaire ou circulaire.
### What is it
Voici les éléments qui compose une shape structure (ne pas oublier qu'une partie de l'information est stocké dans la structure draw parent) :
```mermaid
  graph TD;
    A[shape] --> B[shape];
    A --> C[type];
    A --> D[color in];
    A --> E[color out];
    A --> F[thick];
```
- **shape** est un pointeur vers la SFML structure correspondante entre sfCircle et sfRectangle.
- **type** est une valeur qui représente si la shape est un rectangle ou un cercle (voir énumération *shape_type_t* dans *shape.h*).
- **color_in** est la couleur qui remplira l'intérieur de la forme.
- **color_out** est la couleur qui remplira le contour de la forme.
- **thick** est un nombre qui représente l'épaisseur du contour de la forme.
### Creation
Une shape est créée avec la fonction suivante :
```c
shape_t * create_shape(shape_type_t type, sfColor color_in, sfColor color_out, int thick);
```
- **type** spécifie si c'est un rectangle ou un cercle.
- **color_in** & **color_out** sont des sfColor qui composeront la shape.
- **thick** détermine l'épaisseur du contour de la shape.
### Displaying
Vous n'aurez pas à gérer vous même l'affichage de shape. En cas de besoin, voir dans le header *shape.h* la fonction *draw_shape*.
### Destruction
Vous n'aurez pas à gérer vous même le free de shape. En cas de besoin, voir dans le header *shape.h* la fonction *free_shape*.

## Sprite
Un sprite est une structure qui permet de manipuler une image. Cette image peut être animée à l'aide d'une spritesheet.
### What is it
Voici un schéma qui représente l'architecture d'une structure sprite :
```mermaid
  graph TD;
    A[sprite] --> B[texture];
    A --> C[sprite];
    A --> D[rectangle rect];
    A --> E[animated];
    A --> F[nb frame];
    A --> G[current];
```
- **texture** est une SFML structure qui représente l'image qui sera manipulée.
- **sprite** est une SFML structure qui permet d'afficher et manipuler la texture.
- **rect** est un rectangle qui représente quelle zone de la texture sera prise en compte (notamment pour l'utilisation de spritesheet).
- **animated** est un bouléen qui indique si le sprite est animé ou non.
- **nb_frame** est un nombre qui indique le nombre d'images qui composent l'animation du sprite.
- **current** est un nombre qui indique à quelle étape de l'animation le sprite se trouve.
### Creation
Un sprite se crée en plusieurs étapes. En premier il faut l'initialiser vierge avec la fonction suivante :
```c
sprite_t * init_sprite(void);
```
Ensuite il faut lier le sprite avec une texture préinitialisée avec la fonction suivante :
```c
void set_texture_sprite(sprite_t * sprite, sfTexture * texture, sfIntRect rect);
```
Si le sprite est animé, on active l'animation avec la fonction suivante :
```c
void set_animation_sprite(sprite_t * sprite, int nb_frame);
```
**Attention :** pour que l'animation puisse être automatisé, il faut que les différentes frames de l'animation se suivent sur la spritesheet sur la même ligne horizontale sans espace entre les frames. Il faut aussi que chaque frame ai les mêmes dimensions.
### Displaying
Vous n'aurez pas à gérer vous même l'affichage de sprite. En cas de besoin, voir dans le header *sprite.h* la fonction *draw_sprite*.
### Destruction
Vous n'aurez pas à gérer vous même le free de sprite. En cas de besoin, voir dans le header *sprite.h* la fonction *free_sprite*.

## Text
Un text est une structure qui permet d'afficher une chaîne de caractères.
### What is it
Voici les éléments qui compose une text structure (ne pas oublier qu'une partie de l'information est stocké dans la structure draw parent) :
```mermaid
  graph TD;
    A[text] --> B[text];
    A --> C[string];
    A --> D[font];
    A --> E[color in];
    A --> F[color out];
    A --> G[thick]
```
- **text** est un pointeur vers la SFML structure qui permet de manipuler du texte.
- **string** est la chaîne de caractère lié à la structure.
- **font** est un pointeur vers la SFML structure qui correspond à une police de caractère. La police par défaut est Arial.
- **color_in** est la couleur qui remplira l'intérieur du texte.
- **color_out** est la couleur qui remplira le contour du texte.
- **thick** est un nombre qui représente l'épaisseur du contour du texte.
### Creation
Un text est créé avec la fonction suivante :
```c
text_t * create_text(const char * string, sfFont * font, sfColor color);
```
- **string** est une chaîne de caractères.
- **font** est une police de caractère en sfFont. Si on ne veut pas spécifier de police on peut donner NULL et la police sera Arial par défaut.
- **color** détermine une couleur unie pour le texte.
### Displaying
Vous n'aurez pas à gérer vous même l'affichage de shape. En cas de besoin, voir dans le header *text.h* la fonction *draw_text*.
### Destruction
Vous n'aurez pas à gérer vous même le free de shape. En cas de besoin, voir dans le header *text.h* la fonction *free_text*.

## Vector & Rectangle functions
Pour initialiser des vecteur vous pouvez utiliser les fonctions suivantes :
```c
sfVector2f set_2vector(float x, float y);
sfVector3f set_3vector(float x, float y, float z);
```
Pour plus de fonctions de manipulation de vecteur se référer à *vector.h*.
Pour initialiser un rectangle vous pouvez utiliser la fonction suivante :
```c
sfIntRect set_rectangle(int left, int top, int width, int height);
```
# Global Architecture
Voici un schéma qui résume l'architecture globale de la lib :
```mermaid
  graph TD;
    A[window] --> B[SFML window structure];
    A --> C[size vecteur];
    A --> D[SFML view];
    A --> E[background layer];
    A --> F[core layer];
    A --> G[fx layer];
    A --> H[ui layer];
    A --> I[splash layer];
    E --next--> F;
    F --next--> G;
    G --next--> H;
    H --next--> I;
    E --> J[layer];
    F --> J;
    G --> J;
    H --> J;
    I --> J;
    J --> K[type];
    J --> L[render texture];
    J --> M[sprite];
    J --> N[size vecteur];
    J --> O[draw list];
    J --> P[show];
    J --> Q[next & previous];
    O --> R[draw];
    R --> S[drawable];
    R --> T[type];
    R --> U[data structure];
    R --> V[id];
    R --> W[show];
    R --> X[next & previous];
    U --> Y[data];
    Y --> Z[position];
    Y --> AA[size];
    Y --> AB[angle];
    Y --> AC[depth];
    S --> AD[sprite]
    AD --> AE[texture];
    AD --> AF[sprite];
    AD --> AG[rectangle rect];
    AD --> AH[animated];
    AD --> AI[nb frame];
    AD --> AJ[current];
    S --> AK[shape];
    AK --> AL[shape];
    AK --> AM[type];
    AK --> AN[color in];
    AK --> AO[color out];
    AK --> AP[thick];
    S --> AQ[text];
    AQ --> AR[string];
    AQ --> AS[font];
    AQ --> AT[color in];
    AQ --> AU[color out];
    AQ --> AV[thick]
```
