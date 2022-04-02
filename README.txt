echo "# printf" >> README.md
git init
git add README.md
git commit -m "first commit"
git branch -M main
git remote add origin git@github.com:Ktexaswalker/printf.git
git push -u origin main

git remote add origin git@github.com:Ktexaswalker/printf.git
git branch -M main
git push -u origin main

_______________________________________________________________________________

PRINTF(1)                 BSD General Commands Manual                PRINTF(1)

NAME
     printf -- formatted output

SYNOPSIS
     printf format [arguments ...]

DESCRIPTION
     The printf utility formats and prints its arguments, after the first,
     under control of the format.  The format is a character string which con-
     tains three types of objects: plain characters, which are simply copied
     to standard output, character escape sequences which are converted and
     copied to the standard output, and format specifications, each of which
     causes printing of the next successive argument.

     The arguments after the first are treated as strings if the corresponding
     format is either c, b or s; otherwise it is evaluated as a C constant,
     with the following extensions:

           o   A leading plus or minus sign is allowed.
           o   If the leading character is a single or double quote, the value
               is the character code of the next character.

     The format string is reused as often as necessary to satisfy the
     arguments.  Any extra format specifications are evaluated with zero or
     the null string.

     Character escape sequences are in backslash notation as defined in the
     ANSI X3.159-1989 (``ANSI C89''), with extensions.  The characters and
     their meanings are as follows:

           \a      Write a <bell> character.
           \b      Write a <backspace> character.
           \c      Ignore remaining characters in this string.
           \f      Write a <form-feed> character.
           \n      Write a <new-line> character.
           \r      Write a <carriage return> character.
           \t      Write a <tab> character.
           \v      Write a <vertical tab> character.
           \'      Write a <single quote> character.
           \\      Write a backslash character.
           \num    Write a byte whose value is the 1-, 2-, or 3-digit octal
                   number num.  Multibyte characters can be constructed using
                   multiple \num sequences.

     Each format specification is introduced by the percent character (``%'').
     The remainder of the format specification includes, in the following
     order:

     Zero or more of the following flags:

             #       A `#' character specifying that the value should be
                     printed in an ``alternate form''.  For b, c, d, s and u
                     formats, this option has no effect.  For the o formats
                     the precision of the number is increased to force the
                     first character of the output string to a zero.  For the
                     x (X) format, a non-zero result has the string 0x (0X)
                     prepended to it.  For a, A, e, E, f, F, g and G formats,
                     the result will always contain a decimal point, even if
                     no digits follow the point (normally, a decimal point
                     only appears in the results of those formats if a digit
                     follows the decimal point).  For g and G formats, trail-
                     ing zeros are not removed from the result as they would
                     otherwise be;

             -       A minus sign `-' which specifies left adjustment of the
                     output in the indicated field;

             +       A `+' character specifying that there should always be a
                     sign placed before the number when using signed formats.

             ` '     A space specifying that a blank should be left before a
                     positive number for a signed format.  A `+' overrides a
                     space if both are used;

             0       A zero `0' character indicating that zero-padding should
                     be used rather than blank-padding.  A `-' overrides a `0'
                     if both are used;

     Field Width:
             An optional digit string specifying a field width; if the output
             string has fewer bytes than the field width it will be blank-
             padded on the left (or right, if the left-adjustment indicator
             has been given) to make up the field width (note that a leading
             zero is a flag, but an embedded zero is part of a field width);

     Precision:
             An optional period, `.', followed by an optional digit string
             giving a precision which specifies the number of digits to appear
             after the decimal point, for e and f formats, or the maximum num-
             ber of bytes to be printed from a string; if the digit string is
             missing, the precision is treated as zero;

     Format:
             A character which indicates the type of format to use (one of
             diouxXfFeEgGaAcsb).  The uppercase formats differ from their low-
             ercase counterparts only in that the output of the former is
             entirely in uppercase.  The floating-point format specifiers
             (fFeEgGaA) may be prefixed by an L to request that additional
             precision be used, if available.

     A field width or precision may be `*' instead of a digit string.  In this
     case an argument supplies the field width or precision.

     The format characters and their meanings are:

     diouXx      The argument is printed as a signed decimal (d or i),
                 unsigned octal, unsigned decimal, or unsigned hexadecimal (X
                 or x), respectively.

     fF          The argument is printed in the style `[-]ddd.ddd' where the
                 number of d's after the decimal point is equal to the preci-
                 sion specification for the argument.  If the precision is
                 missing, 6 digits are given; if the precision is explicitly
                 0, no digits and no decimal point are printed.  The values
                 infinity and NaN are printed as `inf' and `nan', respec-
                 tively.

     eE          The argument is printed in the style e `[-d.ddd+-dd]' where
                 there is one digit before the decimal point and the number
                 after is equal to the precision specification for the argu-
                 ment; when the precision is missing, 6 digits are produced.
                 The values infinity and NaN are printed as `inf' and `nan',
                 respectively.

     gG          The argument is printed in style f (F) or in style e (E)
                 whichever gives full precision in minimum space.

     aA          The argument is printed in style `[-h.hhh+-pd]' where there
                 is one digit before the hexadecimal point and the number
                 after is equal to the precision specification for the argu-
                 ment; when the precision is missing, enough digits are pro-
                 duced to convey the argument's exact double-precision float-
                 ing-point representation.  The values infinity and NaN are
                 printed as `inf' and `nan', respectively.

     c           The first byte of argument is printed.

     s           Bytes from the string argument are printed until the end is
                 reached or until the number of bytes indicated by the preci-
                 sion specification is reached; however if the precision is 0
                 or missing, the string is printed entirely.

     b           As for s, but interpret character escapes in backslash nota-
                 tion in the string argument.  The permitted escape sequences
                 are slightly different in that octal escapes are \0num
                 instead of \num.

     n$          Allows reordering of the output according to argument.

     %           Print a `%'; no argument is used.

     The decimal point character is defined in the program's locale (category
     LC_NUMERIC).

     In no case does a non-existent or small field width cause truncation of a
     field; padding takes place only if the specified field width exceeds the
     actual width.

     Some shells may provide a builtin printf command which is similar or
     identical to this utility.  Consult the builtin(1) manual page.

EXIT STATUS
     The printf utility exits 0 on success, and >0 if an error occurs.

COMPATIBILITY
     The traditional BSD behavior of converting arguments of numeric formats
     not beginning with a digit to the ASCII code of the first character is
     not supported.

SEE ALSO
     builtin(1), echo(1), sh(1), printf(3)

STANDARDS
     The printf command is expected to be compatible with the IEEE Std 1003.2
     (``POSIX.2'') specification.

HISTORY
     The printf command appeared in 4.3BSD-Reno.  It is modeled after the
     standard library function, printf(3).

CAVEATS
     ANSI hexadecimal character constants were deliberately not provided.

     Trying to print a dash ("-") as the first character causes printf to
     interpret the dash as a program argument.  -- must be used before format.

     If the locale contains multibyte characters (such as UTF-8), the c format
     and b and s formats with a precision may not operate as expected.

BUGS
     Since the floating point numbers are translated from ASCII to floating-
     point and then back again, floating-point precision may be lost.  (By
     default, the number is translated to an IEEE-754 double-precision value
     before being printed.  The L modifier may produce additional precision,
     depending on the hardware platform.)

     The escape sequence \000 is the string terminator.  When present in the
     argument for the b format, the argument will be truncated at the \000
     character.

     Multibyte characters are not recognized in format strings (this is only a
     problem if `%' can appear inside a multibyte character).

