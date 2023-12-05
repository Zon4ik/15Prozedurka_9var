#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определение структуры для узла в стеке
typedef struct Node {
    char brand[50];
    char color[50];
    char serialNumber[50];
    int numsDoors;
    int yearOfRelease;
    int price;
    struct Node* next;
} Node;

void push(Node** head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf(
        "Выбери элемент из каталога: \n"
        "1.Марка\n"
        "2.Цвет\n"
        "3.Серийный Номер\n"
        "4.Кол-во дверей\n"
        "5.Год релиза\n"
        "6.Цена\n"
    );
    int choice_catalog;
    int value_int;
    char value_str[50];

    strcpy(newNode->brand, "0");
    strcpy(newNode->color, "0");
    strcpy(newNode->serialNumber, "0");
    newNode->numsDoors = -1;
    newNode->yearOfRelease = -1;
    newNode->price = -1;

    scanf("%d", &choice_catalog);
    switch (choice_catalog)
    {
    case 1:
        system("cls");
        printf("Добавить в список: ");
        scanf("%s", &value_str);
        strcpy(newNode->brand, value_str);
        break;
    case 2:
        system("cls");
        printf("Добавить в список: ");
        scanf("%s", &value_str);
        strcpy(newNode->color, value_str);
        break;
    case 3:
        system("cls");
        printf("Добавить в список: ");
        scanf("%s", &value_str);
        strcpy(newNode->serialNumber, value_str);
        break;
    case 4:
        system("cls");
        printf("Добавить в список: ");
        scanf("%d", &value_int);
        newNode->numsDoors = value_int;
        break;
    case 5:
        system("cls");
        printf("Добавить в список: ");
        scanf("%d", &value_int);
        newNode->yearOfRelease = value_int;
        break;
    case 6:
        system("cls");
        printf("Добавить в список: ");
        scanf("%d", &value_int);
        newNode->price = value_int;
        break;
    default:
        break;
    }


    /*newNode->price = value;*/
    newNode->next = *head;
    *head = newNode;
}

