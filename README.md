MOBIT - Projetista de Sistemas Embarcados
==============================================================

# Resumo
Repositório criado para resolução de questões para a vaga de Projetista de Sistemas Embarcados.

Tecnologias:
*   Virtual BOX
*   Linux Ubuntu 18.04 ou compatível;
*   Linguagem Shell Script;
*   Linguagem C (gcc 7.4.0 );
*	Linguagem C\+\+17 (g++ 7.4.0);
*	GIT;
*   Codeblock;
*   Makefile.

# Candidato:
###### JOSE DE ARIMATEIA CARVALHO SILVA JUNIOR

### Email para contato: 
#### juniorcs09@gmail.com
---------
# Questões:
## Q_01:
A questão 01 tem como principal objetivo monitorar dados dos sistema e alertar via email ao usuário pre-selecionado, bem como, criar log para cada um dos alertas. Os dados dos sistemas a serem monitorados foram: capacidade do disco, memória e temperatura. Além disso, foi necessário colocar tal script de modo automático no crontab (gerenciador de atividades do linux), para isso, outro script foi criado. Como não houve exigencia de periodicidade na questão foi colocado a periodicidade diária às 23h.

## Q_02:
A questão 2 tem como principal objetivo corrigir um problema de concorrencia de threads, para isso foi utilizado o mutex. Poderíamos usar outras ferramentas, como por exemplo o pthread, porém como o código principal já havia sido feito optei por usar, simplemente, o controle de zona crítica. Além disso, também foi necessario a criaçao de um makefile, que por tratar-se apenas de um arquivo optei por fazer de modo direto, sem a necessidade de variáveis ou funçoes associadas.

## Q_03:
A questão 3 tem como objetivo principal criar thread concorrente, tais threads tem seus insumos oriundos de um aquivo xml, que foi lido através da lib RapidXML, para o problema de concorrencia de thread foi utilizada a pthread. 
    

## Q_4:
A questão 4 tem como objetivo principal realizar e leitura de uma imagem, ao mesmo tempo que gerencia processo, semelhante ao que é realizado com radares de velocidade. 


## Como utilizar:

## Questão 01:
o script "puro" tem a nomeclatura Q1 (referente a questão 01) para roda-lo basta que no terminal se execute o comando 

      $ ./Q1 

É necessário que tenha a permissão de execução, um modo bem simples de fazer isso é no terminal fazer o seguinte:

     $ sudo chmod 777 Q1

Para instalar o script no crontab apenas excute o comando, mais uma vez é necessário a permissão de execução, siga o passo anterior modificando o nome do arquivo.

    $ ./conf_crontab

## Questão 02:
como pedido na questão execute execute o comando make, assim, automaticamente o pacote encontrará o aquivo makefile. O comando make deve ser colocado do seguinte modo

    $ make

Em seguida, para executar o programa:

    $ ./q2_exe

Para fazer a exclusão, basta usar o seguinte comando:

    $ make clean

## Questão 03: 
Gerencia de threads em C++ (Produtor-Consumidor). Execute o seguinte comando no terminal.É importante salientar que embora use um lib externa a mesma não precisa ser compilada, visto que, apresenta apenas um arquivo .hpp. Desse modo é importante apenas que a mesma seja visível ao projeto original.

    $ ./q3

    
## Questão 4. 

---------

