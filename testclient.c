#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

typedef struct {
    int pid;
    char message[1024];
    int bit_count;
    char current_char;
} ClientData;

ClientData clients[10]; // Max 10 clients
int client_count = 0;

void handle_signals(int sign, siginfo_t *info, void *context)
{
    static int current_client = -1;

    // Find the client
    for (int i = 0; i < client_count; i++) {
        if (clients[i].pid == info->si_pid) {
            current_client = i;
            break;
        }
    }

    if (current_client == -1) {
        // New client
        current_client = client_count++;
        clients[current_client].pid = info->si_pid;
        clients[current_client].bit_count = 0;
        clients[current_client].current_char = 0;
        memset(clients[current_client].message, 0, sizeof(clients[current_client].message));
    }

    ClientData *client = &clients[current_client];

    if (sign == SIGUSR1)
        client->current_char = (client->current_char << 1) | 1;
    else if (sign == SIGUSR2)
        client->current_char = (client->current_char << 1) | 0;

    client->bit_count++;

    if (client->bit_count == 8) {
        if (client->current_char == '\0') {
            printf("Message from client (PID: %d): %s\n", client->pid, client->message);
            client->bit_count = 0;
            client->current_char = 0;
            memset(client->message, 0, sizeof(client->message));
        } else {
            strncat(client->message, &client->current_char, 1);
            client->bit_count = 0;
            client->current_char = 0;
        }
    }
}

int main(int ac, char **av)
{
    struct sigaction sa;

    (void)av;
    if (ac != 1)
    {
        printf("Erreur\n");
        return (1);
    }
    printf("PID:%d\n", getpid());
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_signals;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}