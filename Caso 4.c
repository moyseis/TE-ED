
* ============================================================
   SISTEMA DE GESTAO ACADEMICA
   Caso de Uso 4 - Realizar Matricula
   Atores: Aluno, Professor, Coordenador
   Regras de negocio:
     - Limite de creditos por semestre
     - Disciplinas com pre-requisitos obrigatorios
   Fluxos alternativos tratados:
     3A - Pre-requisito nao atendido
     4A - Turma lotada
   ============================================================ */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALUNOS       50
#define MAX_DISCIPLINAS  20
#define MAX_NOME         60
#define LIMITE_CREDITOS  24   /* regra de negocio: limite por semestre */
#define SEM_PREREQ       -1   /* indica que a disciplina nao tem pre-requisito */

/* ---------- ESTRUTURAS (equivalem ao Diagrama de Classes) ---------- */

typedef struct {
    int  id;
    char nome[MAX_NOME];
    int  creditos;
    int  vagas;
    int  idPreRequisito;      /* -1 se nao houver */
} Disciplina;

typedef struct {
    int  id;
    char nome[MAX_NOME];
    int  creditosMatriculadosNoSemestre;
    int  disciplinasCursadas[MAX_DISCIPLINAS]; /* ids das disciplinas ja concluidas */
    int  totalCursadas;
    int  disciplinasMatriculadas[MAX_DISCIPLINAS]; /* ids das disciplinas do semestre atual */
    int  totalMatriculadas;
} Aluno;

/* ---------- "BANCO DE DADOS" EM MEMORIA ---------- */

Disciplina disciplinas[MAX_DISCIPLINAS];
int totalDisciplinas = 0;

Aluno alunos[MAX_ALUNOS];
int totalAlunos = 0;

/* ============================================================
   FUNCOES AUXILIARES DE BUSCA
   ============================================================ */

Disciplina* buscarDisciplina(int id) {
    for (int i = 0; i < totalDisciplinas; i++)
        if (disciplinas[i].id == id)
            return &disciplinas[i];
    return NULL;
}

Aluno* buscarAluno(int id) {
    for (int i = 0; i < totalAlunos; i++)
        if (alunos[i].id == id)
            return &alunos[i];
    return NULL;
}

int alunoJaCursou(Aluno *a, int idDisciplina) {
    for (int i = 0; i < a->totalCursadas; i++)
        if (a->disciplinasCursadas[i] == idDisciplina)
            return 1;
    return 0;
}

int alunoJaMatriculadoNaDisciplina(Aluno *a, int idDisciplina) {
    for (int i = 0; i < a->totalMatriculadas; i++)
        if (a->disciplinasMatriculadas[i] == idDisciplina)
            return 1;
    return 0;
}

/* ============================================================
   CADASTROS
   ============================================================ */

void cadastrarDisciplina() {
    if (totalDisciplinas >= MAX_DISCIPLINAS) {
        printf("Limite de disciplinas cadastradas atingido.\n");
        return;
    }
    Disciplina d;
    d.id = totalDisciplinas + 1;
    printf("Nome da disciplina: ");
    getchar();
    fgets(d.nome, MAX_NOME, stdin);
    d.nome[strcspn(d.nome, "\n")] = '\0';

    printf("Quantidade de creditos: ");
    scanf("%d", &d.creditos);

    printf("Quantidade de vagas: ");
    scanf("%d", &d.vagas);

    printf("Id da disciplina pre-requisito (0 se nao houver): ");
    int pre;
    scanf("%d", &pre);
    d.idPreRequisito = (pre == 0) ? SEM_PREREQ : pre;

    disciplinas[totalDisciplinas++] = d;
    printf(">> Disciplina cadastrada com id %d.\n\n", d.id);
}

void cadastrarAluno() {
    if (totalAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos cadastrados atingido.\n");
        return;
    }
    Aluno a;
    a.id = totalAlunos + 1;
    printf("Nome do aluno: ");
    getchar();
    fgets(a.nome, MAX_NOME, stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0';

    a.creditosMatriculadosNoSemestre = 0;
    a.totalCursadas = 0;
    a.totalMatriculadas = 0;

    alunos[totalAlunos++] = a;
    printf(">> Aluno cadastrado com id %d.\n\n", a.id);
}

/* Permite marcar que um aluno ja concluiu uma disciplina,
   usado para simular historico e testar os pre-requisitos. */
void marcarDisciplinaComoCursada() {
    int idAluno, idDisc;
    printf("Id do aluno: ");
    scanf("%d", &idAluno);
    Aluno *a = buscarAluno(idAluno);
    if (!a) { printf("Aluno nao encontrado.\n\n"); return; }

    printf("Id da disciplina concluida: ");
    scanf("%d", &idDisc);
    if (!buscarDisciplina(idDisc)) { printf("Disciplina nao encontrada.\n\n"); return; }

    if (a->totalCursadas < MAX_DISCIPLINAS) {
        a->disciplinasCursadas[a->totalCursadas++] = idDisc;
        printf(">> Historico atualizado.\n\n");
    }
}

/* ============================================================
   CASO DE USO PRINCIPAL: REALIZAR MATRICULA
   Fluxo principal:
     1. Aluno acessa sistema        -> aluno informado por id
     2. Escolhe disciplinas         -> disciplina informada por id
     3. Sistema verifica pre-requisitos
        3A. Pre-requisito nao atendido -> matricula recusada
     4. Sistema verifica vagas disponiveis
        4A. Turma lotada               -> matricula recusada
     5. Matricula e confirmada
   Regra de negocio adicional: respeita o limite de creditos por semestre
   ============================================================ */

void realizarMatricula() {
    int idAluno, idDisc;

    printf("Id do aluno: ");
    scanf("%d", &idAluno);
    Aluno *aluno = buscarAluno(idAluno);
    if (!aluno) {
        printf(">> Aluno nao encontrado.\n\n");
        return;
    }

    printf("Id da disciplina desejada: ");
    scanf("%d", &idDisc);
    Disciplina *disc = buscarDisciplina(idDisc);
    if (!disc) {
        printf(">> Disciplina nao encontrada.\n\n");
        return;
    }

    if (alunoJaMatriculadoNaDisciplina(aluno, idDisc)) {
        printf(">> O aluno ja esta matriculado nesta disciplina.\n\n");
        return;
    }

    /* Passo 3 + Fluxo alternativo 3A: pre-requisito nao atendido */
    if (disc->idPreRequisito != SEM_PREREQ &&
        !alunoJaCursou(aluno, disc->idPreRequisito)) {
        Disciplina *pre = buscarDisciplina(disc->idPreRequisito);
        printf(">> MATRICULA RECUSADA (3A): pre-requisito \"%s\" nao atendido.\n\n",
               pre ? pre->nome : "desconhecido");
        return;
    }

    /* Passo 4 + Fluxo alternativo 4A: turma lotada */
    if (disc->vagas <= 0) {
        printf(">> MATRICULA RECUSADA (4A): turma lotada, sem vagas disponiveis.\n\n");
        return;
    }

    /* Regra de negocio: limite de creditos por semestre */
    if (aluno->creditosMatriculadosNoSemestre + disc->creditos > LIMITE_CREDITOS) {
        printf(">> MATRICULA RECUSADA: limite de %d creditos por semestre seria excedido.\n\n",
               LIMITE_CREDITOS);
        return;
    }

    /* Passo 5: matricula confirmada */
    disc->vagas--;
    aluno->creditosMatriculadosNoSemestre += disc->creditos;
    aluno->disciplinasMatriculadas[aluno->totalMatriculadas++] = idDisc;

    printf(">> MATRICULA CONFIRMADA: %s matriculado(a) em \"%s\".\n", aluno->nome, disc->nome);
    printf("   Creditos no semestre: %d/%d | Vagas restantes na turma: %d\n\n",
           aluno->creditosMatriculadosNoSemestre, LIMITE_CREDITOS, disc->vagas);
}

/* ============================================================
   RELATORIOS / LISTAGENS
   ============================================================ */

void listarDisciplinas() {
    printf("\n--- DISCIPLINAS CADASTRADAS ---\n");
    if (totalDisciplinas == 0) { printf("(nenhuma)\n\n"); return; }
    for (int i = 0; i < totalDisciplinas; i++) {
        Disciplina *d = &disciplinas[i];
        printf("Id %d | %s | %d creditos | %d vagas | pre-requisito: %s\n",
               d->id, d->nome, d->creditos, d->vagas,
               (d->idPreRequisito == SEM_PREREQ) ? "nenhum" :
               (buscarDisciplina(d->idPreRequisito) ? buscarDisciplina(d->idPreRequisito)->nome : "?"));
    }
    printf("\n");
}

void listarAlunos() {
    printf("\n--- ALUNOS CADASTRADOS ---\n");
    if (totalAlunos == 0) { printf("(nenhum)\n\n"); return; }
    for (int i = 0; i < totalAlunos; i++) {
        Aluno *a = &alunos[i];
        printf("Id %d | %s | Creditos no semestre: %d/%d | Disciplinas matriculadas: ",
               a->id, a->nome, a->creditosMatriculadosNoSemestre, LIMITE_CREDITOS);
        if (a->totalMatriculadas == 0) {
            printf("nenhuma");
        } else {
            for (int j = 0; j < a->totalMatriculadas; j++) {
                Disciplina *d = buscarDisciplina(a->disciplinasMatriculadas[j]);
                printf("%s%s", d ? d->nome : "?", (j < a->totalMatriculadas - 1) ? ", " : "");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* ============================================================
   MENU PRINCIPAL
   ============================================================ */

void menu() {
    printf("=================================================\n");
    printf(" SISTEMA DE GESTAO ACADEMICA\n");
    printf("=================================================\n");
    printf("1 - Cadastrar disciplina\n");
    printf("2 - Cadastrar aluno\n");
    printf("3 - Marcar disciplina como ja cursada (historico)\n");
    printf("4 - Realizar matricula\n");
    printf("5 - Listar disciplinas\n");
    printf("6 - Listar alunos e matriculas\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    int opcao;
    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: cadastrarDisciplina(); break;
            case 2: cadastrarAluno(); break;
            case 3: marcarDisciplinaComoCursada(); break;
            case 4: realizarMatricula(); break;
            case 5: listarDisciplinas(); break;
            case 6: listarAlunos(); break;
            case 0: printf("Encerrando o sistema.\n"); break;
            default: printf("Opcao invalida.\n\n");
        }
    } while (opcao != 0);

    return 0;
} **
