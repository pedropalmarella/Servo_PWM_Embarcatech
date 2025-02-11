#include <stdio.h>
#include "pico/stdlib.h"
#include "servo.h"

int main()
{
    setup_pwm(SERVO); // Configura o PWM para o SERVO

    while (true)
    {
        movimento_inicial(SERVO); // Efetua os 3 movimentos iniciais do SERVO com seus devidos delays
        ciclo_servo(SERVO);
        sleep_ms(1000);
        experimento_led(LED); // Chama a função de experimento para o LED, aplica a mesma lógica, alterando o PINO
    }
}
