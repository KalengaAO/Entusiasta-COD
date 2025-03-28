******************************************************
SAUDAÇÕES E AGRADECIMENTO PARA TODOS QUE AQUI CHEGARAM 
******************************************************

# A ideia é simples: Monitorar o sistema.

A descrição vai ser detalhada para as partes essências \
do script neste caso as duas primeiras variáveis são \
descartadas o mesmo vale para o comando echo e todas linhas.

------------------------------------------------------------ 
Atendo o uso do sistema basta alterar os valores na variáveis \
CPU e MEM para controlar o limite
------------------------------------------------------------

### loop infinito  
while true; do
### capturando uma vez os processo 
top -bn1 
### capturando a primeira referência de CPU na lista de processos  
grep "CPU" | head n1
### manipulando os dados para imprimir em ponto flutuante 
sed '/s/,/.g'
### imprimindo os dados de consumo da CPU 
// awk'{print "Usuario: " $2"%\tSistema: "$4 "%\t Total: " $2 + $4"%"}'

Nota: é possível que o comando sed em alguns sistema não seja \
necessário se a formatação estiver no formato Americano (ponto decimal).
No meu sistema, os valores estão usando vírgula (9,3) em vez de \
ponto decimal ( 9.3 ) para awk para manipular melhor os valor substitui as \
virgulas por ponto isso permitindo que a soma seja da em ponto flutuante.

### listando processos 
ps -eo user,pid,%cpu,%mem,cmd,comm,start --sort=-%cpu
ps -eo user,pid,%cpu,%mem,cmd,comm,start --sort=-%mem

Nota: Está é a parte fundamental do script, listo os processos com ps
e as flags -e (everyone) lista todos os processos do sistema, incluindo
os de outros usuários, isso da uma vantagem em monitorar o roda em
todo sistema incluindo de outros usuário, a flags -o permite especificar
quais coluna quero capturar, neste caso capturo user,pid,cpu,mem,
cmd(de onde foi inicializado),comm (comando),start(hora, minito e seg que
o processo foi inicializado)

### filtrando só processo com tail
tail -n +2 // captura só processo e não titulos
### filtrando os 20 primeiros processos com head
head -n 20
### loop 
while read -r // le os processo segundo os titulos
### Usando if para monitorar o consumo de mem e cpu
if [[ ]] // penso que ai não tem muito de novidade, com execesão o \
comando bc (base de calculo em bash), porém ele só lida com string \
literal, então uso o comando echo para que os dados das var mem e LIM_MEM \
sejam interpretado como string incluindo operador >, se for verdade retorna \
1, tornando true a condição -eq 1.

**"Exemplo: echo " 5 + 5" | bc -l**
user@user:~/ 10
sem o bc -l a saída séria
user@user:~/ 5 + 5
[comando_legal!]

### Usando janelas pop para imprimir o alerta
notify-send "alerta de consumo de *" // penso que será necessário \
instalar o comando notify-send, permite que o script envie mensagem \
usando janela pop na tela em primeiro plano, se no seu sistema não estiver\
clica no link para ver umas dicas de instalação:

https://www.dicas-l.com.br/arquivo/uma_dica_do_notify-send.php
[não frequento este site, só achei ele explicativo e simples! so take care]









