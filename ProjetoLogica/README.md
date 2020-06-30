# ProjetoLogica

O projeto é um resolvedor de instâncias do problema SAT. O programa recebe expressões bem-formadas da lógica proposicional e retorna a solução do problema. O programa soluciona as instâncias a partir do Método da Resolução.

Método da resolução

O método consiste em aplicar sucessivamente a seguinte equivalência lógica:

    (XvY) ∧ (¬YvZ) ≡ (XvY) ∧ (¬YvZ) ∧ (XvZ)

Ou seja, procuramos encontrar literais ditos complementares em cláusulas distintas e criar uma nova cláusula com os literais restantes. Se, ao fazermos esse processo, encontrarmos a cláusula vazia (sem literais), a fórmula é insatisfatível.

Nesse projeto, só serão aceitas expressões que contenham apenas cláusulas de Horn. Caso seja dada uma expressão que não esteja no FNC, o programa retornará "Não está na FNC"; caso esteja, mas não tenha apenas cláusulas de Horn, o programa retornará "Nem todas as cláusulas são de Horn"; por fim, caso esteja no FNC e contenha apenas clausulas de Horn, será dito se é ou não satisfatível.

Para resolver a satisfabilidade, foi usado o processo de propagação unitária. E caso a expressão não tenha nenhum literal, será satisfatível. Isso é garantido pelo lema que diz:
                                  
    Seja uma fórmula ϕ ∈ PROP na FNC. Se ϕ não tem cláusulas unitárias, então ϕ é satisfatível
    
Para saber mais sobre propagação unitária ler: https://en.wikipedia.org/wiki/Unit_propagation 

Sintaxe da entrada:

● Operadores: cada entrada será composta por 5 operadores. Seus símbolos usados estão listados abaixo.

○ ~ | Negação

○ v | Disjunção

○ & | Conjunção

○ > | Implicação

○ < | Equivalência (bi-implicação)

● Variáveis: a entrada terá no máximo 4 variáveis - P, Q, R e S.

● Parênteses:
○ Todas as cláusulas estão envoltas em parênteses, até mesmo as unitárias.

