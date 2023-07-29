#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
/**char str[] = "When you invoke GCC , it normally does preprocessing, compilation, assembly and linking. The \"overall options\" allow you to stop this process at an intermediate stage. For example, the -c option says not to run the linker. Then the output consists of object files output by the assembler.\n\nOther options are passed on to one stage of processing. Some options control the preprocessor and others the compiler itself. Yet other options control the assembler and linker; most of these are not documented here, since you rarely need to use any of them.\n\nMost of the command line options that you can use with GCC are useful for C programs; when an option is only useful with another language (usually C++), the explanation says so explicitly. If the description for a particular option does not mention a source language, you can use that option with all supported languages.\n\nThe gcc program accepts options and file names as operands. Many options have multi... [Diff had to be removed because it was too long]";*/
    _printf("Let's print a simple sentence.\n");
    _printf("%c", 'S');
    _printf("A char inside a sentence: %c. Did it work?\n", 'F');
    _printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
    _printf("%s", "This sentence is retrieved from va_args!\n");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
    _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
    _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    _printf("%%");
    _printf("Should print a single percent sign: %%\n");
    _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
    _printf("css%ccs%scscscs", 'T', "Test");
    /**_printf(str);
    _printf("man gcc:\n%s", str);*/
    _printf(NULL);
    _printf("%c", '\0');
    _printf("%!\n");
    _printf("%K\n");

    return (0);
}


