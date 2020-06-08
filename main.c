#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

char *my_itoa(long num, int base);

char *reverse(char* a);

int my_printf(char * restrict format, ...)
{
    char *output = malloc(100 * sizeof(char));
    int i = 0, length = 0, a;
    int *ptr;
    char *string = malloc(100 * sizeof(char));
    va_list ap;
    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] != '%') {
            output[length++] = format[i++];
            continue;
        }
        if (format[i] == '%') {
            int after_format_specifier = i + 1;
            switch (format[after_format_specifier]) {
                case 'd':
                    a = va_arg(ap, int);
                    strcat(output, my_itoa(a, 10));
                    length += (int)strlen(my_itoa(a, 10));
                    break;
                case 'o':
                    a = va_arg(ap, int);
                    unsigned int m = (unsigned int) a;
                    strcat(output, my_itoa(m, 8));
                    length += (int)strlen(my_itoa(m, 8));
                    break;
                case 'u':
                    a = va_arg(ap,  int);
                    unsigned int u = (unsigned int) a;
                    strcat(output, my_itoa(u, 10));
                    length += (int)strlen(my_itoa(u, 10));
                    break;
                case 'x':
                    a = va_arg(ap, int);
                    unsigned int n = (unsigned int) a;
                    strcat(output, my_itoa(n, 16));
                    length += (int)strlen(my_itoa(n, 16));
                    break;
                case 'c':
                    a = va_arg(ap, int);
                    output[length++] = a;
                    break;
                case 's':
                    string = va_arg(ap, char*);
                    if(string != NULL) {
                        int k = 0;
                        while (string[k] != '\0') {
                            output[length++] = string[k++];
                        }
                    }
                    else {
                        strcat(output, "(null)");
                        length += (int)strlen("(null)");
                    }
                    break;
                case 'p':
                    ptr = va_arg(ap, void*);
                    if (ptr == NULL) {
                        strcat(output, "(nil)");
                        length += (int)strlen("(nil)");
                    }
                     else {
                        strcat(output, "0x");
                        length += 2;
                        strcat(output, my_itoa((long)ptr, 16));
                        length += (int)strlen(my_itoa((long)ptr, 16));
                     }
                    break;
                default:
                    break;
            }
            i += 2;
            continue;
        }
        i++;
    }

    write(1, output, length);
    return length;
}
#define RED "\033[31;1m"
#define NORMAL "\033[0m"
#define GREEN "\033[1;32m"

