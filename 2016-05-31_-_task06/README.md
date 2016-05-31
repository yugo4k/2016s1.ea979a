##### 2016s1 - EA979a
##### 033324 - Yugo Kuno
#### Atividade 06: CG/introdução ao opengl

---

### Funcionamento do programa

- Inicializa o GLUT, configura janela, etc.
- Configura a visualização correta de objetos conforme profundidade no campo de visão.
- Define parâmetros iniciais de perspectiva.
- Define a _display callback function_:
  - Configura a perspectiva.
  - Limpa o frame anterior com novo _background_.
  - Desenha as cinco esferas, para cada uma:
    - Adiciona matriz para posição da esfera.
    - Rotaciona e translada a matriz conforme desejado.
    - Desenha _WireSphere_ ou _SolidSphere_ conforme desejado.
    - Remove matriz de posição não mais necessária.
  - Manda o buffer criada para ser mostrado na janela.
- Define a _reshape callback function_:
