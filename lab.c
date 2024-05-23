#include "lr.h"

int laba1(){ 
   
 float l;
 float v1;
 float t;
 printf ("v1 = ");
 scanf("%f", &v1);
 printf ("l = ");
 scanf ("%f", &l); 
 t = 2*l/v1;
 printf("t = %f\n", t);
 return 0;
}
int laba2()
{

float n; 
float i; 
float N; 
float x; 
float s; 
float a; 
float m; 
float b; 
float d;
//ввод параметров ряда 
printf("N = ");
scanf("%f", &N);
printf("x = ");
scanf("%f", &x);
// начальное присваивание переменных 
s=1;
i=1; 
m=1;
m=-m; 
n=2;
d=1; 
b=1;
// цикл
while (i<N)
{
b = b*x*x;
d = d*n*(n-1); 
a = m*b/d;
i = i+1; 
n = n+1; 
m = -m; 
s = s+a;
}
//вывод результата
printf("s = %f\n", s); 
return 0;
}



int laba3()
{
int is_consonant(char ch) 
    {
    // Проверяем, является ли символ согласной буквой
    return ((ch >= 'b' && ch <= 'd') || (ch >= 'f' && ch <= 'h') ||
            (ch >= 'j' && ch <= 'n') || (ch >= 'p' && ch <= 't') ||
            (ch >= 'v' && ch <= 'z') || (ch >= 'B' && ch <= 'D') ||
            (ch >= 'F' && ch <= 'H') || (ch >= 'J' && ch <= 'N') ||
            (ch >= 'P' && ch <= 'T') || (ch >= 'V' && ch <= 'Z'));
    }

    {
    int c;         // текущий символ из потока
    int prevc = ' '; // предыдущий символ изначально пробел
    int cnt = 0;   // счетчик

    printf("Введите текст: \n");

    // цикл чтения символов из потока, связанного с
    // клавиатурой
    while ((c = getchar()) != EOF) {
        if ((prevc != ' ' && prevc != '\n' && prevc != '\t') && is_consonant(prevc) && (c == ' ' || c == '\n' || c == '\t')) {
            cnt++;
        }
        prevc = c;
    }

    printf("Количество слов, заканчивающихся на согласную букву: %d\n", cnt);
    return 0;
    }
}
int laba4() 
{
    char str[100];
    int i = 0;
    int j = 0;
    int count_spaces = 0;
    int last_space_index = -1;
    int second_last_space_index = -1;
    int ch;
    
    printf("Введите строку: ");
    while ((ch = getchar()) != '\n' && ch != EOF) {
        str[i++] = ch;
    }
    str[i] = '\0';
    
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count_spaces++;
            second_last_space_index = last_space_index;
            last_space_index = i;
        }
    }
    
    
    if (count_spaces >= 2) {
        
        for (i = 0; str[i] != '\0'; i++) {
            if (i <= second_last_space_index || i > last_space_index) {
                str[j++] = str[i];
            }
        }
    }

    str[j] = '\0';
    printf("%s\n", str);

    return 0;
}
int laba5() {
 
    int chisla[10];
    int max_index = 0;

    // Ввод чисел
    printf("Введите 10 целых чисел:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &chisla[i]);
    }
    
    // Находим индекс максимального элемента
    for (int i = 1; i < 10; i++) {
        if (chisla[i] > chisla[max_index]) {
            max_index = i;
        }
    }
    
    // Заменяем элементы слева от максимального на нули
    for (int i = 0; i < max_index; i++) {
        chisla[i] = 0;
    }

    // Заменяем элементы справа от максимального на максимальный элемент
    for (int i = max_index + 1; i < 10; i++) {
        chisla[i] = chisla[max_index];
    }

    // Итог
    printf("Массив после замен:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", chisla[i]);
    }
    return 0;
}

