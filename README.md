# AES-e-derivado
Implementação em C do algoritmo de criptografia simétrica AES e o algoritmo A²ES derivado do AES.

# Compilação
Para compilação do algoritmo, é funcional o gcc a partir da versão 4.8.4. Deve ser usado comando:
```
make
```

# Rodando
Para rodar o algoritmo deve-se seguir o formato de linha de comando:
```
./A2ES.out ALG OP KEY IN OUT
```
Em que ALG é o algoritmo que será usado para encriptação ou decriptação. ALG = 1 é o AES e ALG = 2 é o A²ES.

OP é o modo de operação do algoritmo, em que OP = C é usado para encriptação e OP = D para decriptação.

KEY é o caminho para o arquivo que contem a chave.

IN é o caminho para o arquivo de entrada (que será encriptado ou decriptado).

OUT é o caminho para o arquivo de saída.


# Exemplo de comando:
```
./A2ES.out 2 C Tests/A2ES.key Tests/test.in Tests/test.out
```
No exemplo acima o arquivo test.in é encriptado pelo algoritmo A²ES usando a chave contida em A2ES.key e o resultado é armazenado no arquivo test.out.
