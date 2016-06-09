##### 2016s1 - EA979a
##### 033324 - Yugo Kuno
#### Atividade 07

---

### `minimal_exe6`

- A _global struct variable_ `perspective` foi criada para manter as variáveis de perspectiva do programa.
- A função `reset` foi criada para reiniciar a perspectiva.
- A função `reshape` foi alterada para atender os requisitos do enunciado.
- A função `keyboard` foi alterada para que a interface recebesse novos comandos que atendem o enunciado.
- A função `reshape` foi chamada no final da função `keyboard` uma vez que o que se pede no enunciado não poderia ser mostrado a não ser que a janela fosse redimensionada, o que é impraticável. Desta forma é possível atender o que se pede no enunciado e permitir as alterações de perspectiva pedidas interativamente.


#### Lista de comandos

- Os inputs `t` e `T` rotacionam o ponto de perspectiva mudando o ângulo zenital em torno do centro, respectivamente aumentando e diminuindo o ângulo.
- `p` e `P` fazem o mesmo acima para o ângulo azimutal.
- `v` e `V` mudam o _field of view_, respectivamente aumentando e diminuindo seu ângulo.
- `a` e `A` mudam o _aspect ratio width over height_, respectivamente aumentando e diminuindo seu valor.
- `x`, `y` e `z` deslocam o ponto e o centro da perspectiva simultanemante nos respectivos eixos; `X`, `Y` e `Z` fazem os deslocamentos inversos respectivos.
- `+` aproxima a cena, `-` afasta.
- `r` reinicializa a cena para a configuração original.
- `c` e `C` continuam realizando a operação original do algoritmo recebido.
