#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// verificação de rro na abertura de arquivos de leitura
int verificar_leitura(FILE *arquivo){
    if (arquivo == NULL){
        printf("Erro ao ler arquivo");
        exit(1);
    }
    return 0;
}

// verificação de rro na abertura de arquivos de cruação
int verificar_criacao(FILE *arquivo){
    if (arquivo == NULL){
        printf("Erro ao criar arquivo");
        exit(1);
    }

    return 0;
}

// cria o ponteiro arquivo com a localização do arquivo txt
FILE* le_arquivo (const char *caminho){
    FILE *arquivo = fopen(caminho, "r");

    verificar_leitura(arquivo);
    return arquivo;
}

// imprime as notas dos alunos
void print_notas(FILE *arquivo){
    char nome[100];
    double nota1;
    double nota2;

    printf("\nNOTAS\n");
    while(fscanf(arquivo, "%s %lf %lf", nome, &nota1, &nota2) == 3){
        printf("%s   %.2lf   %.2lf\n", nome, nota1, nota2);
    }

    rewind(arquivo);
}

// imprime a média de cada aluno
void print_media(FILE *arquivo){
    char nome[100];
    double nota1;
    double nota2;
    double media;

    printf("\nCALCULO DE MEDIA\n");
    while(fscanf(arquivo, "%s %lf %lf", nome, &nota1, &nota2) == 3){
        media = (nota1 + nota2)/2;
        printf("%s   %.2lf\n", nome, media);
    }
    rewind(arquivo);
}

// imprime a média de cada aluno
void print_aprovados(FILE *arquivo){
    char nome[100];
    double nota1;
    double nota2;
    double media;

    printf("\nAPROVADOS\n");
    while(fscanf(arquivo, "%s %lf %lf", nome, &nota1, &nota2) == 3){
        media = (nota1 + nota2)/2;
        if(media >= 5){
            printf("%s\n", nome);
        }
    }
    rewind(arquivo);   
}

// cria um novo arquivo com as médias e situação dos alunos
void add_media_aprovado(const char *caminho){
    char nome[100];
    double nota1;
    double nota2;
    double media;

    FILE *leitura = fopen(caminho, "r");
    verificar_leitura(leitura);
    FILE *escrita = fopen("notas_com_media_aprovados.txt", "w");

    while(fscanf(leitura, "%s %lf %lf", nome, &nota1, &nota2) == 3){
        media = (nota1 + nota2)/2;
        if (media >= 5){
            fprintf(escrita, "%s %.2lf %.2lf %.2lf APROVADO\n", nome, nota1, nota2, media);
        } else{
            fprintf(escrita, "%s %.2lf %.2lf %.2lf REPROVADO\n", nome, nota1, nota2, media);
        }

    }

    fclose(leitura);
    fclose(escrita);

    FILE *arquivo = fopen("notas_com_media_aprovados.txt", "r");
    verificar_criacao(arquivo);
    printf("\nArquivo com medias e aprovados criado com sucesso\n");
    fclose(arquivo);

}

int main(){
    
    FILE *arquivo;
    const char *caminho = "notas.txt";

    arquivo = le_arquivo(caminho);

    print_notas(arquivo);
    print_media(arquivo);
    print_aprovados(arquivo);
    add_media_aprovado(caminho);

    fclose(arquivo);
    return 0;
}
