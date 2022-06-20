# Sistemas Operativos TP3

## Estructura del Proyecto
Todo el codigo se encuentra en la carpeta src.
Dentro de src se pueden ver las siguientes carpetas:
* `server`: Contiene el codigo principal del server. Ya sean las preguntas, respuestas y el loop principal de preguntas.
* `runme`: Un programa simple que solo imprime por pantalla un string. Forma parte de un easter egg.
* `lib`: Contiene codigo que se utiliza desde `server` y desde `runme`. Principalmente desencriptar strings.
* `interactor`: Codigo para interactuar con el `server` mediante sockets.

## Build
Correr `./dcom make` para buildear el server y el interactor.

Los ejecutables se crean en el root del proyecto, y se llaman `./server` e `./interactor`.

## Preprocesador

Para encriptar strings y calcular md5, decidimos crear un preprocesador que se ejecute previo a la etapa de compilación.
Decidimos hacerlo en python para un manejo de strings mas facil.
Este script lo llamamos `string_encryptor.sh` y se ejecuta automaticamente al hacer make.

El funcionamiento es simple; busca en el codigo los strings encerrados en `ENCRIPTED("")` o `MD5SUM("")` y los reemplaza por el string encriptado o el hash md5 del string, respectivamente.
Como la deteccion de estas sentencias esta hecha con una expresion regular, no es perfecta, pero detecta los casos mas comunes y es suficiente para este programa.

## Easter Eggs encontrados (y como reproducirlos)

Para poder reproducirlos se debe usar el programa `server` provisto por la catedra, ya que algunos valores (como posiciones dentro del binario) pueden cambiar.

### Vaca

Al ver los strings del programa, se pueden ver una serie de strings que forman un ascii art de una vaca generada con `cowsay ESTO ES UN EASTER_EGG`.

```
> strings server | tail +95 | head -n8
 _______________________
< ESTO ES UN EASTER_EGG >
 -----------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

### Valgrind

Originalmente encontramos el easter egg listando los simbolos del programa `server` con el comando `nm server` y viendo que algunos simbolos tenian una forma un poco peculiar.
Al analizarlos un poco encontramos que el mensaje es "VALGRIND ES GENIAL" y esta escrito verticalmente sobre los nombres.

```
> nm server -nj | egrep '[A-Z_]_[A-Z_]$'
V_E
A_S
L__
G_G
R_E
I_N
N_I
D_A
__L
```

Luego, decidimos ejecutar el programa mediante valgrind para obtener el easter egg de la manera intencionada.

```
> valgrind ./server
```

Y en la pregunta N°3 se realiza un salto que depende de una variable no inicalizada.

### Ejecutar sección .RUN_ME

Luego de ver que la sección .RUN_ME empieza con el header típico de los archivos ELF, lo extraemos a su archivo propio y lo ejecutamos.

```
> objdump --headers server
> dd skip=13784 count=9712 if=server of=extracted bs=1
> ./extracted
Estoy muy orgulloso de que hayan logrado esto. Les espera un premio especial.
```

### /tmp/hidden

Cuando el programa `server` termina, este crea un archivo llamado /tmp/hidden que contiene la cadena "QUE CURIOSO"

```
> cat /tmp/hidden
QUE CURIOSO
```
