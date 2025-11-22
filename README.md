# Minitalk

Este repositório contém a minha implementação do projeto "minitalk" (42). É um pequeno projeto cliente-servidor que envia mensagens entre processos UNIX usando sinais (`SIGUSR1`/`SIGUSR2`). Este repositório serve como exemplo técnico no meu portfólio: mostra controle de baixo nível de processos, comunicação por sinais, manipulação bit-a-bit e boas práticas em C.

**Conteúdo rápido**
- **Linguagem:** C
- **Conceitos:** sinais POSIX, comunicação IPC por sinais, operações bitwise, tratamento seguro em signal handlers, `sigaction` e acknowledgements (ACKs).

**Visão Geral**

O objetivo é transferir uma string do processo `client` para o processo `server` usando apenas sinais. Cada carácter é enviado bit-a-bit (8 bits) do bit mais significativo (MSB) para o menos (LSB). O servidor reconstrói bytes recebendo sinais e responde com ACKs para controlar o fluxo.

**Como funciona (resumo técnico)**
- O `client` lê o PID do servidor como argumento e, para cada bit de um carácter, envia:
	- `SIGUSR2` para bit 1 (definido como `BIT_1`)
	- `SIGUSR1` para bit 0 (definido como `BIT_0`)
- Após enviar cada bit, o `client` espera um ACK (`ACK_SIGNAL`) do `server` para continuar — isto garante sincronização e evita perda de sinais.
- Quando o `server` recebe 8 bits, reconstrói o carácter com operações de deslocamento e OR, escreve o carácter no stdout e, no término da mensagem (byte `\0`), envia um `COMPLETE_ACK` para o `client`.

**Arquivos principais**
- `server.c`: aplicação servidor. Registra handlers com `sigaction`, reconstrói bytes, imprime a mensagem e envia ACKs.
- `client.c`: aplicação cliente. Converte a mensagem em bits MSB-first, envia sinais com `kill()` e espera confirmações.
- `includes/minitalk.h`: constantes (`BIT_0`, `BIT_1`, `ACK_SIGNAL`, `COMPLETE_ACK`), estrutura de estado e includes.
- `libft/`: implementação local de utilitários (`ft_printf`, `ft_atoi`, entre outros) usados para permitir foco no exercício sem depender de libs externas.
- `Makefile`: regras de compilação (geralmente `make` produz `client` e `server`).

**Como compilar**

No diretório do projeto:

```bash
make
```

Isso deve compilar `client` e `server` (dependendo do `Makefile` presente).

**Como executar**

1. Inicie o servidor em um terminal:

```bash
./server
# -> exibirá: Server PID: 12345
```

2. Em outro terminal, envie uma mensagem usando o PID mostrado:

```bash
./client 12345 "Olá, Minitalk!"
```

O servidor imprimirá a mensagem recebida. O `client` aguardará um ACK final e exibirá `Done` quando a transferência for concluída.

**Detalhes de implementação e conceitos aplicados**
- Comunicação por sinais (IPC): usando `kill()` para enviar `SIGUSR1`/`SIGUSR2` entre processos.
- `sigaction` com `SA_SIGINFO`: handler recebe `siginfo_t` para identificar o PID do remetente.
- Bitwise e reconstrução de bytes: `current_char = (current_char << 1) | bit` para reconstruir MSB-first.
- Sincronização por ACKs: o servidor envia um sinal de confirmação a cada bit recebido; o cliente espera esse ACK antes de enviar o próximo bit.
- Variáveis seguras para sinais: uso de `volatile sig_atomic_t` para estado compartilhado entre handler e fluxo principal.
- Robustez: detecção de PID de cliente, reset do estado quando um novo cliente aparece, timeout básico no cliente para ACK de término.
- Uso da `libft`: funções utilitárias (parse, impressão) foram usadas para consistência com outros projetos do 42.

**Pontos de atenção / desafios enfrentados**
- Enviar sinais muito rápido pode causar perda; a estratégia de ACKs garante sincronização.
- Handlers de sinal devem usar apenas funções seguras para serem reentrantes; a implementação limita-se a operações seguras e atualizações em `sig_atomic_t`.
- Concorrência: este servidor é simples e processa um cliente por vez (ao detectar outro cliente, reinicia o estado).


