# ☀️ Sun Tracker: Rastreador Solar Automático

Este projeto consiste na simulação de um sistema de rastreamento solar de eixo único (Single Axis Solar Tracker) utilizando **Arduino Uno**. O objetivo é simular o comportamento de uma placa fotovoltaica que se move autonomamente para ficar sempre perpendicular à fonte de luz, maximizando a eficiência energética.

## ⚙️ Funcionalidades

- **Rastreamento em Tempo Real:** O sistema lê dois sensores de luz (LDRs) continuamente.
- **Comparador Lógico:** O algoritmo calcula a diferença de luminosidade entre o lado esquerdo e direito.
- **Controle de Histerese:** Implementação de uma margem de tolerância para evitar que o motor fique "tremendo" (jitter) com pequenas variações de luz.
- **Proteção de Limites:** O servo motor é limitado via software para operar apenas entre 0° e 180°.

## 🛠️ Componentes Utilizados (Simulação)

- 1x Arduino Uno R3
- 1x Micro Servo Motor (simulando o atuador da placa)
- 2x Sensores LDR (Light Dependent Resistor)
- 2x Resistores de 10kΩ (Configuração Pull-down / Divisor de Tensão)
- Protoboard e Jumpers

## 📐 Lógica do Circuito

Os sensores LDR estão configurados em um **Divisor de Tensão** com resistores de 10kΩ.
- **Mais Luz** = Menor resistência no LDR = Maior tensão na porta analógica (A0/A1).
- **Menos Luz** = Maior resistência no LDR = Menor tensão.

O Arduino lê essas tensões, compara os valores e decide para qual lado girar o servo motor.

## 🖥️ Simulação Online

Este projeto foi desenvolvido e testado no simulador **Tinkercad**.
Você pode visualizar o circuito e testar o código diretamente no navegador:

🔗 **[CLIQUE AQUI PARA VER A SIMULAÇÃO] (Coloque_Seu_Link_do_Tinkercad_Aqui)**

*(Dica: Ao abrir a simulação, clique nos LDRs para ajustar a intensidade da luz e ver o motor se movendo)*

## 🔧 Como Reproduzir

1. Clone o repositório:
   ```bash
   git clone https://github.com/thaynaraamorim00-star/Rastreador-Solar.git