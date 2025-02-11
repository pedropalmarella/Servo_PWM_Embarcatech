# Controle de Servomotor com PWM no RP2040

Este projeto utiliza o microcontrolador **RP2040** para controlar um **servomotor** via **PWM**, permitindo movimentá-lo entre **0 e 180 graus** de forma precisa. Além disso, uma rotina periódica foi implementada para uma movimentação suave entre os ângulos extremos.

## Funcionalidades Implementadas

### Definição da Frequência do PWM
- O PWM é configurado para **50Hz** (período de 20ms), adequado para controle de servomotores.
- O **divisor de clock do PWM** foi definido como **125.0**, garantindo um funcionamento estável.

### Controle de Posições do Servomotor
- **180 graus** → Ciclo ativo de **2.400µs** (0,12% Duty Cycle).
- **90 graus** → Ciclo ativo de **1.470µs** (0,0735% Duty Cycle).
- **0 graus** → Ciclo ativo de **500µs** (0,025% Duty Cycle).
- Em cada posição, o servomotor aguarda **5 segundos** antes de avançar para a próxima.

### Movimentação Suave
- Após atingir cada posição predefinida, o sistema inicia um **ciclo de movimentação contínua**.
- A movimentação entre **0 e 180 graus** ocorre suavemente, com **incrementos de 5µs** no ciclo ativo e um **atraso de 10ms** entre cada incremento.
- A rotina de movimentação é implementada na função `ciclo_servo()`, garantindo transições suaves e controladas.

### Integração com LED RGB (GPIO 12)
- O comportamento do **LED RGB** é monitorado durante a execução do código.
- O LED **reproduz a mesma movimentação do servomotor**, alterando seu brilho proporcionalmente.
- A função `experimento_led()` aplica a mesma lógica do PWM ao LED.

## Estrutura do Código

O código é modularizado nos seguintes arquivos:

- **`pwm_serv.c`**: Função principal que configura o PWM e executa a movimentação do servomotor e LED.
- **`servo.h`**: Definições das funções responsáveis pelo controle do servomotor e LED.
- **Principais funções:**
  - `setup_pwm(pino)`: Configura o PWM para o pino desejado.
  - `movimento_inicial(pino)`: Realiza os movimentos iniciais do servo.
  - `ciclo_servo(pino)`: Implementa a movimentação periódica suave.
  - `experimento_led(pino)`: Aplica a lógica do PWM ao LED RGB.

## Tecnologias Utilizadas

- **Microcontrolador**: Raspberry Pi Pico (RP2040)
- **Linguagem de Programação**: C (usando o **Pico SDK**)
- **Ambiente de Desenvolvimento**: Visual Studio Code (VSCode) com Pico SDK
- **Simulador Wokwi**
- **Hardware**:
  - **Servomotor**
  - **LED RGB (GPIO 12)**

## Como Usar

1. **Simulação no Wokwi**:
   - O projeto foi testado e validado no simulador **Wokwi**.
   - O código pode ser carregado no Wokwi para testar o comportamento do PWM e do servomotor virtualmente.
   - As configurações de hardware estão descritas no arquivo **diagram.json**.

2. **Monitorar o funcionamento**:
   - O servomotor se movimentará entre **0°, 90° e 180°**.
   - Após essa sequência, ele iniciará a movimentação suave entre os ângulos.
   - O LED RGB no **GPIO 12** pode apresentar variações de brilho conforme o comportamento do PWM.
