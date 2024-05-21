#include <stdio.h>
#include <string.h>
#include <windows.h>

//& "C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\gcc.exe" -std=c99

const char g_szClassName[] = "Calc";

HWND output, button1, button2, button3, button4, button5, button6, button7, button8, button9, button0, buttonMais, buttonMenos, buttonIgual, buttonDividir, buttonMultiplicar, buttonApagar;

char result[1000];
char result_copy[1000];
char last[100];

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg) {
        case WM_CREATE:
            break;
        case WM_COMMAND:
            switch (LOWORD(wParam)){
                case 1:
                    {
                        int index = strlen(result);
                        result[index] = '7';
                        result[index + 1] = '\0';
                        last[0] = '7';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 2:
                    {
                        int index = strlen(result);
                        result[index] = '8';
                        result[index + 1] = '\0';
                        last[0] = '8';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 3:
                    {
                        int index = strlen(result);
                        result[index] = '9';
                        result[index + 1] = '\0';
                        last[0] = '9';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 4:
                    {
                        int index = strlen(result);
                        result[index] = '4';
                        result[index + 1] = '\0';
                        last[0] = '4';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 5:
                    {
                        int index = strlen(result);
                        result[index] = '5';
                        result[index + 1] = '\0';
                        last[0] = '5';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 6:
                    {
                        int index = strlen(result);
                        result[index] = '6';
                        result[index + 1] = '\0';
                        last[0] = '6';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 7:
                    {
                        int index = strlen(result);
                        result[index] = '1';
                        result[index + 1] = '\0';
                        last[0] = '1';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 8:
                    {
                        int index = strlen(result);
                        result[index] = '2';
                        result[index + 1] = '\0';
                        last[0] = '2';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 9:
                    {
                        int index = strlen(result);
                        result[index] = '3';
                        result[index + 1] = '\0';
                        last[0] = '3';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 10:
                    if (strlen(result) - 1 == 0){
                        last[0] = 'n';
                        last[1] = '\0';
                        result[0] = '\0';
                        SetWindowText(output, result);

                        break;
                    }
                    if (result[strlen(result) - 1] == ' '){
                        result[strlen(result) - 3] = '\0';
                        SetWindowText(output, result);

                        int count = 0;

                        for (int i = strlen(result) - 1; i >= 0; i--){
                            if (result[i] == ' '){
                                break;
                            }
                            count++;
                        }

                        int i = 0;
                        while (count != 0){
                            last[i] = result[strlen(result) - count];

                            i++;
                            count--;
                        }

                        last[i] = '\0';

                        break;
                    } else {
                        result[strlen(result) - 1] = '\0';
                        SetWindowText(output, result);

                        if (result[strlen(result) - 1] == ' '){
                            last[0] = result[strlen(result) - 2];
                            last[1] = '\0';

                            break;
                        }
                        
                        int count = 0;

                        for (int i = strlen(result) - 1; i >= 0; i--){
                            if (result[i] == ' '){
                                break;
                            }
                            count++;
                        }

                        int i = 0;
                        while (count != 0){
                            last[i] = result[strlen(result) - count];

                            i++;
                            count--;
                        }

                        last[i] = '\0';

                        break;
                    }

                    break;
                case 11:
                    result[strlen(result)] = '0';
                    result[strlen(result)] = '\0';
                    last[0] = '0';
                    last[1] = '\0';
                    SetWindowText(output, result);
                    break;
                case 13:
                    {
                        if (last[0] == '/' || last[0] == '*' || last[0] == '-' || last[0] == '+' || last[0] == 'n'){
                            break;
                        }
                        int index = strlen(result);
                        result[index] = ' ';
                        result[index + 1] = '/';
                        result[index + 2] = ' ';
                        result[index + 3] = '\0';
                        last[0] = '/';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 14:
                    {
                        if (last[0] == '/' || last[0] == '*' || last[0] == '-' || last[0] == '+' || last[0] == 'n'){
                            break;
                        }
                        int index = strlen(result);
                        result[index] = ' ';
                        result[index + 1] = '*';
                        result[index + 2] = ' ';
                        result[index + 3] = '\0';
                        last[0] = '*';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 15:
                    {
                        if (last[0] == '/' || last[0] == '*' || last[0] == '-' || last[0] == '+' || last[0] == 'n'){
                            break;
                        }
                        int index = strlen(result);
                        result[index] = ' ';
                        result[index + 1] = '-';
                        result[index + 2] = ' ';
                        result[index + 3] = '\0';
                        last[0] = '-';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 16:
                    {
                        if (last[0] == '/' || last[0] == '*' || last[0] == '-' || last[0] == '+' || last[0] == 'n'){
                            break;
                        }
                        int index = strlen(result);
                        result[index] = ' ';
                        result[index + 1] = '+';
                        result[index + 2] = ' ';
                        result[index + 3] = '\0';
                        last[0] = '/';
                        last[1] = '\0';
                        SetWindowText(output, result);
                        break;
                    }
                case 12:
                    {
                        if (strlen(result) == 0){
                            break;
                        }

                        if (last[0] == '/' || last[0] == '*' || last[0] == '-' || last[0] == '+'){
                            break;
                        }

                        printf("------------------------------igual------------------------------\n");

                        strcpy(result_copy, result);

                        printf("result_copy: %s\n", result_copy);

                        int i = 0;
                        while (result_copy[i] != '\0'){
                            if (result_copy[i] == '*'){
                                int countMenos = 0;
                                for (int i2 = i - 2; i2 >= 0; i2--){
                                    if (result[i2] == ' '){
                                        break;
                                    }
                                    countMenos++;
                                }

                                int countMais = 0;
                                for (int i2 = i + 2; i2 < strlen(result_copy); i2++){
                                    if (result[i2] == ' '){
                                        break;
                                    } 
                                    countMais++;
                                }

                                printf("\n%d %d\n", countMenos, countMais);

                                char number1str[50];
                                char number2str[50];
                                int number_index = 0;

                                for (int i2 = i - 2 - countMenos + 1; i2 <= i - 2; i2++){
                                    number1str[number_index++] = result_copy[i2];
                                }

                                number1str[number_index] = '\0';

                                number_index = 0;
                                for (int i2 = i + 2; i2 < i + 2 + countMais; i2++){
                                    number2str[number_index++] = result_copy[i2];
                                }

                                number2str[number_index] = '\0';

                                printf("\n%s %s\n", number1str, number2str);

                                int result_multi = atoi(number1str) * atoi(number2str);

                                char number_result[50];

                                itoa(result_multi, number_result, 10);

                                printf("result_multi: %s\n", number_result);

                                int index = 0;
                                for (int i2 = i + 2 + countMais - 1; i2 >= i - 2 - countMenos + 1; i2--){
                                    printf("local %c\n", result_copy[i2]);
                                    if (number_result[strlen(number_result) - 1 - index] == '\0'){
                                        result_copy[i2] = '0';
                                        continue;
                                    }
                                    result_copy[i2] = number_result[strlen(number_result) - 1 - index];
                                    index++;
                                }

                                printf("final result: %s\n", result_copy);

                                strcpy(result, result_copy);

                                SetWindowText(output, result);
                            }
                            if (result_copy[i] == '/'){
                                int countMenos = 0;
                                for (int i2 = i - 2; i2 >= 0; i2--){
                                    if (result[i2] == ' '){
                                        break;
                                    }
                                    countMenos++;
                                }

                                int countMais = 0;
                                for (int i2 = i + 2; i2 < strlen(result_copy); i2++){
                                    if (result[i2] == ' '){
                                        break;
                                    } 
                                    countMais++;
                                }

                                printf("\n%d %d\n", countMenos, countMais);

                                char number1str[50];
                                char number2str[50];
                                int number_index = 0;

                                for (int i2 = i - 2 - countMenos + 1; i2 <= i - 2; i2++){
                                    number1str[number_index++] = result_copy[i2];
                                }

                                number1str[number_index] = '\0';

                                number_index = 0;
                                for (int i2 = i + 2; i2 < i + 2 + countMais; i2++){
                                    number2str[number_index++] = result_copy[i2];
                                }

                                number2str[number_index] = '\0';

                                printf("\n%s %s\n", number1str, number2str);

                                int result_multi = atoi(number1str) / atoi(number2str);

                                char number_result[50];

                                itoa(result_multi, number_result, 10);

                                printf("result_multi: %s\n", number_result);

                                int index = 0;
                                for (int i2 = i + 2 + countMais - 1; i2 >= i - 2 - countMenos + 1; i2--){
                                    printf("local %c\n", result_copy[i2]);
                                    if (number_result[strlen(number_result) - 1 - index] == '\0'){
                                        result_copy[i2] = '0';
                                        continue;
                                    }
                                    result_copy[i2] = number_result[strlen(number_result) - 1 - index];
                                    index++;
                                }

                                printf("final result: %s\n", result_copy);

                                strcpy(result, result_copy);

                                SetWindowText(output, result);
                            }

                            i++;
                        }

                        i = 0;
                        while (result_copy[i] != '\0'){
                            if (result_copy[i] == '+'){
                                int countMenos = 0;
                                for (int i2 = i - 2; i2 >= 0; i2--){
                                    if (result[i2] == ' '){
                                        break;
                                    }
                                    countMenos++;
                                }

                                int countMais = 0;
                                for (int i2 = i + 2; i2 < strlen(result_copy); i2++){
                                    if (result[i2] == ' '){
                                        break;
                                    } 
                                    countMais++;
                                }

                                printf("\n%d %d\n", countMenos, countMais);

                                char number1str[50];
                                char number2str[50];
                                int number_index = 0;

                                for (int i2 = i - 2 - countMenos + 1; i2 <= i - 2; i2++){
                                    number1str[number_index++] = result_copy[i2];
                                }

                                number1str[number_index] = '\0';

                                number_index = 0;
                                for (int i2 = i + 2; i2 < i + 2 + countMais; i2++){
                                    number2str[number_index++] = result_copy[i2];
                                }

                                number2str[number_index] = '\0';

                                printf("\n%s %s\n", number1str, number2str);

                                int result_multi = atoi(number1str) + atoi(number2str);

                                char number_result[50];

                                itoa(result_multi, number_result, 10);

                                printf("result_multi: %s\n", number_result);

                                int index = 0;
                                for (int i2 = i + 2 + countMais - 1; i2 >= i - 2 - countMenos + 1; i2--){
                                    printf("local %c\n", result_copy[i2]);
                                    if (number_result[strlen(number_result) - 1 - index] == '\0'){
                                        result_copy[i2] = '0';
                                        continue;
                                    }
                                    result_copy[i2] = number_result[strlen(number_result) - 1 - index];
                                    index++;
                                }

                                printf("final result: %s\n", result_copy);

                                strcpy(result, result_copy);

                                SetWindowText(output, result);
                            }
                            if (result_copy[i] == '-'){
                                int countMenos = 0;
                                for (int i2 = i - 2; i2 >= 0; i2--){
                                    if (result[i2] == ' '){
                                        break;
                                    }
                                    countMenos++;
                                }

                                int countMais = 0;
                                for (int i2 = i + 2; i2 < strlen(result_copy); i2++){
                                    if (result[i2] == ' '){
                                        break;
                                    } 
                                    countMais++;
                                }

                                printf("\n%d %d\n", countMenos, countMais);

                                char number1str[50];
                                char number2str[50];
                                int number_index = 0;

                                for (int i2 = i - 2 - countMenos + 1; i2 <= i - 2; i2++){
                                    number1str[number_index++] = result_copy[i2];
                                }

                                number1str[number_index] = '\0';

                                number_index = 0;
                                for (int i2 = i + 2; i2 < i + 2 + countMais; i2++){
                                    number2str[number_index++] = result_copy[i2];
                                }

                                number2str[number_index] = '\0';

                                printf("\n%s %s\n", number1str, number2str);

                                int result_multi = atoi(number1str) - atoi(number2str);

                                char number_result[50];

                                itoa(result_multi, number_result, 10);

                                printf("result_multi: %s\n", number_result);

                                int index = 0;
                                for (int i2 = i + 2 + countMais - 1; i2 >= i - 2 - countMenos + 1; i2--){
                                    printf("local %c\n", result_copy[i2]);
                                    if (number_result[strlen(number_result) - 1 - index] == '\0'){
                                        result_copy[i2] = '0';
                                        continue;
                                    }
                                    result_copy[i2] = number_result[strlen(number_result) - 1 - index];
                                    index++;
                                }

                                printf("final result: %s\n", result_copy);

                                strcpy(result, result_copy);

                                SetWindowText(output, result);
                            }

                            i++;
                        }

                        printf("------------------------------igual------------------------------\n");

                        break;
                    }
                default:
                    break;
            }

            printf("last: %s\n", last);
            printf("result: %s\n", result);
            printf("result length: %d\n", strlen(result));

            break;
        case WM_DESTROY:
            PostQuitMessage(0);
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style          = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)){
        printf("window registration failed");
        return 0;
    }

    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Calculadora",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 390, 500,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL){
        printf("window creation failed");
        return 0;
    }

    last[0] = 'n';

    output = CreateWindow(
        "STATIC",
        "",
        WS_CHILD | WS_BORDER | WS_VISIBLE | SS_RIGHT,
        10, 10, 350, 30,
        hwnd, (HMENU) 0, NULL, NULL
    );

    button7 = CreateWindow(
        "BUTTON",
        "7",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 50, 80, 80,
        hwnd, (HMENU) 1, NULL, NULL
    );

    button8 = CreateWindow(
        "BUTTON",
        "8",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        100, 50, 80, 80,
        hwnd, (HMENU) 2, NULL, NULL
    );

    button9 = CreateWindow(
        "BUTTON",
        "9",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        190, 50, 80, 80,
        hwnd, (HMENU) 3, NULL, NULL
    );

    buttonDividir = CreateWindow(
        "BUTTON",
        "/",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        280, 50, 80, 80,
        hwnd, (HMENU) 13, NULL, NULL
    );

    button4 = CreateWindow(
        "BUTTON",
        "4",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 140, 80, 80,
        hwnd, (HMENU) 4, NULL, NULL
    );

    button5 = CreateWindow(
        "BUTTON",
        "5",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        100, 140, 80, 80,
        hwnd, (HMENU) 5, NULL, NULL
    );

    button6 = CreateWindow(
        "BUTTON",
        "6",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        190, 140, 80, 80,
        hwnd, (HMENU) 6, NULL, NULL
    );

    buttonMultiplicar = CreateWindow(
        "BUTTON",
        "*",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        280, 140, 80, 80,
        hwnd, (HMENU) 14, NULL, NULL
    );

    button1 = CreateWindow(
        "BUTTON",
        "1",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 230, 80, 80,
        hwnd, (HMENU) 7, NULL, NULL
    );

    button2 = CreateWindow(
        "BUTTON",
        "2",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        100, 230, 80, 80,
        hwnd, (HMENU) 8, NULL, NULL
    );

    button3 = CreateWindow(
        "BUTTON",
        "3",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        190, 230, 80, 80,
        hwnd, (HMENU) 9, NULL, NULL
    );

    buttonMenos = CreateWindow(
        "BUTTON",
        "-",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        280, 230, 80, 80,
        hwnd, (HMENU) 15, NULL, NULL
    );

    buttonApagar = CreateWindow(
        "BUTTON",
        "<-",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        10, 320, 80, 80,
        hwnd, (HMENU) 10, NULL, NULL
    );

    button0 = CreateWindow(
        "BUTTON",
        "0",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        100, 320, 80, 80,
        hwnd, (HMENU) 11, NULL, NULL
    );

    buttonIgual = CreateWindow(
        "BUTTON",
        "=",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        190, 320, 80, 80,
        hwnd, (HMENU) 12, NULL, NULL
    );

    buttonMais = CreateWindow(
        "BUTTON",
        "+",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        280, 320, 80, 80,
        hwnd, (HMENU) 16, NULL, NULL
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0) > 0){
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}