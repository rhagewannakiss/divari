#include "post_notation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "point_4_2.h"
#include "char_stack.h"
#include "calculating_value.h"

void post_notation(int N) {
    FILE* input_file =  fopen(k_source_filename, "r");
    FILE* output_file = fopen(k_output_filename, "w");

    assert(input_file != NULL);
    assert(output_file != NULL);

    char** array_of_strings = (char**)calloc(N, sizeof(char *));
    if (array_of_strings == NULL) {
        fprintf(stderr, "Memory allocation failed in post_notation func.");

        fclose(input_file);
        fclose(output_file);

        abort();
    }

    for (int i = 0; i < N; i++) {
        array_of_strings[i] = (char*)calloc(k_max_string_length, sizeof(char));
        if (array_of_strings[i] == NULL) {
            fprintf("Memory allocation failed in post_notation func (array_of_strings)");
            for (int j = 0; j < i; j++) {
                free(array_of_strings[j]);
            }
            free(array_of_strings);

            fclose(input_file);
            fclose(output_file);

            abort();
        }

        if (fgets(array_of_strings[i], k_max_string_length, input_file) == NULL) {
            fprintf("Error reading form file: %s", k_source_filename);
            for (int j = 0; j <= i; j++) {
                free(array_of_strings[j]);
            }
            free(array_of_strings);

            fclose(input_file);
            fclose(output_file);

            abort();
        }
        array_of_strings[i][strcspn(array_of_strings[i], "\n")] = 0;
    }

    for (int i = 0; i < N; i++) {
        char* postfix = post_conversion(array_of_strings[i]);
        fprintf(output_file, "%s\n", postfix);
        free(postfix);
    }

    for (int i = 0; i < N; i++) {
        free(array_of_strings[i]);
    }
    free(array_of_strings);

    fclose(input_file);
    fclose(output_file);

    return;
}

//-----------------------------------------------
//
//static int get_priority(char op) {
//    switch(op) {
//        case '+':
//        case '-': return 1;
//        case '*':
//        case '/': return 2;
//        case '^': return 3;
//        default:  return 0;
//    }
//}
//
//char* post_conversion(const char* infix) {
//    struct Node* stack = NULL;
//    char* postfix = (char*)calloc(k_max_string_length, sizeof(char));
//    int j = 0;
//    char temp;
//
//    for (int i = 0; infix[i]; i++) {
//        if (isdigit(infix[i])) {
//            while (isdigit(infix[i])) {
//                postfix[j++] = infix[i++];
//            }
//            postfix[j++] = ' ';
//            i--;
//        } else if (infix[i] == '(') {
//            stack = push(stack, infix[i]);
//        } else if (infix[i] == ')') {
//            while (!isempty(stack) && stack->elem != '(') {
//                stack = pop(stack, &temp);
//                postfix[j++] = temp;
//                postfix[j++] = ' ';
//            }
//            if (!isempty(stack)) stack = pop(stack, &temp);
//        } else {
//            while (!isempty(stack) &&
//                   get_priority(infix[i]) <= get_priority(stack->elem)) {
//                stack = pop(stack, &temp);
//                postfix[j++] = temp;
//                postfix[j++] = ' ';
//            }
//            stack = push(stack, infix[i]);
//        }
//    }
//
//    while (!isempty(stack)) {
//        stack = pop(stack, &temp);
//        postfix[j++] = temp;
//        postfix[j++] = ' ';
//    }
//
//    postfix[j] = '\0';
//    return postfix;
//}

//  обратная польская запись:

/*void print(node_t* node) {
    if (node == NULL) { return; }

    //fprintf(k_output_filename, "( ");
    if (node->left) { print(node->left); }
    if (node->right) { print(node->right); }
    fprintf(k_output_filename, " %d ", node->value);
    //fprintf(k_output_filename, " )");
} */

