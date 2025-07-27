# Cortina Inteligente

Projeto de uma cortina automatizada controlada por um controle remoto infravermelho (IR). Utiliza um motor de passo para abrir e fechar a cortina com precisão.

## ⚙️ Funcionalidades

- Controle total da cortina via controle remoto IR.
- Movimentos pré-definidos (ex: 1 giro, 3 giros).
- Controle de direção (horário e anti-horário) para abrir e fechar.
- Fácil de montar e customizar.

## 🔌 Hardware Necessário

- Placa Arduino (Uno, Nano, etc.)
- Motor de Passo (ex: NEMA 17)
- Driver para Motor de Passo (ex: A4988 ou DRV8825)
- Receptor IR (ex: TSOP38238)
- Controle Remoto IR (qualquer um, os códigos podem ser ajustados)
- Fonte de alimentação externa para o motor (de acordo com a especificação do seu motor)
- Jumpers

## 📚 Bibliotecas (Software)

Este projeto requer a seguinte biblioteca para Arduino:
- [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)

Você pode instalá-la através do Gerenciador de Bibliotecas da Arduino IDE.

## 🛠️ Montagem e Conexões

Conecte os componentes da seguinte forma:

| Componente          | Pino no Arduino |
| :------------------ | :-------------- |
| Receptor IR (Sinal) | Pino Digital 3  |
| Driver Motor (STEP) | Pino Digital 8  |
| Driver Motor (DIR)  | Pino Digital 9  |

### Diagrama de Alimentação

- **Receptor IR**: Conecte o `VCC` e `GND` do receptor aos pinos `5V` e `GND` do Arduino.
- **Driver do Motor**:
  - Conecte a alimentação do motor (`VMOT` e `GND`) à sua fonte de alimentação externa. **⚠️ Não alimente o motor diretamente pelo Arduino.**
  - Conecte o `GND` da fonte do motor ao `GND` do Arduino para ter uma referência de terra comum.
  - Conecte o `VDD` (lógica) do driver ao pino `5V` ou `3.3V` do Arduino (verifique a especificação do seu driver).

## 🚀 Instalação

1.  Instale a Arduino IDE.
2.  Instale a biblioteca `IRremote` (veja a seção de Bibliotecas acima).
3.  Conecte os componentes como descrito na seção de montagem.
4.  Abra o arquivo `cortinaInteligente.c++` (ou renomeie para `cortinaInteligente.ino`) na Arduino IDE.
5.  Faça o upload do código para a sua placa Arduino.

## 🕹️ Como Usar

Aponte o controle remoto para o receptor IR e pressione os botões para controlar a cortina. Os comandos padrão no código são:

| Botão no Controle | Ação                                               |
| :---------------- | :------------------------------------------------- |
| `1`               | Gira o motor 1 vez no sentido horário.             |
| `2`               | Gira o motor 1 vez no sentido anti-horário.        |
| `3`               | Gira o motor 3 vezes no sentido horário.           |
| `4`               | Gira o motor 3 vezes no sentido anti-horário.      |
| `POWER`           | Para o motor (função a ser implementada).          |
| `5` a `9`         | Ações personalizadas (a serem implementadas).      |

## 🔧 Customização

### Usando seu próprio controle remoto

Se você quiser usar um controle remoto diferente, precisará descobrir os códigos hexadecimais de seus botões.

1.  Com o Arduino conectado ao computador, abra o **Monitor Serial** na Arduino IDE (`Ferramentas > Monitor Serial`).
2.  Configure a velocidade (baud rate) para **9600**.
3.  Aponte seu controle para o receptor e pressione os botões que deseja usar.
4.  O Monitor Serial exibirá o código hexadecimal de cada botão (ex: `CF30FF00`).
5.  No código, substitua os valores `case` dentro da estrutura `switch` pelos códigos do seu controle.

### Ajustando o motor

A constante `passosPorGiroMotor` está definida como `200`. Altere este valor se o seu motor de passo tiver um número diferente de passos por revolução (ex: 400).

```cpp
const int passosPorGiroMotor = 200; // Altere este valor conforme seu motor
```

## 🤝 Contribuição

Contribuições são muito bem-vindas! Sinta-se à vontade para abrir uma *issue* para relatar bugs ou sugerir melhorias, ou enviar um *pull request* com suas alterações.

## 📄 Licença

Este projeto está sob a licença MIT.