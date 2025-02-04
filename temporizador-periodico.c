#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_VERMELHO 11
#define LED_AMARELO 12
#define LED_VERDE 13

#define PERIODO_MS 3000  // Tempo de troca do semáforo (3s)

// Enum para representar os estados do semáforo
typedef enum {
    VERMELHO,
    AMARELO,
    VERDE
} EstadoSemaforo;

EstadoSemaforo estado_atual = VERMELHO;  // Começa no vermelho

// Protótipos das funções
void inicializar_leds();
void desligar_leds();
bool trocar_semaforo_callback(struct repeating_timer *t);

int main() {
    stdio_init_all();

    // Inicializa os LEDs
    inicializar_leds();

    // Liga o LED vermelho inicialmente
    gpio_put(LED_VERMELHO, 1);
    printf("Semáforo inicializado: Vermelho\n");

    // Configura o temporizador repetitivo para trocar o semáforo a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(PERIODO_MS, trocar_semaforo_callback, NULL, &timer);

    // Loop principal - imprime mensagens na serial a cada 1s
    while (true) {
        printf("Sistema rodando... Tempo atual: %d ms\n", to_ms_since_boot(get_absolute_time()));
        sleep_ms(1000);
    }

    return 0;
}

// Função para inicializar os LEDs
void inicializar_leds() {
    int leds[] = {LED_VERMELHO, LED_AMARELO, LED_VERDE};

    for (int i = 0; i < 3; i++) {
        gpio_init(leds[i]);
        gpio_set_dir(leds[i], GPIO_OUT);
    }
}

// Função para desligar todos os LEDs
void desligar_leds() {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
}

// Função de callback do temporizador
bool trocar_semaforo_callback(struct repeating_timer *t) {
    // Desliga os LEDs antes de mudar de estado
    desligar_leds();

    // Define a nova cor e imprime mensagem
    const char *cor;

    switch (estado_atual) {
        case VERMELHO:
            gpio_put(LED_AMARELO, 1);  // Muda para amarelo
            estado_atual = AMARELO;
            cor = "Amarelo";
            break;
        case AMARELO:
            gpio_put(LED_VERDE, 1);  // Muda para verde
            estado_atual = VERDE;
            cor = "Verde";
            break;
        case VERDE:
            gpio_put(LED_VERMELHO, 1);  // Muda para vermelho
            estado_atual = VERMELHO;
            cor = "Vermelho";
            break;
    }

    printf("Semáforo mudou para: %s\n", cor);
    return true; // Mantém o temporizador ativo
}