// Так как в односвязном списке используется тип LIFO,
// то мы можем удалить только с конца списка
int pop(struct Node** head) {
    if (*head != NULL) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Важно помнить что вывод происходит наоборот
void insert(Node* head, int position, int count) {
    count -= position;
    int choice = 1;
    int value_str[50];
    int value_int;
    for (int i = 0; i < count; i++) {
        head = head->next;
    }

    printf(
        "Выбери элемент из каталога: \n"
        "1.Марка\n"
        "2.Цвет\n"
        "3.Серийный Номер\n"
        "4.Кол-во дверей\n"
        "5.Год релиза\n"
        "6.Цена\n"
    );

    Node* new_node = (Node*)malloc(sizeof(Node));
    switch (choice)
    {
    case 1:
        system("cls");
        printf("Добавить в список: ");
        scanf("%s", &value_str);
        strcpy(new_node->brand, value_str);
        break;
    case 2:
        system("cls");
        printf("Добавить в список: ");
        scanf("%s", &value_str);
        strcpy(new_node->color, value_str);
        break;
    case 3:
        system("cls");
        printf("Добавить в список: ");
        scanf("%s", &value_str);
        strcpy(new_node->serialNumber, value_str);
        break;
    case 4:
        system("cls");
        printf("Добавить в список: ");
        scanf("%d", &value_int);
        new_node->numsDoors = value_int;
        break;
    case 5:
        system("cls");
        printf("Добавить в список: ");
        scanf("%d", &value_int);
        new_node->yearOfRelease = value_int;
        break;
    case 6:
        system("cls");
        printf("Добавить в список: ");
        scanf("%d", &value_int);
        new_node->price = value_int;
        break;
    default:
        break;
    }

    Node* tmp = head->next; // Делаю копию на следующий элемент
    head->next = new_node; // меняю ссылку на новый элемент
    new_node->next = tmp; // В новом элементе ставлю ссылку на следующий (копию)
}


int count_elements(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}



void print_stack(Node* head) {
    int choice;
    printf("Выведи категорию вывода: ");
    printf(
        "Выбери элемент из каталога: \n"
        "1.Марка\n"
        "2.Цвет\n"
        "3.Серийный Номер\n"
        "4.Кол-во дверей\n"
        "5.Год релиза\n"
        "6.Цена\n"
    );
    scanf("%d", &choice);
    system("cls");
    while (head != NULL) {
        switch (choice)
        {
        case 1:
            if (!strcmp(head->brand, "0")) continue;
            printf("%s ", head->brand);
            break;
        case 2:
            if (!strcmp(head->color, "0")) continue;
            printf("%s ", head->color);
            break;
        case 3:
            if (!strcmp(head->serialNumber, "0")) continue;
            printf("%s ", head->serialNumber);
            break;
        case 4:
            if (head->numsDoors = -1) continue;
            printf("%d ", head->numsDoors);
            break;
        case 5:
            if (head->yearOfRelease = -1) continue;
            printf("%d ", head->yearOfRelease);
            break;
        case 6:
            if (head->price = -1) continue;
            printf("%d ", head->price);
            break;
        default:
            break;
        }
        head = head->next;
        printf("\n");
    }
}


int find(Node* head) {
    int choice = 1;
    int find_int_value = 12;
    char find_str_value[50] = "123";
    switch (choice)
    {
    case 1:
        while (head != NULL) {
            if (!strcmp(head->brand, find_str_value)) {
                printf("Элемент %s найден\n", head->brand);
                return head->brand;
            }
            else {
                head = head->next;
            }
        }
        printf("Элемент не найден\n");
        break;
    case 2:
        while (head != NULL) {
            if (!strcmp(head->color, find_str_value)) {
                printf("Элемент %s найден\n", head->brand);
                return head->brand;
            }
            else {
                head = head->next;
            }
        }
        printf("Элемент не найден\n");
        break;
    case 3:
        while (head != NULL) {
            if (!strcmp(head->serialNumber, find_str_value)) {
                printf("Элемент %s найден\n", head->brand);
                return head->brand;
            }
            else {
                head = head->next;
            }
        }
        printf("Элемент не найден\n");
        break;
    case 4:
        while (head != NULL) {
            if (head->numsDoors == find_int_value) {
                printf("Элемент %d найден\n", head->numsDoors);
                return head->numsDoors;
            }
            else {
                head = head->next;
            }
        }
        printf("Элемент не найден\n");
        break;
    case 5:
        while (head != NULL) {
            if (head->yearOfRelease == find_int_value) {
                printf("Элемент %d найден\n", head->yearOfRelease);
                return head->yearOfRelease;
            }
            else {
                head = head->next;
            }
        }
        printf("Элемент не найден\n");
        break;
    case 6:
        while (head != NULL) {
            if (head->price == find_int_value) {
                printf("Элемент %d найден\n", head->price);
                return head->price;
            }
            else {
                head = head->next;
            }
        }
        printf("Элемент не найден\n");
        break;
    default:
        break;
    }
}

void add(Node** head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    char str_value[50];
    int int_value;
    system("cls");
    printf("Введи марку: ");
    scanf("%s", &str_value);
    strcpy(newNode->brand, str_value);

    printf("Введи цвет: ");
    scanf("%s", &str_value);
    strcpy(newNode->color, str_value);

    printf("Введи серийный номер: ");
    scanf("%s", &str_value);
    strcpy(newNode->serialNumber, str_value);

    printf("Введи кол-во дверей: ");
    scanf("%d", &int_value);
    newNode->numsDoors = int_value;

    printf("Введи год релиза: ");
    scanf("%d", &int_value);
    newNode->yearOfRelease = int_value;

    printf("Введи цену: ");
    scanf("%d", &int_value);
    newNode->price = int_value;

    newNode->next = *head;
    *head = newNode;

}

void fiterlist(Node* head) {
    printf("Введи фильтр по марке\n");
    char str_value[50];
    scanf("%s", &str_value);

    while (head != NULL) {
        if (!strcmp(head->brand, str_value)) {
            printf("Марка %s найдена\n", head->brand);
            printf("Цвет: %s\n", head->color);
            printf("Cерийный номер: %s\n", head->serialNumber);
            printf("Кол-во дверей: %d\n", head->numsDoors);
            printf("Год релиза: %d\n", head->yearOfRelease);
            printf("Цена: %d\n", head->price);
            break;
        }
        else {
            head = head->next;
        }
    }
    if (head == NULL)
        printf("Элемент не найден\n");
    
}

void mainMenu() {
    printf(
        "Выбери действие: \n"
        "1.Создать и добавить элемент\n"
        "2.Создать список по всем категориям\n"
        "3.Удалить элемент с конца\n"
        "4.Создать и добавить элемент на позицию\n"
        "5.Поиск и извлечение элемента\n"
        "6.Сохранить список в файл\n"
        "7.Вывести список в консоль из файла\n"
        "8.Вывеси список по элементу\n"
        "9.Вывести по фильтру\n"
        "10.Пройти дальше\n"
    );
}

void saveFile(Node* head) {
    FILE* file = fopen("outfile.txt", "w");
    if (file == NULL) {
        ferror("Ошибка в файле");
        return 1;
    }

    Node* temp = head;
    int count = 1;
    char str[50];
    while (temp != NULL) {
        fprintf(file, "%s %d\n", "Машина", count);
        fprintf(file, "Марка: %s\n", temp->brand);
        fprintf(file, "Цвет: %s\n", temp->color);
        fprintf(file, "Серийный Номер: %s\n", temp->serialNumber);
        sprintf(str, "%d", temp->color);
        fprintf(file, "Кол-во дверей: %s\n", str);
        sprintf(str, "%d", temp->yearOfRelease);
        fprintf(file, "Год выпуска: %s\n", str);
        sprintf(str, "%d", temp->price);
        fprintf(file, "Цена: %s\n", str);
        fprintf(file, "\n");
        
        count++;
        temp = temp->next;
    }free(temp);
    fclose(file);
}

void loadfile() {
    FILE* file = fopen("outfile.txt", "r");
    if (file == NULL) {
        ferror("Ошибка в файле");
        return 1;
    }
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        printf("%c", ch);
    }

    fclose(file);

}
int main() {
    system("chcp 1251 >> null");
    Node* head = NULL;

    start: mainMenu();
    int choice;
    int position;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        system("cls");
        push(&head);
        goto start;
        break;
    case 2:
        add(&head);
        goto start;
        break;
    case 3:
        system("cls");
        pop(&head);
        goto start;
        break;
    case 4:
        system("cls");
        printf("Выбери позицию: \n");
        scanf("%d", &position);
        insert(head, position, count_elements(head));
        goto start;
        break;
    case 5:
        system("cls");
        char* strs = find(head);
        goto start;
        break;
    case 6:
        system("cls");
        saveFile(head);
        goto start;
    case 7:
        system("cls");
        loadfile();
        goto start;
        break;
    case 8:
        print_stack(head);
        goto start;
        break;
    case 9:
        system("cls");
        fiterlist(head);
        goto start;
        break;
    case 10:
        goto end;
        break;
    default:
        break;
    }
    
    end: 
    return 0;
}
