#include <stdio.h>

int main() {
    int qtd, i, id, total_aulas, presencas, situacao;
    float frequencia;

    printf("=== SISTEMA DE FREQUENCIA ===\n");
    printf("Legenda de Situacao: (1) Regular | (2) Em Alerta | (3) Reprovado\n\n");
    
    printf("Digite a quantidade de estudantes: ");
    scanf("%d", &qtd);

    while (qtd <= 0) {
        printf("Quantidade invalida! Digite um numero maior que zero: ");
        scanf("%d", &qtd);
    }

    for (i = 1; i <= qtd; i++) {
        printf("\n--- Cadastro do Estudante %d de %d ---\n", i, qtd);
        printf("Digite o Numero de Matricula (ID) [ou 0 para encerrar]: ");
        scanf("%d", &id);

        if (id <= 0) {
            printf("\nCadastro interrompido pelo usuario.\n");
            break;
        }

        printf("Total de aulas ministradas: ");
        scanf("%d", &total_aulas);
        while (total_aulas <= 0) {
            printf("O total de aulas deve ser maior que zero! Digite novamente: ");
            scanf("%d", &total_aulas);
        }

        printf("Numero de presencas: ");
        scanf("%d", &presencas);
        while (presencas < 0 || presencas > total_aulas) {
            printf("Numero de presencas invalido (deve ser entre 0 e %d)! Digite novamente: ", total_aulas);
            scanf("%d", &presencas);
        }

        frequencia = ((float)presencas / total_aulas) * 100.0;

        if (frequencia >= 75.0) {
            situacao = 1;
        } else if (frequencia >= 60.0) {
            situacao = 2;
        } else {
            situacao = 3;
        }

        printf("\n[Resultado do Aluno %d]\n", id);
        printf("Frequencia: %.1f%% | Situacao: (%d)", frequencia, situacao);
        
        if (situacao == 1) {
            printf(" - Regular\n");
        } else if (situacao == 2) {
            printf(" - Em Alerta\n");
        } else {
            printf(" - Reprovado\n");
        }
        
        printf("----------------------------------------\n");
    }

    printf("\nFim do processamento!\n");

    return 0;
}