BSD                             April 21, 2014                             BSD
_______________________________________________________________________________

STDARG(3)                BSD Library Functions Manual                STDARG(3)

NAME
     stdarg -- variable argument lists

SYNOPSIS
     #include <stdarg.h>

     void
     va_start(va_list ap, last);

     type
     va_arg(va_list ap, type);

     void
     va_copy(va_list dest, va_list src);

     void
     va_end(va_list ap);

DESCRIPTION
     A function may be called with a varying number of arguments of varying
     types.  The include file <stdarg.h> declares a type (va_list) and defines
     three macros for stepping through a list of arguments whose number and
     types are not known to the called function.

     The called function must declare an object of type va_list which is used
     by the macros va_start(), va_arg(), va_copy(), and va_end().

     The va_start() macro must be called first, and it initializes ap, which
     can be passed to va_arg() for each argument to be processed.  Calling
     va_end() signals that there are no further arguments, and causes ap to be
     invalidated.  Note that each call to va_start() must be matched by a call
     to va_end(), from within the same function.

     The parameter last is the name of the last parameter before the variable
     argument list, i.e., the last parameter of which the calling function
     knows the type.

     Because the address of this parameter is used in the va_start() macro, it
     should not be declared as a register variable, or as a function or an
     array type.

     The va_arg() macro expands to an expression that has the type and value
     of the next argument in the call.  The parameter ap is the va_list ap
     initialized by va_start().  Each call to va_arg() modifies ap so that the
     next call returns the next argument.  The parameter type is a type name
     specified so that the type of a pointer to an object that has the speci-
     fied type can be obtained simply by adding a * to type.

     If there is no next argument, or if type is not compatible with the type
     of the actual next argument (as promoted according to the default argu-
     ment promotions), random errors will occur.

     The first use of the va_arg() macro after that of the va_start() macro
     returns the argument after last.  Successive invocations return the val-
     ues of the remaining arguments.

     The va_copy() macro copies the state of the variable argument list, src,
     previously initialized by va_start(), to the variable argument list,
     dest, which must not have been previously initialized by va_start(),
     without an intervening call to va_end().  The state preserved in dest is
     equivalent to calling va_start() and va_arg() on dest in the same way as
     was used on src.  The copied variable argument list can subsequently be
     passed to va_arg(), and must finally be passed to va_end() when through
     with it.

     After a variable argument list is invalidated by va_end(), it can be
     reinitialized with va_start() or made a copy of another variable argument
     list with va_copy().