#define PRINTF_PARAM_0_1 "Hello world!\n"
void test_0_1()
{
    printf("<#0 - 1>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_0_1);
    int printf_ret_value = printf(PRINTF_PARAM_0_1);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#0 - 1>\n");
}

#define PRINTF_PARAM_2_3 "%c!\n", 'H'
void test_2_3()
{
    printf("<#2 - 3>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_2_3);
    int printf_ret_value = printf(PRINTF_PARAM_2_3);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#2 - 3>\n");
}

#define PRINTF_PARAM_4_5 "%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'
void test_4_5()
{
    printf("<#4 - 5>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_4_5);
    int printf_ret_value = printf(PRINTF_PARAM_4_5);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#4 - 5>\n");
}

#define PRINTF_PARAM_6_7 "Hello %s!\n", "QWASAR.IO"
void test_6_7()
{
    printf("<#6 - 7>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_6_7);
    int printf_ret_value = printf(PRINTF_PARAM_6_7);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#6 - 7>\n");
}

#define PRINTF_PARAM_8_9 "Hello %s %s!\n", "Mr", "Gaetan"
void test_8_9()
{
    printf("<#8 - 9>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_8_9);
    int printf_ret_value = printf(PRINTF_PARAM_8_9);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#8 - 9>\n");
}


#define PRINTF_PARAM_10_11 "NULL STRING %s!\n", (char *)NULL
void test_10_11()
{
    printf("<#10 - 11>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_10_11);
    int printf_ret_value = printf(PRINTF_PARAM_10_11);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#10 - 11>\n");
}

#define PRINTF_PARAM_12_13 "%d!\n", 1337
void test_12_13()
{
    printf("<#12 - 13>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_12_13);
    int printf_ret_value = printf(PRINTF_PARAM_12_13);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#12 - 13>\n");
}

#define PRINTF_PARAM_14_15 "%d - %d - %d!\n", 2048, 0, -1337
void test_14_15()
{
    printf("<#14 15>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_14_15);
    int printf_ret_value = printf(PRINTF_PARAM_14_15);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#15 16>\n");
}

#define PRINTF_PARAM_16_17 "%o!\n", 100
void test_16_17()
{
    printf("<#16 - 17>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_16_17);
    int printf_ret_value = printf(PRINTF_PARAM_16_17);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#16 - 17>\n");
}

#define PRINTF_PARAM_18_19 "%u!\n", 1337
void test_18_19()
{
    printf("<#18 - 19>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_18_19);
    int printf_ret_value = printf(PRINTF_PARAM_18_19);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#18 - 19>\n");
}

#define PRINTF_PARAM_20_21 "%x!\n", 14
void test_20_21()
{
    printf("<#20 - 21>\n");
    int my_printf_ret_value = my_printf(PRINTF_PARAM_20_21);
    int printf_ret_value = printf(PRINTF_PARAM_20_21);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#20 - 21>\n");
}

void test_22_23()
{
    int a = 3;
    printf("<#22 - 23>\n");
    int my_printf_ret_value = my_printf("%p!\n", &a);
    int printf_ret_value = printf("%p!\n", &a);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
    printf("</#22 - 23>\n");
}

#define NEGATIVE -17
#define MIN_INT (int)-2147483648
#define MAX_INT 2147483647

#define PRINTF_CUSTOM_1 "%d\n", NEGATIVE
void custom1()
{
    printf("\n\nSigned negative \n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_1);
    int printf_ret_value = printf(PRINTF_CUSTOM_1);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_2 "%u\n", NEGATIVE
void custom2()
{
    printf("\n\nUnsigned negative\n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_2);
    int printf_ret_value = printf(PRINTF_CUSTOM_2);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_3 "%x\n", NEGATIVE
void custom3()
{
    printf("\n\nHexa negative\n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_3);
    int printf_ret_value = printf(PRINTF_CUSTOM_3);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_4 "%o\n", NEGATIVE
void custom4()
{

    printf("\n\nOctal negative\n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_4);
    int printf_ret_value = printf(PRINTF_CUSTOM_4);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_5 "%d\n", MIN_INT
void custom5()
{
    printf("\n\nSigned minimum\n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_5);
    int printf_ret_value = printf(PRINTF_CUSTOM_5);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_6 "%u\n", MIN_INT
void custom6()
{
    printf("\n\nUnsigned minimum\n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_6);
    int printf_ret_value = printf(PRINTF_CUSTOM_6);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_7 "%x\n", MIN_INT
void custom7()
{

    printf("\n\nHexa minimum\n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_7);
    int printf_ret_value = printf(PRINTF_CUSTOM_7);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_8 "%o\n", MIN_INT
void custom8()
{

    printf("\n\nOctal minimum\n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_8);
    int printf_ret_value = printf(PRINTF_CUSTOM_8);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_9 "%s\n", "qwertyuiopastdsfghjkarestyuiopuytrrdtfjuytreertyuioytrdjegdlasgdljfhgadsljghflashdkljfghkldfhgkldhfslkghsdflkghsldkfjhglskdjfhglksjdhfgl"
void custom9()
{

    printf("\n\nLong long string \n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_9);
    int printf_ret_value = printf(PRINTF_CUSTOM_9);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

#define PRINTF_CUSTOM_10 "%p\n", NULL
void custom10()
{

    printf("\n\nNULL address \n");
    int my_printf_ret_value = my_printf(PRINTF_CUSTOM_10);
    int printf_ret_value = printf(PRINTF_CUSTOM_10);
    printf("%s my_printf(%d) == printf(%d) %s\n", my_printf_ret_value != printf_ret_value ? RED : GREEN , my_printf_ret_value, printf_ret_value, NORMAL);
}

int main()
{

    test_0_1();
    test_2_3();
    test_4_5();
    test_6_7();
    test_8_9();
    test_10_11();
    test_12_13();
    test_14_15();
    test_16_17();
    test_18_19();
    test_20_21();
    test_22_23();

    printf("\n\n====== CUSTOM TESTS =====\n\n");

    custom1();
    custom2();
    custom3();
    custom4();
    custom5();
    custom6();
    custom7();
    custom8();
    custom9();
    custom10();

    return 0;
}

char *reverse(char* a)
{
    char *to_string = malloc(sizeof(char));
    int count = 0;
    while (*a != '\0') {
        count++;
        a++;
    }
    int save = count;
    a -= count;
    while (count > 0) {
        *to_string = *(a + (count - 1));
        to_string++;
        count--;
    }
    *to_string = '\0';
    to_string -= save;
    return to_string;
}

char *my_itoa(long number, int base)
{
    char *string = malloc(100 * sizeof(char));
    int i = 0;
    _Bool is_positive = 1;

    if (number == 0) {
        string[i++] = '0';
        string[i] = '\0';
        return string;
    }

    if (number < 0 && base == 10) {
        is_positive = 0;
        number = -number;
    }

    while (number != 0) {
        int rem = number % base;
        string[i] = (rem > 9)? (rem - 10) + 'a' : rem + '0';
        i++;
        number /= base;
    }

    if (is_positive == 0)
        string[i++] = '-';
    string[i] = '\0';
    return reverse(string);
}
