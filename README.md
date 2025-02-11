# Controle de Servomotor com PWM no RP2040

Este projeto utiliza o microcontrolador **RP2040** para controlar um **servomotor** via **PWM**, permitindo movimentá-lo entre **0 e 180 graus** de forma precisa. Além disso, uma rotina periódica foi implementada para uma movimentação suave entre os ângulos extremos.

## Funcionalidades Implementadas

### Definição da Frequência do PWM
- O PWM é configurado para **50Hz** (período de 20ms), adequado para controle de servomotores.

### Controle de Posições do Servomotor
- **180 graus** → Ciclo ativo de **2.400µs** (0,12% Duty Cycle).
- **90 graus** → Ciclo ativo de **1.470µs** (0,0735% Duty Cycle).
- **0 graus** → Ciclo ativo de **500µs** (0,025% Duty Cycle).
- Em cada posição, o servomotor aguarda **5 segundos** antes de avançar para a próxima.

### Movimentação Suave
- Após atingir cada posição predefinida, o sistema inicia um ciclo de movimentação periódica.
- A movimentação entre **0 e 180 graus** ocorre suavemente, com **incrementos de 5µs** no ciclo ativo e um **atraso de 10ms** entre cada incremento.

### Integração com LED RGB (GPIO 12)
- O comportamento do LED RGB é monitorado durante a execução do código para avaliar possíveis efeitos da operação do PWM no GPIO.

## Tecnologias Utilizadas

- **Microcontrolador**: Raspberry Pi Pico (RP2040)
- **Linguagem de Programação**: C (usando o **Pico SDK**)
- **Ambiente de Desenvolvimento**: Visual Studio Code (VSCode) com Pico SDK
- **Hardware**:
  - **Servomotor**
  - **LED RGB (GPIO 12)**
  - **Simulador Wokwi**

## Como Usar

1. **Simulação no Wokwi**:
   - O projeto foi testado e validado no simulador **Wokwi**.
   - O código pode ser carregado no Wokwi para testar o comportamento do PWM e do servomotor virtualmente.

2. **Monitorar o funcionamento**:
   - O servomotor se movimentará entre 0°, 90° e 180°.
   - Após essa sequência, ele iniciará a movimentação suave entre os ângulos.
   - O LED RGB no **GPIO 12** pode apresentar variações dependendo do comportamento do PWM.

## Observações
- A movimentação do servomotor deve ocorrer de maneira **precisa e suave**.
- Possíveis interferências no LED RGB devem ser analisadas para entender sua relação com o PWM.

---
Este projeto demonstra o controle preciso de **servomotores com PWM no RP2040**, além de explorar possíveis interações com **outros periféricos**, como o **LED RGB**.

