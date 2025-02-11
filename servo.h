#ifndef SERVO_H
#define SERVO_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

const uint SERVO = 22;         // Pino do SERVO conectado
const uint LED = 12;                 // Pino do LED conectado
#define DIVIDER_PWM 125.0      // Divisor fracional do clock para o PWM
#define DUTY_DELAY_INCIAL 2000 // Delay para os movimentos INICIAIS do SERVO
#define DUTY_DELAY_SUAVE 10    // Delay para o movimento em ciclo do SERVO
const uint16_t PERIOD = 20000; // Período/wrap do PWM (valor máximo do contador)
const uint16_t DUTY_SUAVE = 5; // Incremento/decremento para o duty cycle do SERVO
uint slice;

// Posições do servo
uint16_t duty_cycle_180 = 2400; // 2.400us (180°)
uint16_t duty_cycle_90 = 1470;  // 1.470us (90°)
uint16_t duty_cycle_0 = 500;    // 500us (0°)

void setup_pwm(const uint SERVO)
{
    gpio_set_function(SERVO, GPIO_FUNC_PWM); // Configura o pino do SERVO para função PWM
    slice = pwm_gpio_to_slice_num(SERVO);    // Pega o slice do PWM associado ao pino do SERVO
    pwm_set_clkdiv(slice, DIVIDER_PWM);      // Define o divisor de clock do PWM
    pwm_set_wrap(slice, PERIOD);             // Configura o valor máximo do contador (período/wrap do PWM)
    pwm_set_enabled(slice, true);            // Habilita o PWM no slice correspondente
}

void movimento_inicial(const uint SERVO)
{
    pwm_set_gpio_level(SERVO, duty_cycle_180); // Movimento para 180°
    sleep_ms(DUTY_DELAY_INCIAL);
    pwm_set_gpio_level(SERVO, duty_cycle_90); // Movimento para 90°
    sleep_ms(DUTY_DELAY_INCIAL);
    pwm_set_gpio_level(SERVO, duty_cycle_0); // Movimento para 0°
    sleep_ms(DUTY_DELAY_INCIAL);
}

void ciclo_servo(const uint SERVO)
{
    for (uint16_t duty_cycle = duty_cycle_0; duty_cycle <= duty_cycle_180; duty_cycle += DUTY_SUAVE)
    {
        pwm_set_gpio_level(SERVO, duty_cycle);
        sleep_ms(DUTY_DELAY_SUAVE);
    }

    for (uint16_t duty_cycle = duty_cycle_180; duty_cycle >= duty_cycle_0; duty_cycle -= DUTY_SUAVE)
    {
        pwm_set_gpio_level(SERVO, duty_cycle);
        sleep_ms(DUTY_DELAY_SUAVE);
    }
}

void experimento_led(const uint LED)
{
    setup_pwm(LED);
    movimento_inicial(LED);
    ciclo_servo(LED);
    sleep_ms(1000);
}

#endif