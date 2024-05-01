# Projeto Post Alert

## Sobre o Projeto
Esse projeto é desenvolvido no âmbito acadêmico com o objetivo de inovar a forma como recebemos nossas correspondências. Utilizando um sensor de presença acoplado às caixas de correios, o dispositivo é capaz de detectar a chegada de novas correspondências e notificar o proprietário de forma automática. Este projeto não apenas propõe uma solução tecnológica moderna para um problema cotidiano, mas também serve como uma excelente ferramenta de aprendizado em áreas como eletrônica, programação e sistemas embarcados.

## Funcionalidades

- **Detecção de Correspondência:** Utiliza um sensor de presença para detectar quando uma correspondência é depositada na caixa de correios.
- **Notificações:** Envia uma notificação ao proprietário da caixa de correios sempre que uma nova correspondência é detectada.
- **Registro de Atividades:** Mantém um histórico de todas as correspondências recebidas com data e hora da detecção.

## Tecnologias Utilizadas

- Sensor De Obstáculo
- ESP32 e Shild para alimentação
- Serviços de notificação como e-mail e aplicativo escolhido

## Pré-requisitos

Antes de iniciar, certifique-se de que você possui os seguintes itens:

- Um microcontrolador (ESP32)
- Sensor De Obstáculo
- Acesso à Internet via wifi
- Cabos e conexões adequadas

## Configuração

1. **Montagem do Hardware:** Conecte o sensor de presença ao microcontrolador seguindo o esquema de conexão fornecido na seção de esquemas deste documento.
2. **Configuração do Software:**
    - Instale as bibliotecas necessárias para o funcionamento do sensor e dos serviços de notificação.
    - Carregue o código-fonte fornecido para o microcontrolador.

## Como Usar

Após realizar a configuração inicial:

1. Posicione o dispositivo abaixo da entrada da sua caixa de correios, na parte interna.
2. Certifique-se de que o dispositivo está conectado à Internet para enviar as notificações.
3. Receba notificações em tempo real sempre que uma correspondência for detectada.

## Contribuir

Contribuições são o que fazem a comunidade open-source um lugar incrível para aprender, inspirar e criar. Quaisquer contribuições que você fizer serão **muito apreciadas**.

Para contribuir:

1. Faça um _fork_ do projeto.
2. Crie uma _branch_ para a sua feature (`git checkout -b feature/AmazingFeature`).
3. Faça o _commit_ das suas alterações (`git commit -m 'Add some AmazingFeature'`).
4. _Push_ para a branch (`git push origin feature/AmazingFeature`).
5. Abra um _pull request_.

## Licença

Distribuído sob a Licença MIT. Veja `LICENSE` para mais informações.

## Contato

Caio Pontes – caiopontes1707@hotmail.com