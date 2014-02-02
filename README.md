ComputacaoBasica
================

Código com implementações para a disciplina 
[CIC-116301 Computação Básica](https://matriculaweb.unb.br/matriculaweb/graduacao/disciplina.aspx?cod=116301). 
Os arquivos são feitos para funcionar em ambiente Unix, com o compilador 
[gcc](http://gcc.gnu.org/).

### Uso

Os arquivos são feitos para exemplificar certos conceitos, facilmente identificados 
pelo nome do artigo. O código segue o [padrão
ANSI](http://pt.wikipedia.org/wiki/Biblioteca_padr%C3%A3o_do_C#Padr.C3.A3o_ANSI), 
e pode ser compilado com o seguinte comando:

<code>gcc -Wall -ansi codigo_fonte.c -o nome_executavel</code>

Por exemplo:
<code>gcc -Wall -ansi ola_turma.c -o oi</code>

### Erros

Em caso de erro, lembre-se que a [internet](www.google.com.br) é sua amiga, basta
procurar um pouco. Se não houver jeito, entre em contato com o responsável pelo
projeto. Segue a lista de erros mais comuns (em função de como este projeto é
organizado).

#### fatal error

Caso o compilador não encontre o arquivo <code>utils_impl.h</code>, basta 
remover/comentar a linha que o inclui (ao final do arquivo <code>utils.h</code>).

#### error: ‘EXIT_FAILURE’ undeclared 

A constante não foi declarada (é só incluir o arquivo <code>stdlib.h</code>).

#### undefined reference to `nome_da_funcao'

A função é chamada mas não foi definida. Se for uma das funções declaradas em
<code>utils.h</code>, você deve implementá-la por conta própria. Se for uma 
função definida em outro lugar, é possível que você tenha esquecido de incluir o
arquivo <i>header</i> (ex: stdlib.h para a função <code>malloc</code>). 