int laba6() 
{
    int N = 3;
    int arr[N][N];
    int sum_nad = 0;
    int sum_pod = 0;
    
    // Ввод элементов массива
    printf("Введите элементы массива %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Вычисление сумм элементов над и под главной диагональю
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i < j) {
                sum_nad += arr[i][j];
            } else{
                sum_pod += arr[i][j];
            }
        }
    }

    // Обнуление элементов в соответствии с условиями задачи
    if (sum_nad < sum_pod) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i < j) {
                    arr[i][j] = 0;
                }
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i > j) {
                    arr[i][j] = 0;
                }
            }
        }
    }

    // Вывод обновленного массива
    printf("Обновленный массив:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int laba7() {
    long long N;
    unsigned char bytes[sizeof(N)];
    int i;
    unsigned char diff;

    // Ввод числа с клавиатуры
    printf("Введите длинное целое число: ");
    scanf("%lld", &N);

    // Извлекаем байты из числа N с помощью битовой маски
    for (i = 0; i < sizeof(bytes); i++) {
        bytes[i] = (N >> (i * 8)) & 0xFF;
    }

    // Вычисляем разницу между первыми двумя байтами
    diff = bytes[1] - bytes[0];

    // Проверяем, являются ли остальные байты арифметической прогрессией
    for (i = 2; i < sizeof(bytes); i++) {
        if (bytes[i] - bytes[i-1] != diff) {
            printf("Байты числа не составляют арифметическую прогрессию.\n");
            return 0;
        }
    }

    printf("Байты числа составляют арифметическую прогрессию.\n");

    return 0;
}

int labadop1(){
    
#define BEGIN {
#define END }
#define N 45
int main()
BEGIN
 float l;
 float v1;
 float t;
 printf ("v1 = ");
 scanf ("%f", &v1); 
 printf ("l = ");
 scanf ("%f", &l); 
 t = 2*l/v1;
 printf("t = %f\n", t);
 return 0;
END
}


int labadop2(){
    
float n, x, s, a, b, d, m; 
int i;
// ввод параметров ряда 
printf("n = ");
scanf("%f", &n);
printf("x = ");
scanf("%f", &x);
// начальное присваивание переменных 
s = 1;
i = 1;
m = 1;
d = 1;
b = 1;
// цикл
while (n >= 0)
{
b = b*x*x;
d = d*n*(n-1); 
a = m*b/d; 
i = i+1; 
n = n-1;
m = -m; 
s = s+a;
}
// вывод результата 
printf("s = %f\n", s); 
return 0;
}

int labadop4()
{
    int has_vowels(const char *word) {
 int vowel_count = 0;
 for (int i = 0; word[i] != '\0'; i++) {
 char ch = word[i];
 if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
 ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
 vowel_count++;
 }
 }
 return vowel_count;
}
int main() {
 char str[100];
 int i = 0;
 int j = 0;
 int count_spaces = 0;
 int last_space_index = -1;
 int second_last_space_index = -1;
 int ch;
 printf("Введите строку: ");
 while ((ch = getchar()) != '\n' && ch != EOF) {
 str[i++] = ch;
 }
 str[i] = '\0';
 for (i = 0; str[i] != '\0'; i++) {
 if (str[i] == ' ') {
 count_spaces++;
 second_last_space_index = last_space_index;
 last_space_index = i;
 }
 }
 if (count_spaces >= 2 && has_vowels(&str[second_last_space_index + 1]) == 0) {
 for (i = 0; str[i] != '\0'; i++) {
 if (i <= second_last_space_index || i > last_space_index) {
 str[j++] = str[i];
 }
 }
 }
 str[j] = '\0';
printf("%s\n", str);
 return 0;
}
}

int labadop5()

{
 int chisla[10];
 int max_index = 0;
 // Ввод чисел
 printf("Введите 10 целых чисел:\n");
 for (int i = 0; i < 10; i++) {
 scanf("%d", &chisla[i]);
 }
// Находим индекс максимального элемента
 for (int i = 1; i < 10; i++) {
 if (chisla[i] > chisla[max_index]) {
 max_index = i;
 }
 }
// Заменяем элементы слева от максимального на нули, кроме отрицательных
for (int i = 0; i < max_index; i++) {
 if (chisla[i] >= 0) {
 chisla[i] = 0;
 }
 }
// Заменяем элементы справа от максимального на максимальный элемент
 for (int i = max_index + 1; i < 10; i++) {
 chisla[i] = chisla[max_index];
 }
 // Итог
 printf("Массив после замен:\n");
 for (int i = 0; i < 10; i++) {
printf("%d ", chisla[i]);
 }
 return 0;
} 




