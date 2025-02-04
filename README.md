# 🚦 Semáforo com Temporizador Periódico

Este projeto implementa um **semáforo automatizado** utilizando a placa **Raspberry Pi Pico W** e a biblioteca **Pico SDK**. O sistema controla três LEDs que simulam um semáforo real, alternando entre os estados **vermelho**, **amarelo** e **verde** a cada **3 segundos**.

---

## 🛠 **Requisitos do Projeto**
✅ Utilizar a placa **Raspberry Pi Pico W**  
✅ Controlar **três LEDs** (vermelho, amarelo e verde)  
✅ Implementar um **temporizador repetitivo** usando `add_repeating_timer_ms()`  
✅ O semáforo deve **iniciar no vermelho** e alternar as cores a cada **3 segundos**  
✅ Exibir mensagens no terminal serial para acompanhar a execução  

---

## ⚙ **Componentes e Conexões**
| **Componente** | **Pino GPIO** |
|--------------|------------|
| 🔴 LED Vermelho | GPIO 11 |
| 🟡 LED Amarelo | GPIO 12 |
| 🟢 LED Verde | GPIO 13 |

📌 **Nota:** Os LEDs devem ser conectados em série com **resistores de 330Ω** para limitar a corrente.

---

## 📥 **Como Clonar e Rodar o Projeto**

### 📌 **Passo 1: Clonar o repositório**
Primeiro, faça o **clone do repositório** para a sua máquina local:

```bash
git clone https://github.com/brenotainandev/temporizador-periodico
cd temporizador-periodico
```

---

### 📌 **Passo 2: Configurar o ambiente**
1. **Instale o SDK do Raspberry Pi Pico** seguindo a documentação oficial:  
   🔗 [Guia Oficial do Pico SDK](https://github.com/raspberrypi/pico-sdk)  
2. **Configure seu ambiente** para compilar programas em C para o Raspberry Pi Pico.

---

### 📌 **Passo 3: Compilar o código**
Execute os seguintes comandos para compilar e gerar o binário:

```bash
mkdir build
cd build
cmake ..
make
```

Se a compilação for bem-sucedida, um **arquivo `.uf2`** será gerado dentro do diretório `build/`.

---

### 📌 **Passo 4: Enviar para o Raspberry Pi Pico**
1. Conecte o **Raspberry Pi Pico W** ao computador segurando o botão **BOOTSEL**.  
2. Monte a unidade de armazenamento USB chamada **RPI-RP2**.  
3. Arraste o arquivo **`.uf2`** gerado no diretório `build/` para a unidade **RPI-RP2**.  
4. O microcontrolador será reiniciado automaticamente e o programa começará a rodar. 🚦✨  

---

## 📡 **Saída Esperada no Terminal Serial**
Se conectado via **UART/USB**, o código imprimirá algo como:

```
Semáforo inicializado: Vermelho
Sistema rodando... Tempo atual: 1000 ms
Sistema rodando... Tempo atual: 2000 ms
Semáforo mudou para: Amarelo
Sistema rodando... Tempo atual: 4000 ms
Semáforo mudou para: Verde
Sistema rodando... Tempo atual: 7000 ms
Semáforo mudou para: Vermelho
```
Isso indica que o **ciclo do semáforo está funcionando corretamente**! 🚦🎉

---

## 📝 **Explicação do Código**
1. **Inicializa os LEDs** e define os **pinos GPIO** correspondentes.  
2. Configura um **temporizador repetitivo** que chama a função `trocar_semaforo_callback()`.  
3. A cada 3 segundos (`PERIODO_MS`), a função `trocar_semaforo_callback()` troca a cor do semáforo.  
4. O loop principal apenas imprime **mensagens de status** no terminal serial.  

---

## 🔗 **Referências**
📖 [Raspberry Pi Pico SDK Documentation](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)