EXAMPLES
     The function foo takes a string of format characters and prints out the
     argument associated with each format character based on the type.

           void foo(char *fmt, ...)
           {
                   va_list ap, ap2;
                   int d;
                   char c, *s;

                   va_start(ap, fmt);
                   va_copy(ap2, ap);
                   while (*fmt)
                           switch(*fmt++) {
                           case 's':                       /* string */
                                   s = va_arg(ap, char *);
                                   printf("string %s\n", s);
                                   break;
                           case 'd':                       /* int */
                                   d = va_arg(ap, int);
                                   printf("int %d\n", d);
                                   break;
                           case 'c':                       /* char */
                                   /* Note: char is promoted to int. */
                                   c = va_arg(ap, int);
                                   printf("char %c\n", c);
                                   break;
                           }
                   va_end(ap);
                   ...
                   /* use ap2 to iterate over the arguments again */
                   ...
                   va_end(ap2);
           }

COMPATIBILITY
     These macros are not compatible with the historic macros they replace.  A
     backward compatible version can be found in the include file <varargs.h>.

STANDARDS
     The va_start(), va_arg(), va_copy(), and va_end() macros conform to
     ISO/IEC 9899:1999 (``ISO C99'').

BUGS
     Unlike the varargs macros, the stdarg macros do not permit programmers to
     code a function with no fixed arguments.  This problem generates work
     mainly when converting varargs code to stdarg code, but it also creates
     difficulties for variadic functions that wish to pass all of their argu-
     ments on to a function that takes a va_list argument, such as
     vfprintf(3).

BSD                            October 25, 2002                            BSD

_______________________________________________________________________________
