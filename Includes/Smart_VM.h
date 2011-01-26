/*
 * nimh-doc
 * = %(Java Kitty-Includes)path/Smart_VM.h
 * %% Author: %(KatrinaTheLamia)user
 * %% Project: %(Java Kitty)project %(Jerl 6)project %(Munchhausen3)project
 * 		%(JUMPS)project %(Lamia Browser)project 
 * 		%(Echidna System)project %(Munchhasuen2)project 
 * 		%(P-DA ZX)project %(PET Project)project %(MOLARP)project
 * %% License: Artistic %(Java Kitty-Documentation)path/LICENSE.TXT
 * %% Group: %(NIMH Labs)group
 * %% Creation: 3177-1-26
 *
 * == Revisions
 * + 3177-1-26 Started work on this file
 *
 * == TODO
 * ! complete file
 * ! debug
 * ! optimise
 * ! documentation
 *
 */

#ifndef __Java_Kitty_Smart_VM_h__
#define __Java_Kitty_Smart_VM_h__

make_this_c(

typedef signed char jk_byte;
typedef unsigned char jk_char;
typedef signed short jk_short;
typedef signed int jk_int;
typedef signed long long jk_long;

typedef signed float jk_float;
typedef signed double jk_double;

enum jk_boolean { jk_false = 0, jk_true = 1  };

typedef unsigned long long jk_opcode;
typedef jk_opcode* returnAddress;

typedef const jk_byte jk_null = "\0";
typedef const jk_byte jk_zero = 0;

typedef struct {
	nimh_width *__self;
	JK_Smart_Class *class_feed;
} jk_methodical_dat jk_methodical;

typedef struct {
	nimh_widget *__self;
	jk_boolean is_thread;
	nimh_widget *process_accounting;
	jk_int instruction_number, pc;
	nimh_widget *stack;
	JK_Smart_Class

} jk_process_dat jk_process;

/* Errors to handle here:
 * StackOverflowError
 * OutOfMemoryError
 */


);

#endif /* End Smart_VM.h */
